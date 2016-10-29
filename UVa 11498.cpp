#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(long long int p=0; p<n; p++)

using namespace std;



int main(){

    int k;
    while(true){
    cin>>k;
    if(k==0) return 0;
    int x,y,a,b;
    cin>>x>>y;
    lp(i,k){
        cin>>a>>b;
        if(a==x || y==b) cout<<"divisa";
        else if(a>x && b>y){
                cout<<"NE";

        }else if (a<x && b>y){
            cout<<"NO";
        }else if(a<x  && b<y ){
                cout<<"SO";
        }else if (a>x && b<y){
            cout<<"SE";
        }
        cout<<endl;




    }
    }
}
