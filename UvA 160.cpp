#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;

int primearr[10000];

void gen_prime(){
    primearr[1]=1;
    primearr[0]=1;
    for(int i=0; i*i<=10000; i++){
        if(primearr[i]==0){
            for(int j=i+i; j<=10000; j+=i){
                primearr[j]=1;
            }
        }
    }


}

long long int Max_power_N (long long int n,long long int p){
    int ans=0;
    for(int i=p; i<=n; i*=p){
        ans+=n/i;
    }
    return ans;



}


vector <pair <int, int>> Factor_N(int n){
    vector <pair <int, int>> ans;
    for(int i=0; i<=n; i++){
        if(primearr[i]==0){
            ans.pb(make_pair(i,Max_power_N(n,i)));

        }
    }

    return ans;


}
int main(){
    gen_prime();
    int n;
    cin>>n;


    while(n!=0){
         vector <pair <int, int>> factors =Factor_N(n);
         printf("%3d! =",n);
         int cnt=0;
         for(int i=0; i<factors.size(); i++){
             printf("%3d",factors[i].second);
            cnt++;
            if(cnt==15 && i!=factors.size()-1){
                cnt=0;
                printf("\n      ");

            }
         }


         cout<<endl;
         cin>>n;
    }


}
