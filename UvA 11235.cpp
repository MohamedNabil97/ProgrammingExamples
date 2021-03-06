#include <bits/stdc++.h>
#define lp(i,n) for(int i=0;i<n;i++)

using namespace std;

//p==index of

const int INF = INT_MAX;

int st[4*(100000+5)];
int A[100000+5];
 int cnt=0;
void build(int L, int R, int p){
    cnt++;
    if(L==R){ st[p]=R; return;}

    else {
            build(L,(L+R)/2, p*2);
            build((L+R)/2 +1, R, p*2+1);


            int p1= st[ p*2];
            int p2= st[p*2 + 1];
            int x=A[p1]; int y=A[p2];

            if(A[p1]>A[p2])
            st[p]= p1;
            else{
                st[p]=p2;
            }


    }




}

int rmq (int L, int R, int i ,int j,int p){
    if(j<i) return -1;

    if(L>j || R <i) return -1;

    if (L >= i && R <= j) return st[p];


    int p1 =    rmq(L,(L+R)/2, i,j,p*2);
    int p2 =      rmq((L+R)/2 +1, R, i,j,p*2+1);

    if(p1==-1) return p2;
    if(p2==-1) return p1;

    return A[p1]>A[p2]? p1:p2;

}

int main (){
//    freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    while(true){


        int n,ll;
        cin>>n;
        if(n==0) return 0;
        cin>>ll;
        int nums[n];
        int freq[n];
        int first_appearance[n];
        int last_appearance[n];

        map<int,int> freqmap;
        map <int,int> firstmap;


        for(int i=0; i<n; i++){
            cin>>nums[i];
            freqmap[nums[i]]++;
            if(firstmap.count(nums[i])==false) firstmap[nums[i]]=i;


        }
        for(int i=0; i<n; i++){
            A[i]=freq[i]=freqmap[nums[i]];
            first_appearance[i]=firstmap[nums[i]];

        }


        last_appearance[n-1]=n-1;
        int x=n-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]!=nums[i+1]){
                x=i;
            }
            last_appearance[i]=x;

        }




        build(0,n-1,1);


        lp(ssss,ll){
            int a,b;

            cin>>a>>b;

            a--;
            b--;
            if(nums[a]==nums[b]){
                cout<<b-a+1<<endl;
                continue;
            }
            vector <int> v;
            int t=0;
            if(a!=first_appearance[a]){
                t=last_appearance[a]-a+1;
                a=last_appearance[a]+1;
            }
            v.push_back(t);
            t=0;


            if(b!=last_appearance[b]){
                t=b-first_appearance[b]+1;
                b=first_appearance[b]-1;
            }


            v.push_back(t);

            int oss=rmq(0,n-1,a,b,1);
            if(oss!=-1) v.push_back(A[oss]);

           sort(v.begin(), v.end());

           cout<<v.back()<<endl;

        }

    }

}

