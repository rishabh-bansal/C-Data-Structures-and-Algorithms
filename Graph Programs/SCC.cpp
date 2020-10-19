#include<iostream>
#include<algorithm>
#include<list>
#include<cstring>
using namespace std;
int comp = 0;
int*component;
class Graph
{
	int V;
	list<int>*adj;
	bool*visited;
public:
	Graph(int v);
	void addedge(int a, int b);
	void getdfs();
	void dfs(int x);
};
Graph::Graph(int v)
{
	V = v;
	adj = new list<int>[V + 1];
	component = new int[V + 1];
	visited = new bool[V + 1];
}
void Graph::addedge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
void Graph::getdfs()
{
	memset(visited, false, V + 1);
	for (int j = 1; j < V + 1; j++)
	{
		if (!visited[j])
		{
			comp++;
			dfs(j);
		}
	}
}
void Graph::dfs(int src)
{
	visited[src] = true;
	component[src] = comp;
	list<int>::iterator it;
	for (it = adj[src].begin(); it != adj[src].end(); it++)
	{
		if(!visited[(*it)])
		dfs(*it);
	}
}
int main()
{
	Graph g(9);
	g.addedge(1, 2);
	g.addedge(1, 3);
	g.addedge(1, 5);
	g.addedge(2, 4);
	g.addedge(2, 5);
	g.addedge(4, 6);
	g.addedge(6, 5);
	g.addedge(7, 8);
	g.addedge(8, 9);
	g.getdfs();
	for (int i = 1; i <= comp; i++)
	{
		cout << i << " : ";
		for (int j = 1; j < 10; j++)
		{
			if (component[j] == i)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}