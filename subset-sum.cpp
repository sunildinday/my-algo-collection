/*
SUBSET-SUM:numbre of different sum having  given sum and also print all pof them
Time Complexity:O(n*(value of given sum))
Space Complexity:O(n*(value of given sum))
Only suitable when given sum  is less
*/
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n;
int sum;//sum to be find inside the array
int val[100];
int ns=0;

std::vector< vector< pair<bool,int> > > dp(101,vector<pair<bool,int> >(35,mp(false,0) ) );

int main()
{
	
	cin>>n;//number of element in the array
	for(int i=1;i<=n;i++)
		cin>>val[i];
	int q;//number of query to be made
	cin>>q;
	for(int i=0;i<=n;i++)
		dp[0][i]=mp(true,0);
	while(q--)
	{
		cin>>sum;
		ns=0;
		for(int i=1;i<=sum;i++)
		dp[i][0]=mp(false,0);
		for(int i=1;i<sum;i++)
		{
			for(int j=1;j<=n;j++)
			{
					if(val[j]<=i)
				{
					if(dp[i-val[j]][j-1].first)
						dp[i][j]=mp(true,j);
					else
						dp[i][j]=dp[i][j-1];
				}
				else
					dp[i][j]=dp[i][j-1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(val[i]<=sum)
			if(dp[sum-val[i]][i-1].first)
				{
					ns++;
					cout<<i<<" ";
					int temp=dp[sum-val[i]][i-1].second;
					int sm=sum-val[i];
					while(sm)
					{
						cout<<temp<<" ";
						int tt=sm;
						
						sm=sm-val[temp];
						temp=dp[tt-val[temp]][temp-1].second;

					}
	cout<<endl;
		}			
		}
		cout<<"Total number of subset having sum "<<sum<<" is "<<endl;
		cout<<ns<<endl;
		
}
	return 0;
}
