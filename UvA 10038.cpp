#include <bits/stdc++.h>
using namespace std;



int main() {

    int n;
    while(cin>>n){
        int s;
        vector <int> nums;
        int temp=n;
        while(temp--){
            cin>>s;
            nums.push_back(s);
        }

        vector <bool> check(n);
        check[0]=1;

        bool flag=true;

        for(int i=1; i<nums.size(); i++){

            if(abs(nums[i]-nums[i-1])<n)
              check[abs(nums[i]-nums[i-1])]=true;
        }

        for(int i=1; i<n; i++){
            if(check[i]==0) flag=false;
        }



        if (flag) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
    }


}
