/**------------------------Dynamic Programming-----------------
"Imagine you have a collection of N wines placed next to each other on a shelf. For
simplicity, let's number the wines from left to right as they are standing on the shelf with
integers from 1 to N, respectively. The price of the i th wine is pi. (prices of di䌞耀erent wines
can be di䌞耀erent).
Because the wines get better every year, supposing today is the year 1, on year y the price
of the i th wine will be y*pi, i.e. y-times the value that current year.
You want to sell all the wines you have, but you want to sell exactly one wine per year,
starting on this year. One more constraint - on each year you are allowed to sell only
either the leftmost or the rightmost wine on the shelf and you are not allowed to reorder
the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).
You want to 䐨 nd out, what is the maximum pro䐨 t you can get, if you sell the wines in
optimal order?"
**/

#include<iostream>
using namespace std;
int val[1001];
int n;
int cache[1001][1001];//used to store result of the  the l to r
int profit(int l,int r)
{
	if(l>r)
		return 0;
	if(cache[l][r]!=-1)
		return cache[l][r];
	int year=n-(l-r+1)+1;//calculating number of years
	return cache[l][r]=max(profit(l+1,r)+(year)*val[l]+profit(l,r-1)+(year)*val[r]);//we can choose either left end or riht end
}
int main()
{
cin>>n;
for(int i=0;i<n;i++)
	cin>>val[i];
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
		cache[i][j]=-1;
}
cout<<profit(0,n-1);
return 0;
}
