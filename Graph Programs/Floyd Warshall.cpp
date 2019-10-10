#include<iostream>
#include<algorithm>
#define INF 1000000
using namespace std;
int main()
{
	int V, E, a, b, w;
	cin >> V >> E;
	int**matrix = new int*[V + 1];
	for (int i = 0; i < V + 1; i++)
	{
		matrix[i] = new int[V + 1];
	}
	for (int i = 0; i < V + 1; i++)
	{
		for (int j = 0; j < V + 1; j++)
		{
			matrix[i][j] = INF;
		}
	}
	for (int i = 1; i < V + 1; i++)
	{
		matrix[i][i] = 0;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> w;
		matrix[a][b] = w;
	}
	for (int k = 1; k < V + 1; k++)
	{
		for (int i = 1; i< V + 1; i++)
		{
			for (int j = 1; j < V + 1; j++)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
				{
					if (matrix[i][k] != INF && matrix[k][j] != INF)
					{
						matrix[i][j] = matrix[i][k] + matrix[k][j];
					}
				}
			}
		}
	}
	for (int i = 1; i < V + 1; i++)
	{
		
		for (int j = 1; j < V + 1; j++)
		{
			if(matrix[i][j]!=INF)
			cout << i << "   "<<j<<"  "<< matrix[i][j] << endl; 
		}
	}
}
