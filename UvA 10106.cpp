#include <bits/stdc++.h>
#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)
#define lli long long int

using namespace std;

int ans[10000];


int main(){
    string s1,s2;

    while(cin>>s1>>s2){
      int start=0;
      memset(ans,0,sizeof(ans));
      reverse(s1.begin(),s1.end());
      reverse(s2.begin(),s2.end());
  
  
      if(s1=="0"||s2=="0"){ //CASE TO HANDLE ZERO V IMP
          cout<<"0"<<endl;
          continue;
      }
      lp(i,s1.size()){
          lp(j,s2.size()){
              start=max(start,i+j);
              ans[i+j]+=(s1[i]-'0')*(s2[j]-'0');
  
          }
  
      }
      lp(i,10000-5){
          if(ans[i]>10){
              start=max(start,i+1);
              ans[i+1]+=ans[i]/10;
              ans[i]%=10;
          }
      }
  
  
  
      for(int i=start; i>=0; i--){
          cout<<ans[i];
      }
      cout<<endl;
    }
    return 0;
}
