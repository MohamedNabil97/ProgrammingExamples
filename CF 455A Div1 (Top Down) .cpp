#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;
long long int count1[100000+5];
long long int dp[100000+5];
long long int f(long long int n){
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=max(f(n-1), f(n-2)+count1[n]*n);


}


int main(){
	int n,x;
	cin>>n;
	memset(dp,-1,sizeof dp);
	long long int mx=0;
	lp(i,n){
		cin>>x;
		mx=max((int)x,(int)mx);
		count1[x]++;
	}


	cout<<f(mx+1);
}
