#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
int n,m;
vector<vector<int>> adj;
vector<int> components;
int get_cmp(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=true;
    int ans=1;
    for(auto i : adj[idx]){
        if(!vis[i]){
            ans+=get_cmp(i);
            vis[i]=true;
        }
    }
    return ans;
}
int32_t main() {
     cin>>n>>m;
     adj= vector<vector<int>>(n);
     vis= vector<bool>(n);
     for(int i=0;i<m;i++){
        int u,v;
         cin>>u>>v;
        adj[u].push_back(v);
       adj[v].push_back(u);
     }
     for(int i=0;i<n;i++){
         if(!vis[i]){
             components.push_back(get_cmp(i));
         }
     }
     for(auto i: components){
         cout<<i<<" ";
     }
}
