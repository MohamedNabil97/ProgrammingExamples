#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;
long long int count1[100000+5];
long long int dp[100000+5];

int main(){
	int n,x;
	cin>>n;

	long long int mx=0;
	lp(i,n){
		cin>>x;
		mx=max((int)x,(int)mx);
		count1[x]++;
	}
	dp[0]=0;
	dp[1]=count1[1];

	for(long long int i=2; i<=mx; i++){
            dp[i]=max(dp[i-1],dp[i-2]+count1[i]*i);
	}


	cout<<dp[mx];
}
