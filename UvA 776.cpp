#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;



char g[1005][1005];
int visited[1005][1005];
int col[1000];

void dfs(int i,int j,int r, int c, int monkey,int tree){

    if(visited[i][j]!=0 || i<0 || j<0 || i>=r || j >=c|| g[i][j]!=tree){
        return;
    }

    visited[i][j]=monkey;



    dfs(i+1,j,r,c,monkey,tree);
    dfs(i-1,j,r,c,monkey,tree);
    dfs(i,j-1,r,c,monkey,tree);
    dfs(i,j+1,r,c,monkey,tree);
    dfs(i+1,j+1,r,c,monkey,tree);
    dfs(i-1,j+1,r,c,monkey,tree);
    dfs(i+1,j-1,r,c,monkey,tree);
    dfs(i-1,j-1,r,c,monkey,tree);




}

int main ()
{
//    freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

    string s;

    char p;
    int r=0,c=0;
    int ii=0,jj=0;

    while(getline(cin,s)){
        if(s.empty()) break;



    if(s=="%"){


            int monkey=1;
            for(int rr=0; rr<500; rr++){
                lp(cc,500){
                    visited[rr][cc]=0;

                }
                col[rr]=0;
            }
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(!visited[i][j]){
                        dfs(i,j,r,c,monkey++,g[i][j]);
                    }

                    col[j]=max(col[j], visited[i][j]);


                }

            }

            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                        for(int x=1+floor((log10(visited[i][j]))); x<1+floor((log10(col[j]))); x++){
                            cout<<" ";
                        }
                        cout<<visited[i][j];
                         if(j!=c-1) cout<<" ";
                }
                cout<<endl;

            }
            cout<<"%"<<endl;
            r=0,c=0;
            ii=0,jj=0;
            continue;


        }


        jj=0;
        stringstream t(s);
        while(t>>p){
            visited[ii][jj]=0;
            col[jj]=0;
            g[ii][jj++]=p;

            c=max(jj,c);
        }
        ii++;
        r=max(ii,r);
    }


            int monkey=1;
            for(int rr=0; rr<500; rr++){
                lp(cc,500){
                    visited[rr][cc]=0;

                }
                col[rr]=0;
            }
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(!visited[i][j]){
                        dfs(i,j,r,c,monkey++,g[i][j]);
                    }

                    col[j]=max(col[j], visited[i][j]);


                }

            }

            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                        for(int x=1+floor((log10(visited[i][j]))); x<1+floor((log10(col[j]))); x++){
                            cout<<" ";
                        }
                        cout<<visited[i][j];
                        if(j!=c-1) cout<<" ";
                }
                cout<<endl;

            }
            cout<<"%"<<endl;

    return 0;
}
