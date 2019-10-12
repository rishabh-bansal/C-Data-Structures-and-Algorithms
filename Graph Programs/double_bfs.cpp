#include <bits/stdc++.h>
using namespace std;
int vis[100005];
int diameter[100005];

int bfs(int s,vector<int> adj[],int n) {
    for(int i = 0;i <= n;i++) {
        vis[i] = 0;
        diameter[i] = 0;
    }
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(auto ch:adj[p]) {
            if(vis[ch] == 1)
                continue;
            vis[ch] = 1;
            diameter[ch] = diameter[p]+1;
            q.push(ch);
        }
    }
    return (max_element(diameter+1,diameter+n+1)-diameter);
}

int main() {
  int n;
  cin>>n;
  vector<int> adj[n+1];
  int temp = n-1;
  while(temp--) {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }      
  int init = bfs(1,adj,n);
  int maxx = bfs(init,adj,n);
  cout<<diameter[maxx]<<endl;
  return 0;
}
