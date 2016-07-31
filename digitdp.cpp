 /*--------------------Digit Dp using dynamic programing--------------
 here we are taking number from front ,for example 324 .then put this into a array{3,2,4}.now for the first place we can only insert number
 upto 3 and if number is smaller then 3 then for the next index we can insert any number from 0 to 9,because the number will be always smaller
 then the 324.
 Problem Link:https://www.hackerearth.com/problem/algorithm/samu-and-special-coprime-numbers/description/
 */

                #include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define  Help_me  ios_base::sync_with_stdio(false);
#define  lg(x)  ceil(log2(x))
#define CIN(n) scanf("%d",&n)
#define CINF(n) scanf("%f",&n)
#define COUT(n) printf("%d\n",n)
#define FOR(i,j,n) for(i=j;i<=n;i++)
#define FORR(i,j,n) for(i=j;i>=n;i--)
#define PI 22.0/7.0
#define MX 10000000
#define mod 1000000007
const int inf=100000005;
   ull mulmod(ull a,ull b)  {ull x=0,y=a%mod;while(b){
   		if(b%2==1){x=(x+y)%mod;}
   		y=(2*y)%mod;b=b/2;}return x%mod;}
   ull power(ull a,ull b){ull x=1,y=a%mod;while(b){if(b%2==1){x=mulmod(x,y)%mod;}y=mulmod(y,y)%mod;b=b/2;}return x%mod;}
bool cmp(int x,int y)
{
	return x>y?1:0;
}
ull dp[20][200][1500];
std::vector<int> digit;
ull digitdp(int idx,int tight,int sum, int sqrsum)
{
	if(idx==-1)
		return __gcd(sum,sqrsum)==1;
	if(!tight&&dp[idx][sum][sqrsum]!=-1)
		return dp[idx][sum][sqrsum];
	int lastdigit;
	if(tight)
		lastdigit=digit[idx];
	else
		lastdigit=9;
	ull ans=0;
	for(int d=0;d<=lastdigit;d++)
	{
		ans+=digitdp(idx-1,tight&&lastdigit==d,sum+d,sqrsum+d*d);
	}
	//for tight=1 we are not saving  it in dp table because if we do.then for every number which have same number of digits
	// will have same answer.because when we call dpdigit(digit.size()-1,1,0,0)  (because dp[idx=len-1][tight=1][sum=0][sqrsum=0]!=-1) function in main function .then it will give same answer
	// for every number having same number of digits
	if(!tight)
	dp[idx][sum][sqrsum]=ans;
	return ans; 
}
ull solve(ull num)
{ 
if(num==0)
	return 0;
if(!digit.empty())
digit.clear();

while(num)
{
digit.push_back(num%10);
num/=10;
}
return digitdp(digit.size()-1,1,0,0);
}
int main()
{
	Help_me
	#ifndef ONLINE_JUDGE
	//int number
	//string s="646";
	//stringstream s1(s);
	//s1>>number
	//stringstream convert;
	//convert>>numbere;
	//convert<<s
	//getline(cin>>ws,s);
//	FR
//	FW
	#endif
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));//no nedd to intialise the dp table for every test casse.because for every number answer will be same
	while(t--)
	{
		
		ull l,r;
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
}
return 0;

}
 
