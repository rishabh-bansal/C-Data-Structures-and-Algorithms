
Dado un grafo dirigido halla las componentes fuertemente conexas (SCC).

const int MAX = 100005; 
vector<int> g[MAX]; 
bitset<MAX> vis;
stack<int> st;
int low[MAX], num[MAX], cont;
int compOf[MAX]; 
int cantSCC; 
int N, M; 

void tarjan(int u) {
    low[u] = num[u] = cont++;
    st.push(u);
    vis[u] = true;
    
    for (int v : g[u]) {
        if (num[v] == -1)
            tarjan(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    
    if (low[u] == num[u]) {
        while (true) {
            int v = st.top(); st.pop();
            vis[v] = false;
            compOf[v] = cantSCC;
            if (u == v) break;
        }
        cantSCC++;
    }
}

void init() {
    cont = cantSCC = 0;
    for (int i = 0; i <= N; i++) {
        g[i].clear();
        num[i] = -1; //no visit
    }
}
