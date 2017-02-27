#include <bits/stdc++.h>
using namespace std;

 int longestZigZag(int a[], int n){
 	int dp[2][n];
 	for (int i=0; i<n; i++)
 		dp[0][i]=dp[1][i]=1;

 	for (int i=0; i<n; i++)
    {
 		for (int j=0; j<i; j++)
            {
 			    if (a[i] > a[j])
 				  dp[1][i] = max(dp[1][i], dp[0][j]+1);
 			    else if (a[i] < a[j])
 				  dp[0][i] = max(dp[0][i], dp[1][j]+1);
 		}
    }

 	int mx = 0;
 	for (int i=0; i<n; i++)
 		mx = max(max(dp[0][i], dp[1][i]), mx);

 	return mx;
 }

 int main(){
     int n;
     cin>>n;
     int a[n];

     for(int i=0;i<n;i++)
        cin>>a[i];

 	int res=longestZigZag(a,n);
 	cout<<res<<endl;
 	return 0;
 }
