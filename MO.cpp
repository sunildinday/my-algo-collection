/*
Problem :finding sum of all unique elements in range l ,r
using MO algorithm
O(n*sqrt(n))
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long  int ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define INF 10000000
#define  Help_me  ios_base::sync_with_stdio(false);
int bucket;
int sum=0;
int ans[1001];
int freq[1001];
int n;//number of element
int arr[1001];//elements in array
struct query
{
    int l,r;
    int idx;//index
};
query Q[1001];
bool cmp(struct query x,struct query y)
{
    if(x.l/bucket==y.l/bucket)
        return x.r<y.r;
    return x.l/bucket<y.l/bucket;
}
void add(int x)
{
if(freq[x]==0)
sum+=x;

freq[x]++;
}
void remove(int x)
{
    if(freq[x]==1)
        sum-=x;

        freq[x]--;
}
int main()
{
Help_me
cin>>n;
for(int i=0;i<n;i++)
    cin>>arr[i];
int q;//number of query
cin>>q;
int i=0;
bucket=sqrt(q);
while(i<q)
{
int l,r;
cin>>l>>r;
Q[i].l=l;
Q[i].r=r;
Q[i].idx=i;
i++;
}
sort(Q,Q+q,cmp);
int ll=0,rr=0;
freq[arr[0]]++;
sum+=arr[0];
for(int i=0;i<q;i++)
{
int l,r;
l=Q[i].l,r=Q[i].r;
while(ll<l)
{

remove(arr[ll]);
ll++;
}
while(ll>l)
{
    ll--;
    add(arr[ll]);
if(ll==l)
    break;
}
while(rr>r)
{

remove(arr[rr]);
r--;
}
while(rr<r)
{
rr++;
    add(arr[rr]);

}
ans[Q[i].idx]=sum;
}
for(int i=0;i<q;i++)
    cout<<ans[i]<<endl;
    return 0;
}
