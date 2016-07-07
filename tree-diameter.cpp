/*---------------------------Dynamic Programming------------------------------
Diameter of tree
for each node of the tree we will find the height of each child then if the diameter passes through
a node then it will be the sum of the height of the two child which have maximum height
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
std::vector<int> adj[100];
int diameter;//diameter of the tree
int height[101];
void def(int V,int pV)
{
	std::vector<int> child;//used to get height of all the children's
for(auto v:adj[V])//dfs for child of V
{
	if(v==pV)//if v is its parent then ignore it
		continue;
	dfs(v,V);
child.push_back(height[v]);//pushing the height of each child of V
}
height[V]=1;//intialising height of node V
if(adj[V].size()!=0)
height[V]=1+*max_element(child.begin(), child.end());//height of current node will be the maximum height of child
if(adj[V].size()>=2)
{
//utility func for finding two maximum element in child vector
	int mx1,mx2;
	int mx1=child[0],mx2=child[1];
	if(mx1<mx2)
		swap(mx1,mx2);
	for(int i=2;i<child.size();i++)
	{
		if(child[i]<mx2)
			continue;
		if(child[i]>=mx1)
		{
			mx2=mx1;
			mx1=val[i];
		}
		else 
		{
			mx2=val[i];
		}
	}
diameter=max(1+mx1+mx2,diameter);
}

}
int main()
{
	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout<<diameter<<endl;
	return 0;
}
