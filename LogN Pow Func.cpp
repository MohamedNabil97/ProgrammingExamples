#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;


long long int calc(int n, int k, int mod){
    if(k==1){
        return n%mod;
    }

    if(k%2==0){
       return calc(n*n, k/2, mod);

    }else{
        return n*calc(n*n,k/2,mod);

    }





}
int main(){
    cout<<calc(100,3,107);

}
