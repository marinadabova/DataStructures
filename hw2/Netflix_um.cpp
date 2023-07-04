#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main() {
    string s;
    cin>>s;
    
    unordered_map<char,int> mp;
    queue<pair<int,char>> q;
    
    int size=s.length();
    for(int i=0;i<size;i++){
        char ch=s[i];
        mp[ch]++;
        if(mp[ch]<=1){
            q.push({i,ch});
        }
    }
  
    while(!q.empty()){
        if(mp[q.front().second]==1)
            cout<<q.front().first<<" ";   
        q.pop();
    }
    
    return 0;
}
