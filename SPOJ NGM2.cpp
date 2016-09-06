#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(long long int i=0; i<n; i++)
#define lli long long int

using namespace std;

int gcd(long long int  a,long long int  b){
    if(b==0) return a;

    return gcd (b,a%b);

}

long long int  lcm(long long int  a,long long int  b){

    return (a*b)/gcd(a,b);

}


long long int  inc_exe(long long int  n, vector <long long int > primes, long long int  idx=0, long long int  d=1,long long int  sign=-1 ){
        if(idx==primes.size()){
            if(d==1){
                return 0;
            }
            return sign*n/d;


        }
        return inc_exe(n,primes,idx+1, d ,sign)+inc_exe(n,primes,idx+1,lcm(d,primes[idx]),sign*-1);


}



int main(){

    long long int  n,k;
    cin>>n>>k;

    vector<long long int > primes(k);

    lp(i,k){
        cin>>primes[i];
    }

    lp(i,k){
        if(primes[i]==1){

            cout<<"0"<<endl;
            return 0;
        }

    }




    cout<<n-inc_exe(n,primes);



}
