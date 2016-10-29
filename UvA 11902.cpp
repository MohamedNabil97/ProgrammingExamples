#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)
#define read_int(i) scanf("%d", &i)
using namespace std;

vector < vector <int> > adj_list;

int reachable[101]; //Checks if node reachable from start node
int visited[101];
int state[101][101];

void start_dfs(int node=0){
    reachable[node]=1;

    for(int neighbour:adj_list[node]){
        if(reachable[neighbour]==0){
            start_dfs(neighbour);
        }
    }

}

void dfs(int node,int dominator){
    if(node==dominator) return;

    visited[node]=1;
    state[dominator][node]=0;

    for(int neighbour:adj_list[node])
    {
        if(visited[neighbour]==0)
        {
            dfs(neighbour,dominator);
        }
    }




}

void print_line(int n){
    printf("+");
    for(int i=0; i<n+n+1-2; i++)
        printf("-");
     printf("+\n");

}

void print_case(int c){
    printf("Case %d:\n", c);


}

void reset_vars(){
    for(int i=0; i<101; i++){
        reachable[i]=0;
        visited[i]=0;
        for(int j=0; j<101; j++){
            state[i][j]=0;
        }
    }



}


int main ()
{
  //  freopen("in.txt", "r", stdin);

  //  freopen("out.txt", "w", stdout);

    int t;
    read_int(t);

    for(int c=1; c<=t; c++)
    {


        int n;
        read_int(n);
        adj_list= vector < vector <int> > (n);
        reset_vars();
        
        lp(i,n)
        {


            lp(j,n)
            {
                int x;
                read_int(x);
                if(x==1) adj_list[i].pb(j);


            }

        }

        start_dfs();

        lp(dominator,n){
            lp(node,n){
                if(reachable[node]==1)
                    state[dominator][node]=1;

            }

        }


        lp(i,n){
            memset(visited,0, sizeof visited);
            dfs(0,i);

        }

        print_case(c);
        lp(i,n)
        {
            print_line(n);
            cout<<"|";

            lp(j,n)
            {
                state[i][j]==1?cout<<"Y|":cout<<"N|";
            }
            cout<<endl;
        }

        print_line(n);

    }
    return 0;
}


