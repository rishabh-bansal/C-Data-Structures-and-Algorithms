#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of vertices in the graph"<<endl;
    cin>>n;
    int arr[n][n],que[n],fronty,rare,visit[n],visited[n],stk[n],top;
    putzero(arr);
    int edges,n1,n2,n3,n4;
    cout<<" Enter the numbers of Edges "<<endl;
    cin>>edges;
    cout<<"Marks the edges (connection) between two nodes "<<endl;
     for(int i=1;i<=edges;i++)
    {
        cin>>n1>>n2;
        cout<<"next mark"<<endl;
        arr[n1][n2]=1;
    }
    cout<<"Printng of matrix of graph "<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Enter the initial node to traverse(BFS) from :"<<endl;
    cin>>n3;
    BFS(n3);
    cout<<"Enter the initial node to traverse(DFS) from :"<<endl;
    cin>>n4;
    DFS(n4);
}
void putzero(int arr[M][N])
{

    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            arr[i][j]=0;
        }
    }
}

