#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)

#define lli long long int

using namespace std;


int primes[100];
int visited[20];

set <vector <int> > track;

void shift(vector <int> &x){
    x.insert(x.begin(),x[x.size()-1]);
    x.pop_back();

}

void seive(){
    primes[0]=1;
    primes[1]=1;
    for(int i=0; i*i<=100; i++){
        if(primes[i]==0){
            for(int j=i+i; j<=100; j+=i){
                primes[j]=1;


            }

        }

    }


}




void gen_perm(int n, vector <int> curr={1}, int curr_len=1){
    if(curr_len==n){
        bool flag = true;


        if(primes[curr[0]+curr[curr.size()-1]]==0 ){
             lp(i,n){

                if(track.find(curr)!=track.end()){
                    return;
                }
                shift(curr);
            }

                track.insert(curr);
            for(int x: curr){
                cout<< x;
                if(x!=curr[curr.size()-1]){
                    cout<<" ";
                }
            }

                cout<<endl;
        }
        return;

    }

    for(int i=2; i<=n; i++){
        if(!visited[i]){
            if(curr.size()>=1){
                if(primes[curr[curr.size()-1]+i]==1)
                    continue;
            }
            visited[i]=1;
            curr.pb(i);
            gen_perm(n,curr,curr_len+1);
            curr.pop_back();
            visited[i]=0;
        }


    }


}



int main(){
    seive();

    int n;
    int cs=0;
    while(cin>>n){
        if(cs!=0){
             cout<<endl;
        }
        cs++;
        track.clear();
        cout<<"Case "<<cs<<":"<<endl;
        gen_perm(n);


    }



}
