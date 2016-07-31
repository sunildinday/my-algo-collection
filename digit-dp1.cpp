/*
Problem Link:http://www.spoj.com/problems/CPCRC1C/
*/
    #include<bits/stdc++.h>
    using namespace std;
    long long int dp[10][9000];
    std::vector<int> digit;
    long long int digitdp(int idx,int tight,int sum)
    {
    if(idx==-1)
    {
        return sum;
    }
    if(!tight&&dp[idx][sum]!=-1)
        return dp[idx][sum];
    int newdigit;
    if(tight)
        newdigit=digit[idx];
    else
        newdigit=9;
    long long int ans=0;
    for(int d=0;d<=newdigit;d++)
    {
    ans+=digitdp(idx-1,tight&&(d==newdigit),sum+d);
    }
    if(!tight)
    dp[idx][sum]=ans;
    return ans;
    }
    long long int solve(long long int num)
    {
    digit.clear();
        if(num<=0)
        {
            return 0;
        }
        while(num)
        {
            digit.push_back(num%10);
            num/=10;
        }
        return digitdp(digit.size()-1,1,0);
     
     
    }
    int main()
    {
        long long int a,b;
             memset(dp,-1,sizeof(dp));
     
    while(1)
    {
        cin>>a>>b;
        if(a==-1&&b==-1)
            return 0;
        cout<<solve(b)-solve(a-1)<<endl;
      }
        return 0;
    }
     
