#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;


stack<int> ans;
int visited[1000];

void dfs(int i,vector<vector<int>> graph){

    if(visited[i]==1){
        return;
    }

    visited[i]=1;


   for(auto x: graph[i])
    dfs(x,graph);


   ans.push(i);



}


int main ()
{
    int n,m;
    while(1){
    cin>>n>>m;
    if(!n && !m) return 0;
    lp(ss,n+2)
    visited[ss]=0;
    vector <vector<int>> graph(n+1);

    int i,j;
    lp(oii,m){
        cin>>i>>j;

        graph[i].pb(j);

    }

    for(int i=1; i<n+1; i++){
        if(visited[i]==0) dfs(i,graph);


    }

    while(!ans.empty()){

        cout<<ans.top()<< " ";
        ans.pop();


    }
    cout<<endl;
    }
}
