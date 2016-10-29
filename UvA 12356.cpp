#include <bits/stdc++.h>
#define lp(i,n) for(int i=0; i<n; i++)
using namespace std;

int ls[100005+5];
int rs[100005+5];

int main() {
//    freopen("file.txt", "r",stdin);
//    freopen("file2.txt", "w",stdout);
    int s,b;
    while(true){
    scanf("%d %d",&s,&b);
        if(s==0 && b==0) return 0;
   lp(i,s+2) {
    ls[i]=i-1;
    rs[i]=i+1;

   }

    int l,r;
    lp(i,b){

        scanf("%d %d",&l,&r);


        int sl=ls[l],sr=rs[r];



        if(sl==0) printf("* "); else printf("%d ",sl);
        if(sr>s) printf("*\n"); else printf("%d\n",sr);
        rs[sl]=sr;
        ls[sr]=sl;




    }
    printf("-\n");
    }

}
