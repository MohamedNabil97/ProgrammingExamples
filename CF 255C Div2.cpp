#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(int p=0; p<n; p++)

using namespace std;


vector <int> track[1000000+5]; //array count instead of map

int maxsize(int i,int j){
    int s=1;
    int c=0;
    if(track[j][0]<track[i][0]) //optimization to avoid calling (i,j) and (j,i)
        swap(i,j);
    int currplace=track[i][0];


    int jn=0;
    int in=0;
    while(true){
    if(c%2==0){
        auto it=upper_bound(track[j].begin()+jn, track[j].end(), currplace);
        if(it!=track[j].end()){
                s++;
                currplace=*it;
                jn=it - track[j].begin();
                c++;

        }else{
            return s;
        }
    }else{
         auto it=upper_bound(track[i].begin()+in, track[i].end(), currplace);
        if(it!=track[i].end()){
                s++;
                currplace=*it;
                in=it-track[i].begin();
                c++;

        }else{
            return s;
        }

    }
    }

}



int main(){
    int n;
    scanf("%d", &n);

    set <int> numsset;
    int temp;
    lp(i,n){
        scanf("%d", &temp);
        numsset.insert(temp);
        track[temp].pb(i);
    }
    int mx=0;
    vector<int> nums(numsset.begin(), numsset.end());
    lp(i,nums.size()){
        for(int j=i; j<nums.size(); j++){ //need to start from i only because of above optimization

    
            mx=max(mx,maxsize(nums[i],nums[j]));

        }
    }

    cout<<mx;

}
