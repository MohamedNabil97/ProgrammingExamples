#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX =1000;
long long int C[MAX+1][MAX]; //Whatever Needed

void build_nCk(){ //To Build To Combination Array

    for(int n=0; n<MAX; n++){
        for (int k=0; k<MAX; k++){
            if(n<k){ // Impossible
                break;
            }

             if (n==1 || n==k || k==0){// Base Cases
                C[n][k]=1;
            }else {
                C[n][k]=C[n-1][k]+C[n-1][k-1]; //Standard Combination Rule
            }

        }
    }

}



int main(){
    build_nCk();

    int n,m,t;
    cin>>n>>m>>t;

    long long int j;
    long long int ans=0;

    for(int i=0; i<=t; i++){
        j=t-i;
        if(i<4|| j<1 || i>n || j>m )continue; //If it doesnt fit constraints (to be safe)

        if(i>=4 && j>=1){

            ans+=C[n][i]*C[m][j];

        }

    }


    cout<<ans;
}
