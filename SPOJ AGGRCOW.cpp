#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;


bool can(vector<int> x, int n, int space){
    int pos=x[0];
    int currcount=1;
    for(int i=1; i<x.size(); i++){
        if(currcount>=n) return true;
        if(x[i]-pos>=space){
            currcount++;
            pos=x[i];
        }
    }
    if(currcount>=n) return true;
    return false;



}

int maxspace(vector <int> place, int n){
    int low=1, high=1e9;
    int mid;
    while(low<high){
        if(high-low==1){
            if(can(place,n,high)){
                return high;
            }else{
                high--;
            }
        }
        mid=low+(high-low)/2;

        if(can(place,n,mid)){
            low=mid;
        }else{
            high=mid-1;
        }
    }

    return high;





}



int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,c;
        scanf("%d%d",&n ,&c);
        vector <int> places(n);
        lp(i,n){
            scanf("%d", &places[i]);
        }
        sort(places.begin(),places.end());
        printf("%d\n",maxspace(places,c));

    }
}
