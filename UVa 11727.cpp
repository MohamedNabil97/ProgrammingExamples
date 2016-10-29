#include <bits/stdc++.h>
#define pb push_back
#define lp(p,n) for(long long int p=0; p<n; p++)

using namespace std;



int main(){

    int k;
    int c=1;
    cin>>k;
    while(k--){
        int arr[3];
        lp(i,3){
            cin>>arr[i];

        }
        sort(arr, arr+3);
        cout<<"Case "<<c++<<": "<<arr[1]<<endl;
    }
}
