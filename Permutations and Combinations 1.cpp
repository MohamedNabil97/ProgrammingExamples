#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)

#define lli long long int

using namespace std;


int visited[20];

int gcd(int a,int b){
    return b==0? a: gcd(b, a%b);


}


void gen_perm(int n, vector <int> curr={}, int curr_len=0){
    if(curr_len==n){


            for(int x: curr){
                cout<< x<<" ";

            }

                cout<<endl;

        return;

    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){

            visited[i]=1;
            curr.pb(i);
            gen_perm(n,curr,curr_len+1);
            curr.pop_back();
            visited[i]=0;
        }


    }
}



long long int calc_perm_with_rep(vector <int> nums, int n){
    map <int,int> track;
    for(int x: nums) track[x]++;

    vector <int> up;
    vector <int> down;


    for(int i=n; i>=1; i--) up.pb(i);

    for(auto x: track){
            for(int i=2; i<=x.second; i++){
                down.pb(i);
            }
    }

    for(int &u:up){
        for(int &d: down){
            if(d==1)continue;
            int j=gcd(u,d);
            u/=j;
            d/=j;

        }
    }

    long long int ans=1;

    for(int u:up){
        ans*=u;
    }
    return ans;


}





int main(){
    vector <int> x={1,1,1,2,2};
    cout << calc_perm_with_rep(x,5);



}
