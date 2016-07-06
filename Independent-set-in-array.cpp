/*-----------------------------------Dynamic Programming*************** Independent set in array----------------------------------------------------------------
Given some array of coins.but sum of maximum coins such that no two arew adjacent to each other
*/
#include<iostream>
using namespace std;
int val[101];
int dp[101];
int main()
{
	int n;
	cout<<"Enter Number of coins: "
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	dp[0]=0;//base caseip no coins then sum is zero
	dp[1]=val[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(val[i]+dp[i-2],dp[i-1]);//either choose this element in set or not
	}
cout<<dp[n]<<endl;
	return 0;
}
