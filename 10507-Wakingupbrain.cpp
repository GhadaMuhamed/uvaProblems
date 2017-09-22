#include <bits/stdc++.h>
using namespace std;

int main()
{
	  int n,m;

	  while (scanf(" %d %d ", &n, &m)!=EOF)
	  {
		  map<char,int> mp;
		  vector <char> arr[30];
		  set<char>st;
		  string s;
		  cin>>s;
		  for (int i=0;i<(int)s.size();i++)
		  {  mp[s[i]]=1; st.insert(s[i]);}
		  for (int i=0;i<m;i++)
		  {
			  char a,b;
			  cin>>a>>b;
			  arr[a-'A'].push_back(b);
			  arr[b-'A'].push_back(a);
			st.insert(a);
			st.insert(b);
		  }
		  long long ans=0;
		  bool exit=true;
		  while (exit)
		  {
			  vector <char> vec1;
			  for (set <char> :: iterator it=st.begin();it!=st.end();it++)
			  {
				  if (mp[*it]) continue;
				  int cnt=0;
				  int cur=(*it)-'A';
				for (int j=0;j<arr[cur].size();j++)
				{
                     cnt+=mp[arr[cur][j]];
				}
				if (cnt>=3) vec1.push_back(*it);
			  }
			  if (vec1.size())
			  {
				  for (int i=0;i<vec1.size();i++)
					  mp[vec1[i]]=1;
			  }
			  else exit=false;
			  ans++;
		  }
		  int koko=0;
		  for (map <char,int> :: iterator it=mp.begin();it!=mp.end();it++)
			  if (it->second) {koko++;}

		  if (koko<n)
			  cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
		  else cout<<"WAKE UP IN, "<<ans-1<<", YEARS"<<endl;
	  }
}
