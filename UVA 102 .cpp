#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;

bool visited[3];
vector <string> mnvec;

int mn=9999;

void perm(vector <int> x, int total, int p=0, vector <int> curr={}){
    if(p==3){

        if(total<=mn){
            if(total!=mn){
                mnvec.clear();

            }
                string s;
                for(int x:curr){
                        switch(x){
                            case 0: s+="B"; break;
                            case 1: s+="G"; break;
                            case 2: s+="C"; break;
                        }

                }


            mnvec.pb(s);
            mn=total;
        }
        return;
    }
    for(int i=0; i<3; i++){
        if(!visited[i]){
            visited[i]=1;
            curr.pb(i);
            perm(x,total-x[i+p*3],p+1,curr);
            curr.pop_back();
            visited[i]=0;



        }



    }





}


int main(){
    vector <int> nums(9);
    int total;
while(cin>>nums[0]){
        mnvec.clear();
        total=nums[0];
    for(int i=1; i<9; i++){
        cin>>nums[i];
        total+=nums[i];
    }
    mn=total+10;


    perm(nums, total);
    sort(mnvec.begin(),mnvec.end());
    cout<<mnvec[0];
    cout<<" ";

    cout<<mn<<endl;




}
    return 0;
}
