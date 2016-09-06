#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;



int main(){

int n,m,c;

while(cin>>n>>m>>c){
if(n==0 && m==0 && c==0){
    return 0;
}
n-=7; m-=7;
long long int ans =max(0,n* (m/2));

ans+=((c+n)/2)*(m%2);


    cout<<ans<<endl;
}
}
