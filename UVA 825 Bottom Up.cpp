#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;


int r,c;
int arr[500][500];
int dp[500][500];


int main(){
 //freopen("file.txt", "r", stdin);
   // freopen("file2.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--){

        cin>>r>>c;
        memset(arr,0,sizeof arr);

        cin.ignore();    // ignore '\n'
        string str;
        for (int i = 1, j; i <= r; ++i) {
            getline(cin, str);
            stringstream ss(str);
            ss >> j;    // ignore the first number
            while (ss >> j)
               arr[i-1][j-1] = -1;
        }

        memset(dp,0,sizeof dp);


        dp[r-1][c-1]=1;

        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                if(arr[i][j]==-1 ) continue;
                 if(i==r-1 && j==c-1 ) continue;
                dp[i][j]+=dp[i][j+1];
                dp[i][j]+=dp[i+1][j];

            }
        }
        cout<<dp[0][0]<<endl;
        if(t!=0) cout<<endl;
    }



}
