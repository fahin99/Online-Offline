#include<bits/stdc++.h>
using namespace std;

bool bfs(int s, int t, vector<int>&parent, vector<vector<int>>&cap, vector<vector<int>>&adj){
    vector<bool> vis(parent.size(), 0);
    for(int i=0;i<parent.size();i++) parent[i]=-1;
    queue<int> q;
    q.push(s);
    vis[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v] and cap[u][v]>0){
                parent[v]=u;
                vis[v]=true;
                if(v==t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int max_flow(int s, int t, vector<vector<int>>&cap, vector<vector<int>>&adj){
    vector<int>parent(adj.size(), -1);
    int flow=0;
    while(bfs(s, t, parent, cap, adj)){
        int path=INT_MAX, v=t;
        while(v!=s){
            int u=parent[v];
            path=min(path, cap[u][v]);
            v=u;
        }
        v=t;
        while(v!=s){
            int u=parent[v];
            cap[u][v]-=path;
            cap[v][u]+=path;
            v=u;
        }
        flow+=path;
    }
    return flow;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<vector<int>> cap(n, vector<int>(n));
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v]+=w;
    }
    int ans=max_flow(0, n-1, cap, adj);
    cout<<ans<<endl;
}