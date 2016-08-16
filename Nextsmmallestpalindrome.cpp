/*
Problem:Given a number find its next palindrome
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define INF 10000000
#define  Help_me  ios_base::sync_with_stdio(false);
int num[1001];
bool allnine(int n)
{
for(int i=0;i<n;i++)
{
    if(num[i]!=9)
        return  false;
}
return true;
}
void solve(int n)
{
int i,j;
bool middle=false;
int mid=n/2;
i=mid-1;
(n%2!=0)?j=mid+1:j=mid;
while(i>=0&&(num[i]==num[j]))
{
    i--;j++;
}
if(i<0||(num[i]<num[j]))//if i<0 then number is already palindrome so we have to increase the middle number
middle=true;
while(i>=0)//if number is not palindrome then make it palindrome
{
    num[j]=num[i];
    i--;j++;
}
if(middle)//if number is palindrome or left <right digit then we have to increase the middle number
{
i=mid-1;
(n%2!=0)?j=mid+1:j=mid;
if(n&1)
i=j=mid;
int carry=1;
while(i>=0)
{
    num[i]+=carry;
    carry=num[i]/10;
    num[i]=num[i]%10;
    num[j]=num[i];

    i--;j++;

}
}
}
int main()
{
Help_me
int n;//number of digits in number
cin>>n;
for(int i=0;i<n;i++)
cin>>num[i];
if(allnine(n))
{
    cout<<"1";
    for(int i=0;i<n;i++)
        cout<<"0";
    cout<<"1";
}
else
{
solve(n);
for(int i=0;i<n;i++)
cout<<num[i];
}
    return 0;
}
