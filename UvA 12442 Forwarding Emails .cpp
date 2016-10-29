#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)
#define read_int(i) scanf("%d", &i)
#define ii pair<int,int>


using namespace std;

int sum[50000+5];
int visited[50000+5];
int graph[50000+5];
bool state=false;
int end_loop=0;
stack<int> vertex;

int dfs(int node){

    if(sum[node]!=-1)
        return sum[node];

    if(visited[node]==1){
            state=true;
            end_loop=node;
            return -1;

    }

    visited[node]=1;

    vertex.push(node);


    if(graph[node]==-1){
        sum[node]=0;
        return  sum[node];
    }


    return sum[node]=1+dfs(graph[node]);

}

void set_vars(){
        for(int i=0; i<50000+4; i++){
            graph[i]=-1;
            sum[i]=-1;
            visited[i]=0;
             while(!vertex.empty())vertex.pop();
             state=false;
        }



}

int main ()
{

    //freopen("in.txt","r",stdin);

   // freopen("out.txt","w",stdout);
    int c=1;

    int t;
    scanf("%d",&t);

   while(t--){
        int n;

        scanf("%d", &n);

        set_vars();


        int u,v;
        lp(i,n){

            scanf("%d%d",&u,&v);
            graph[u]=v;
        }


        int mx=-1,mx_ver=0;

        for(int i=1; i<=n; i++){

            if(visited[i]==0){
                state=false;
                while(!vertex.empty())vertex.pop();

                sum[i]=dfs(i);

                if(state){
                    while(!vertex.empty()){
                            sum[vertex.top()]=sum[end_loop];

                            if(vertex.top()==end_loop) break;

                            vertex.pop();
                    }

                }
            }

            if(sum[i]>mx){
                mx_ver=i;
                mx=sum[i];

            }

        }

        printf("Case %d: %d\n",c++,mx_ver);

    }
     return 0;
}


//END OF PROGRAM
