#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node *Arr[9];
struct node
{
    int data;
    node *link;
    int status;
};
class LINKLIST
{
public:
    void insertatend(int d,node **head)
    {
        node *ptr=*head;
        node*temp1=new node();
        temp1->data=d;
        temp1->link=NULL;
        if(*head==NULL)
        {
            *head=temp1;
            return;
        }
        node*temp2=*head;
        while(temp2->link!=NULL)
        {
            temp2=temp2->link;
        }
        temp2->link=temp1;
    }
    void print(node **head)
    {
         if(*head==NULL)
        {
            cout<<"list is empty "<<endl;
            return;
        }
        node*temp1=*head;
        while(temp1!=NULL)
        {
            cout<<temp1->data<<" ";
            temp1=temp1->link;
        }
        cout<<endl;
    }
};
int main()
{
    LINKLIST l;
    int edges,n1;
    for(int i=0;i<9;i++)
    {
        cout<<"Enter the no of edges connected to node "<<i<<" in the graph"<<endl;
        cin>>edges;
        for(int j=0;j<edges;j++)
        {
            cout<<"Enter the edge connected to node "<<i<<endl;
            cin>>n1;
            l.insertatend(n1,&Arr[i]);

        }
    }
    for(int i=0;i<9;i++)
    {
        cout<<"\n Node "<<i<<" is connected to these nodes "<<endl;
        l.print(&Arr[i]);
    }

}
