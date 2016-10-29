#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;

pair<int,int> visited[1009][1009];

pair<int,int> bfs(int Ca,int Cb, int N){




    queue <pair<int,int> > q;
    q.push({0,0});


    while(!q.empty()){
        auto fr=q.front();
        q.pop();
        if(fr.first==N || fr.second==N) {



            return fr;

        }

        if(visited[0][fr.second]==make_pair(-1,-1)){
            visited[0][fr.second]={fr.first,fr.second};
            q.push({0,fr.second});
        }

        if(visited[fr.first][0]==make_pair(-1,-1)){
            visited[fr.first][0]={fr.first,fr.second};
            q.push({fr.first,0});
        }

        if(visited[Ca][fr.second]==make_pair(-1,-1)){
            visited[Ca][fr.second]={fr.first,fr.second};
            q.push({Ca,fr.second});
        }

        if(visited[fr.first][Cb]==make_pair(-1,-1)){
            visited[fr.first][Cb]={fr.first,fr.second};
            q.push({fr.first,Cb});
        }


            int poura=min(fr.second,Ca-fr.first);
            int pourb=min(fr.first,Cb-fr.second);



        if (visited [fr.first+poura][fr.second-poura]==make_pair(-1,-1)){
             visited[fr.first+poura][fr.second-poura]={fr.first,fr.second};
            q.push({fr.first+poura, fr.second-poura});

        }


        if(visited[fr.first-pourb][fr.second+pourb]==make_pair(-1,-1)){
            visited[fr.first-pourb][fr.second+pourb]={fr.first,fr.second};
            q.push({fr.first-pourb,fr.second+pourb});
        }






    }/* END OF WHILE */





    //return fr;



}/*END OF BFS*/

void print_states(int i,int j){


    stack<string> str;
    while(i!=0  || j!=0){



        int par1,par2;
        par1=visited[i][j].first;
        par2=visited[i][j].second;

        if((par2==j) && i>par1){
            str.push("fill A");
        }else if((par2==j) && par1>i){
            str.push("empty A");
        } else  if((par1==i) && j>par2){
            str.push("fill B");
        }else if((par1==i) && j<par2){
            str.push("empty B");
        }else if(par1>i && par2<j){
            str.push("pour A B");
        }else if(par1<i && par2>j){
            str.push("pour B A");
        }


        i=par1;
        j=par2;


    }


     while((!str.empty())){
                    cout<<str.top()<<endl;
            str.pop();

     }
     cout<<"success"<<endl;

}

int main ()
{

    int Ca,Cb,N;
    while(cin>>Ca>>Cb>>N){
            for(int i=0 ;i<1001; i++){
                for(int j=0 ;j<1001; j++){
                    visited[i][j]={-1,-1};
                }
            }



            pair<int,int> final_state=bfs(Ca,Cb,N);
            print_states(final_state.first,final_state.second);


    }
    return 0;
}



