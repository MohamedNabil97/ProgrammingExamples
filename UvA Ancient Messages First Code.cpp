#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)
#define read_int(i) scanf("%d", &i)
#define ii pair<int,int>


using namespace std;

int n,m;
int grid[410][410];
int visited[410][410];



int dy[]={1,0,1,-1,0,-1,1,-1};
int dx[]={0,1,1,0,-1,-1,-1,1};

void out_floodfill(int r,int c){

    if(r>=n || c>=m*4 || r<0 || c<0) return;

    if(grid[r][c]!=0) return;

    grid[r][c]=3;

    lp(i,7){
        lp(j,7){
            out_floodfill(r+dx[i],c+dy[j]);

        }
    }



}


int cnt_components(int r,int c){
     if(r>=n || c>=m*4 || r<0 || c<0) return 0;

    if(grid[r][c]==3 || visited[r][c]==1 ) return 0;
    visited[r][c]=1;
    int ans=0;

    if(grid[r][c]==0) {

            out_floodfill(r,c);
            ans++;

    }

    lp(i,7){
        lp(j,7){
            ans+=cnt_components(r+dx[i],c+dy[j]);

        }
    }
    return ans;



}


void prepare_boundry(){
    for(int i=0; i<4*m; i++){
        if(grid[0][i]==0) out_floodfill(0,i);
    }
    for(int i=0; i<4*m; i++){
        if(grid[n-1][i]==0) out_floodfill(n-1,i);
    }
    for(int i=0; i<n; i++){
        if(grid[i][0]==0) out_floodfill(i,0);
    }
    for(int i=0; i<n; i++){
        if(grid[i][4*m-1]==0) out_floodfill(i,4*m-1);
    }


}

int main ()
{

    int c=1;



    while(cin>>n>>m && n||m){

    lp(i,410){
        lp(j,410){
            visited[i][j]=0;
            grid[i][j]=0;



        }

    }


    lp(j,n){
        string s;
        cin>>s;

        for (int i=0; i<s.size(); i++){
            int hex=0;
            if(s[i]>='0' && s[i] <='9') hex+= s[i]-'0';
            else hex+=s[i]-'a'+10;

            int pos=3;
            while(hex!=0){
                grid[j][i*4+pos]=hex%2;
                hex/=2;
                pos--;
            }



        }



    }
    prepare_boundry();
    vector <char> ans;
    int x;
    lp(i,n){
        lp(j,4*m-1){


            if(visited[i][j]==0 && grid[i][j]==1){
                   // floodfill(i,j);
                    int x=cnt_components(i,j);
                     if(x==1){
                    ans.pb('A');
                    }else if(x==3) ans.pb('J');
                    else if(x==5) ans.pb('D');
                    else if(x==4)ans.pb('S');
                    else if(x==0)ans.pb('W');
                    else if(x==2)ans.pb('K');


            }


        }

    }
    sort(ans.begin(),ans.end());

    cout<<"Case "<<c++<<": ";
    for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
    }
    cout<<endl;




    }
     return 0;
}


//END OF PROGRAM
