#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;

int arr[70000];

void prime(){
    arr[0]=1;
    arr[1]=1;
    for(int i=2; i<=70000; i++){
        if(!arr[i]){
            for(int j=i+i; j<=70000; j+=i){
                arr[j]=1;
            }
        }
    }


}

long long int calc(long long int n, long long int k, long long int mod){
    if(k==1){
        return n%mod;
    }

    if(k%2==0){
       return calc( (n*n)%mod, k/2, mod) %mod;

    }else{
        return (n*calc((n*n)%mod,k/2,mod))%mod;

    }




}

//WE USE LONG LONG INT BECCAUSE THE MAXIMUM INTERMEDIATE PROCESS IS 65000*65000 which cant be handled by int



int main(){

    prime();

    long long int n;
    bool state;
    while(true){
        state=true;
        cin>>n;
        if(n==0){
            return 0;
        }

          for(long long int i=2; i<n; i++){
                if(calc(i,n,n)%n!=i || arr[n]==0){
                    cout<<n<<" is normal."<<endl;
                    state=false;
                    break;

                }
          }


        if(state){
            cout<<"The number "<<n<<" is a Carmichael number."<<endl;
        }

    }
}
