#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,int>
long long oo = 1e9;
long long dijkstra(int start, vector< ii> arr[],int end)
{
	vector <long long > sp(110,oo);
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push( {0,start});
	while (!q.empty())
	{
		long long w=q.top().first; int cur=q.top().second;
		q.pop();
		if (sp[cur]!=oo) continue;
		sp[cur]=w;
		if (cur==end) return sp[cur];
		for (int i=0;i<int(arr[cur].size());i++)
		{
			int child=arr[cur][i].first;
			int cost=arr[cur][i].second;
			q.push( {w+cost,child});
		}
	}
	return oo;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<ii> arr[110];
		int n,e,ti,m;
		cin>>n>>e>>ti>>m;
		for (int i=0;i<m;i++)
		{
			int a,b,w;
			cin>>a>>b>>w;
			arr[a].push_back( {b,w});
		}
		long long ans=0;
		vector <long long> vec(110);
		for (int i=1;i<=n;i++)
		vec[i]=dijkstra(i,arr,e);
		for (int i=1;i<=n;i++)
		if (vec[i]<=ti) ans++;
		cout<<ans<<endl;
		if (t) cout<<endl;

	}
}
