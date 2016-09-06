#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;


int r,c;
int arr[500][500];
int dp[500][500];


int number_of_ways(int i,int j){


    if(i>=r || j>=c || arr[i][j]==-1) return 0;

    if(i==r-1 && j==c-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];



    return dp[i][j]=number_of_ways(i+1,j)+number_of_ways(i,j+1);


}

int main(){
 //   freopen("file.txt", "r", stdin);
 //    freopen("file2.txt", "w", stdout);
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

        memset(dp,-1,sizeof dp);

        cout<<number_of_ways(0,0)<<endl;
        if(t!=0) cout<<endl;
    }



}
