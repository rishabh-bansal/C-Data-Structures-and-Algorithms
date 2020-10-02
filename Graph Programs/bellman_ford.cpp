#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define f first
#define s second

using namespace std;

int inf=INT_MAX;

int32_t main(){
     // Input
     int v,e;
     cin>>v>>e;
     vector<pair<pair<int,int>,int> > edges;
     for(int i=0;i<e;i++){
          int x,y,w;
          cin>>x>>y>>w;
          edges.push_back(mp(mp(x,y),w));
     }
     // Initialization
     int dist[v];
     dist[0]=0;
     for(int i=1;i<v;i++){
          dist[i]=inf;
     }

     //Main algo
     for(int i=0;i<v-1;i++){
          for(int j=0;j<e;j++){
               if(dist[edges[j].f.f]+edges[j].s < dist[edges[j].f.s]){
                    dist[edges[j].f.s]=dist[edges[j].f.f]+edges[j].s;
               }
          }
     }

     //output
     for(int i=0;i<v;i++){
          cout<<dist[i]<<" ";
     }
     return 0;
}
