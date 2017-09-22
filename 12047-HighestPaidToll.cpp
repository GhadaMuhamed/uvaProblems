#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,long long>
vector <ii> graph[10005];
vector <ii> reversed[10005];
long long sp_from_t[10005];
long long sp_from_s[10004];
int n,m,s,t,p;
void D()
{
	memset(sp_from_s,-1,sizeof(sp_from_s));
	memset(sp_from_t,-1,sizeof(sp_from_t));
	priority_queue <ii,vector<ii>,greater<ii> > q;
	q.push(ii(0,s));
	while (!q.empty())
	{
		long long w=q.top().first; int cur=q.top().second;
		q.pop();
		if (sp_from_s[cur]!=-1) continue;
		sp_from_s[cur]=w;
		for (int i=0;i<int(graph[cur].size());i++)
		{
	        	q.push(ii(w+graph[cur][i].second,graph[cur][i].first));
		}
	}
q.push(ii(0,t));
while (!q.empty())
	{
	long long w=q.top().first; int cur=q.top().second;
		q.pop();
		if (sp_from_t[cur]!=-1) continue;
		sp_from_t[cur]=w;
		for (int i=0;i<int(reversed[cur].size());i++)
		{
			q.push(ii(w+reversed[cur][i].second,reversed[cur][i].first));
		}
	}
}
int main()
{
	int C;
	cin>>C;
	while (C--)
	{
		scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
		for (int i=0;i<m;i++)
		{
			int x,y; long long z;
			scanf("%d %d %lld",&x, &y, &z);
			graph[x].push_back(ii(y,z));
			reversed[y].push_back(ii(x,z));
		}
		D();
		long long mx=-1;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<int(graph[i].size());j++)
			{
				int child=graph[i][j].first;
				long long cost=graph[i][j].second;
				if (sp_from_s[i]+sp_from_t[child]+cost<=p && sp_from_s[i]!=-1 && sp_from_t[child]!=-1)
				{
					mx=max(mx,cost);
				}
			}
		}
		printf("%lld\n",mx);
		for (int i=1;i<=n;i++)
			{
			graph[i].clear();
		    reversed[i].clear();
			}
	}
}
