/*--------------------------------_Shortest path(Single source)------------------------------------------------
implemenation of single source shortest path using Dijisktra algo
*/
#include<pthread.h>
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define INF 100000000
queue<int> q;
int dis[3*1001];// used to assign distance from the source
int main()
{
	int t;
	cin>>t;//number of test case
	while(t--)
	{
		std::vector<pair<int,int> > adj[3*1001];//adjancy list
		set <pair<int,int> > ss;//used to get node having the minimum distance from the source
	
		int n,m,x,y,t;
		cin>>n>>m;//number of nodes and edges respectivly.
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>t;//x and y denotes edges and t denotes the  cost of the path from x to y
			adj[x].push_back(make_pair(y,t));
			adj[y].push_back(make_pair(x,t));
		}
		int s;
		set<pair<int,int> >::iterator  itr;
		pair<int,int> u;
		cin>>s;//get the source from the user
		ss.insert(make_pair(0,s));
		//make distance of all the node INF from the source  
		for(int i=1;i<=n;i++)
		{
			dis[i]=INF;
			if(i==s)
				ss.insert(make_pair(0,s));
			else
			ss.insert(make_pair(INF,i));
		}
		dis[s]=0;

		while(!ss.empty())
		{	
			 itr=ss.begin();//get the node with minimum distance
			u=(*itr);
			ss.erase(itr);
			int dd=u.first,cur=u.second;
			for(auto v :adj[cur])
			{
				//relaxing the edges
				if(dis[v.first]>(dd+v.second))
				{
						pair<int,int> temp;
						temp=make_pair(dis[v.first],v.first);		
					itr=ss.find(temp);
					ss.erase(itr);
					
					dis[v.first]=dd+v.second;
					
					ss.insert(make_pair(dis[v.first],v.first));
				}
			}

		}
		for(int i=1;i<=n;i++)
		{
			if(i==s)
				continue;
			if(dis[i]==INF)
				cout<<"-1"<<" ";
			else
				cout<<dis[i]<<" ";
		}
		cout<<endl;



}
	return 0;
}
