#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(long long int p=0; p<n; p++)

using namespace std;





int main(){

    int n;
    while(cin>>n){
        string curr="+x",nw;
        if(n==0) return 0;
    lp(i,n-1){
            cin>>nw;
            if(nw=="No") continue;
           if(curr=="+x"){
                curr=nw;
           }else if (curr=="-x"){
                curr=nw;
                if(nw[0]=='+') curr[0]='-'; else curr[0]='+';

           }else if (curr=="+y"){
                if(nw=="+y") curr="-x";
                if(nw=="-y") curr="+x";

           }else if (curr=="-y"){
                if(nw=="+y") curr="+x";
                if(nw=="-y") curr="-x";


           }else if(curr=="+z"){
                    if(nw=="+z") curr="-x";
                    if(nw=="-z") curr="+x";


           }else if(curr=="-z"){
                    if(nw=="+z") curr="+x";
                    if(nw=="-z") curr="-x";


           }


    }
    cout<<curr<<endl;
    }
}
