#include <bits/stdc++.h>
#define lp(i,n) for(int i=0; i<n; i++)
using namespace std;




int main() {

    int n;
    cin>>n;
    while(n--){
        int k;
        double ans=0;
        map <char, int> track;
        char c; int p;
        cin>>k;
        lp(i,k){
            cin>>c>>p;
            track[c]=p;
        }
        cin>>k;
        cin.ignore();
        string s;
        lp(i,k){
            getline(cin,s);
            for(auto ss:s){
                ans+=track[ss];
            }
        }
        cout<<setprecision(2)<<fixed<<ans/100<<"$"<<endl;

    }


}
