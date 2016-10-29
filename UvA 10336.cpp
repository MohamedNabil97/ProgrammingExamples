#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;


char grid[1000][1000];
int visited[1000][1000];

bool wayToSort(pair<char,int> a, pair<char,int>b){
    if(a.second>b.second) return true;

    if(a.second==b.second && a.first<b.first) return true;

    return false;


}

void dfs(int i,int j, char c,int n ,int m){

    if(grid[i][j]!=c || visited[i][j]==1|| i<0|| j<0||i>=n ||j>=m){
        return;
    }

    visited[i][j]=1;


    dfs(i-1,j,c,n,m);
    dfs(i+1,j,c,n,m);
    dfs(i,j-1,c,n,m);
    dfs(i,j+1,c,n,m);




}


int main ()
{
    int t;
    cin>>t;
    int cnt=1;
    while(t--){

     int n,m;
    cin>>n>>m;
    string s;
    lp(i,n){
        cin>>s;
        lp(j,m){
            visited[i][j]=0;

            grid[i][j]=s[j];
        }

    }
    map<char,int> track;
    lp(i,n){
        lp(j,m){
            if(visited[i][j]==0){
                track[grid[i][j]]++;
                dfs(i,j,grid[i][j],n,m);


            }

        }

    }


    vector<pair<char,int> > vec(track.begin(),track.end());
    sort(vec.begin(),vec.end(),wayToSort);
    printf("World #%d\n", cnt++);

    for(auto x:vec){

        printf("%c: %d\n", x.first, x.second);

    }
    }

}
