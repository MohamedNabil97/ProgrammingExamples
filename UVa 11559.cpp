#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(long long int p=0; p<n; p++)

using namespace std;





int main(){


    int n,b,h,w;
    while(cin>>n>>b>>h>>w){
    int p,a,mn=INT_MAX;;
    lp(i,h){
        cin>>p;
        lp(j,w){
           cin>>a;
           if(a>=n )
            mn=min(mn,n*p);

        }


    }
    if(mn<=b) cout<<mn<<endl; else cout<<"stay home"<<endl;
    }
}
