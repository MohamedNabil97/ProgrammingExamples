#include <bits/stdc++.h>
#define lp(i,n) for(int i=0; i<n; i++)
using namespace std;

char big[2000][2000];
char small[1000][1000];
char small1[1000][1000];
char small2[1000][1000];
char small3[1000][1000];
char small4[1000][1000];


bool searching1 (int dim_xl,int dim_yl, int dim_xs, int dim_ys, int start_xl, int start_yl)
{
    if(dim_xs-1 > dim_xl-1-start_xl) return false;
    if(dim_ys-1 > dim_yl-1-start_yl) return false;

    for(int i=0; i<dim_xs; i++){
        for(int j=0; j<dim_ys; j++){

            if(small1[i][j]!=big[start_xl+i][start_yl+j]) return false;

        }
    }
    return true;


}

bool searching2 (int dim_xl,int dim_yl, int dim_xs, int dim_ys, int start_xl, int start_yl)
{
    if(dim_xs-1 > dim_xl-1-start_xl) return false;
    if(dim_ys-1 > dim_yl-1-start_yl) return false;

    for(int i=0; i<dim_xs; i++){
        for(int j=0; j<dim_ys; j++){

            if(small2[i][j]!=big[start_xl+i][start_yl+j]) return false;

        }
    }
    return true;


}

bool searching3(int dim_xl,int dim_yl, int dim_xs, int dim_ys, int start_xl, int start_yl)
{
    if(dim_xs-1 > dim_xl-1-start_xl) return false;
    if(dim_ys-1 > dim_yl-1-start_yl) return false;

    for(int i=0; i<dim_xs; i++){
        for(int j=0; j<dim_ys; j++){

            if(small3[i][j]!=big[start_xl+i][start_yl+j]) return false;

        }
    }
    return true;


}

bool searching4 (int dim_xl,int dim_yl, int dim_xs, int dim_ys, int start_xl, int start_yl)
{
    if(dim_xs-1 > dim_xl-1-start_xl) return false;
    if(dim_ys-1 > dim_yl-1-start_yl) return false;

    for(int i=0; i<dim_xs; i++){
        for(int j=0; j<dim_ys; j++){

            if(small4[i][j]!=big[start_xl+i][start_yl+j]) return false;

        }
    }
    return true;


}



int main()
{


    while(true){
        int N,n;
        cin>>N>>n;
        if(N==0 && n==0) return 0;

        int a=0,b=0,c=0,d=0;

        lp(i,N){

            cin>>big[i];


        }

         lp(i,n){

            cin>>small1[i];


        }

        lp(i,n){
            lp(j,n){
                small2[j][n-1-i]=small1[i][j];

            }


        }
        lp(i,n){
            lp(j,n){
                small3[j][n-1-i]=small2[i][j];

            }


        }

        lp(i,n){
            lp(j,n){
                small4[j][n-1-i]=small3[i][j];

            }


        }






        lp(i,N){
        lp(j,N){
            if(searching1(N,N,n,n,i,j)){
                a++;
            }


        }
        }

        lp(i,N){
        lp(j,N){
            if(searching2(N,N,n,n,i,j)){
                b++;
            }


        }
        }

        lp(i,N){
        lp(j,N){
            if(searching3(N,N,n,n,i,j)){
                c++;
            }


        }
        }

        lp(i,N){
        lp(j,N){
            if(searching4(N,N,n,n,i,j)){
                d++;
            }


        }
        }


        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    }

}
