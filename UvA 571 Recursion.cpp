#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;

pair<int,int> visited[1009][1009];
int x,y;
bool found=false;
int c=0;

bool fun(int Ca,int Cb, int N, int curr_a,int curr_b,pair<int,int> par){
   // cout<<c++<<endl;




    if(visited[curr_a][curr_b].first!=-1 )
        return false;

    if(visited[curr_a][curr_b].second!=-1) return false;


    visited[curr_a][curr_b]=par;

    if(curr_a==N || curr_b==N) {
            x=curr_a;
            y=curr_b;


            return true;

    }

    int poura=min(curr_b,Ca-curr_a);
    int pourb=min(curr_a,Cb-curr_b);


    return fun(Ca,Cb,N,0,curr_b,{curr_a,curr_b})
    || fun(Ca,Cb,N,curr_a,0,{curr_a,curr_b})
    || fun(Ca,Cb,N,Ca,curr_b,{curr_a,curr_b})
    || fun(Ca,Cb,N,curr_a,Cb,{curr_a,curr_b})
    || fun(Ca,Cb, N, curr_a+poura, curr_b-poura,{curr_a,curr_b})
    || fun(Ca,Cb, N, curr_a-pourb, curr_b+pourb,{curr_a,curr_b});




}

void check(int i,int j){

stack<pair<int,int> >x;
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
        x.push({i,j});

        i=par1;
        j=par2;


    }
     //cout<<i<<" "<<j<<endl;

     while((!x.empty())){
                    cout<<str.top()<<endl;
        str.pop();
        //cout<<x.top().first<<" "<<x.top().second<<endl;
        x.pop();
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


        if(fun(Ca,Cb,N,0,0,{-1,-1})){

            check(x,y);

        }
    }
    return 0;
}



