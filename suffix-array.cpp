//code for suffix array without the use of any inbuilt function like sorting function
//sample problem https://www.hackerearth.com/practice/data-structures/advanced-data-structures/suffix-arrays/practice-problems/algorithm/suffix-array-substring-occurrences/description/ 
#include<iostream>
using namespace std;
int p[111][1111];

class array{
public:
	int first;
	int second;
	int idx;
};
//code for merge sort

bool compare(array x,array y)
{
	if(x.first<y.first)
		return true;
	else if(x.first>y.first)
		return false;
	else
	{
		if(x.second<=y.second)
			return true;
		return false;
	}
}
void merge(int l,int r,int mid,array *arr)
{
	array left[mid-l+1];
	array right[r-mid];
	for(int i=0, j=l;i<mid-l+1;i++,j++)
		left[i]=arr[j];

	for(int i=0, j=mid+1;i<r-mid;i++,j++)
		right[i]=arr[j];
	int i=0,j=0;
	int sz1=mid-l+1;
	int sz2=r-mid;
	while(1)
	{
		if(compare(left[i],right[j]))
		{
			arr[l]=left[i];
			i++;
			l++;
		}
		else
		{
			arr[l]=right[j];
			j++;
			l++;
		}
		if(i==sz1)
		{
			while(j<sz2)
			{
				arr[l]=right[j];
				l++;
				j++;
			}
			break;
		}
		if(j==sz2)
		{
			while(i<sz1)
			{
				arr[l]=left[i];
				l++;
				i++;
			}
			break;
		}
	}
	
}
void merger(int l,int r,array *arr)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		merger(l,mid,arr);
		merger(mid+1,r,arr);
		merge(l,r,mid,arr);
	}
}


//code for suffix array starts from here


int strlen(char *s)
{
	int len=0;

	while(s[len]!='\0')
		len++;
	return len;
}
void swap(char *x,char *y)
{
	char *temp;
	temp=y;
	*y=*x;
	*x=*temp;

}
void reverse(char *s)
{
	int len=strlen(s);
	int i=0;
	while(i<len/2)
	{
		swap(s[i],s[len-i-1]);
		i++;
	}
}

void substr(int start,int len,char *s)
{
	for(int i=start;i<start+len;i++)
		cout<<s[i];
}
array l[1111];
void concate(char *x,char *y)
{
	int xx,yy;
	xx=strlen(x);
	yy=strlen(y);
	for(int i=0;i<yy;i++,xx++)
		x[xx]=y[i];
	x[xx]='\0';
}
int power[111];
int lcp(int i,int j,int step)
{
	int ans=0;
	while(step>=0)
	{
		if(p[step][i]==p[step][j])
		{
			ans+=power[step];
			i=i+power[step];
			j=j+power[step];
		}
		step--;
	}
	return ans;
}
int main()
{
	int len;
	char *s,*t;
	s=new char(1111);
	cin>>s;
	t=new char(111);
	cin>>t;
	int n=strlen(s);
	concate(s,t);
//	cout<<s<<endl;
	len=strlen(s);
	//reverse(s);
	for(int i=1;i<=len;i++)
		p[0][i]=s[i-1]-'a';

	int step=1;
	
	power[0]=1;
	for(int i=1;i<=20;i++)
		power[i]=power[i-1]*2;
	
	for(;power[step-1]<len;step++)
	{
		for(int j=1;j<=len;j++)
		{
			l[j].idx=j;
			l[j].first=p[step-1][j];
			l[j].second=j+power[step-1]<=len?p[step-1][j+power[step-1]]:-1;
		}
		merger(1,len,l);
		for(int j=1;j<=len;j++)
		{
			p[step][l[j].idx]=(j>1&&l[j-1].first==l[j].first&&l[j-1].second==l[j].second)?p[step][l[j-1].idx]:j;
		}
	}
	step--;
	int sa[1111];
	for(int i=1;i<=len;i++)
		sa[p[step][i]]=i;
	int len2=strlen(t);

	for(int i=1;i<=n;i++)
	{
		if(lcp(i,n+1,step)==len2)
		cout<<i-1<<" ";
		//cout<<lcp(i,n+1,step)<<endl;	
	}


}
