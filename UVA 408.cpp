#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;



int arr[1000000];
set <int> x;
int main(){
  int step,mod;
  while(cin>>step>>mod){
  x.clear();
  x.insert(0);
  for(int i=1; i<mod; i++){

    arr[i]=(arr[i-1]+step)%mod;
    if (x.find(arr[i])!=x.end()){
        break;

    }
    x.insert(arr[i]);
  }

  printf("%10d%10d", step, mod);
  if(x.size()==mod){
    cout<<"    Good Choice"<<endl;
  }else{
    cout<<"    Bad Choice"<<endl;
  }
    cout<<endl;

  }
}
