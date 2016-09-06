#include <bits/stdc++.h>
#define pb push_back

using namespace std;
int visited[26];
vector <int> visit;
int main(){
    string s;
    cin>>s;
    vector <vector <int> > adj_list(26+1);

    string t;
    map <int, int> track;
    while(cin>>t){
        if(t=="#") break;

        for(int i=0; i<min(t.size(),s.size()); i++){
            if(s[i]!=t[i]){
                adj_list[s[i]-'A'].pb(t[i]-'A');

                if(track.count(s[i]-'A')==0){
                    track[s[i]-'A']=0;

                }

                track[t[i]-'A']++;
                break;
            }

        }
        s=t;


    }
    vector <char> ans;

    while(ans.size()<track.size()){
        for(auto &x: track){
            if (x.second==0){
                ans.pb(x.first+'A');
                x.second=-1;
                 for(int pp: adj_list[x.first]){
                track[pp]--;
                }
                break;
            }


        }
    }
    for(char x:ans){
        cout<<x;
    }
    cout<<endl;

    return 0;
}
