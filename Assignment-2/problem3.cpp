#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int r,int k)
{
	int mid,l=-1;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(a[mid]>=k)
		{
			r=mid;
		}
		else
			l=mid;
	}
	return r;
}

int longestIncreasingSubsequence(int a[],int n)
{
	int dp[n];
	int l=1;
	dp[0]=a[0];

	for(int i=1;i<(n);i++)
	{
		if(a[i]<dp[0])
		{
			dp[0]=a[i];
		}
		else if(a[i]>dp[l-1])
		{
			dp[l]=a[i];
			l++;
		}
		else
		{
			dp[binarySearch(dp,l-1,a[i])]=a[i];
		}
	}

	return l;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<n;i++)
        {
			cin>>a[i];
			a[i+n]=a[i];
		}

		int mx=0;
		for(int i=0;i<n;i++)
            mx=max(mx,longestIncreasingSubsequence(a+i,n));

        cout<<mx<<endl;
	}
	return 0;
}
