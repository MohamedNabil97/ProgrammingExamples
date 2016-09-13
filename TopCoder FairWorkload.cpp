#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;


int workers_needed(vector<int> x, int mx){
    int ans=1;
    int curr_sum=0;
    for(int i=0; i<x.size(); i++){
        if(curr_sum+x[i]>mx){
            ans++;
            if(x[i]>mx){
                return 1e9;
            }
            curr_sum=x[i];
        }else{
            curr_sum+=x[i];
        }
    }

    return ans;
}
class FairWorkload {
public: int   getMostWork (vector <int> files, int n){
        int lo=0, hi=10000;
        int mid=lo+(hi-lo)/2;
        while(lo<hi){

            mid=lo+(hi-lo)/2;
        if(workers_needed(files,mid)<=n){
            hi=mid;

        }else{
            lo=mid+1;
        }

        }


    return lo;


}

};