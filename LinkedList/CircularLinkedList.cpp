// A simple C++ program for traversal of a Circular linked list

#include<iostream>
using namespace std;

class node
{
    public:
    
    int data;
    node *next; 
    // next is a pointer that points to the next node of the CLL (circlar linked list).

};

int main()
{
    int i,n;
    
    node *p, *q, *head;  
    
    // q is the CLL node.
    // p is a temporary variable used to iterate over the CLL q.
    // head is pointer that points to the first node of the CLL.
    
    
    // taking user input for number of nodes.
    
    cout<<"Enter number of nodes: ";
    cin>>n;
    
    q = new node; // creating a node using new keyword.
    
    cout<<"Enter value of 1st node: ";
    cin>>q->data; // assign data to the 1st node.
    
    q->next = NULL;
    head = q; // head points to the first node of the CLL
    
    p = head; // value of head assigned to p to iterate from 1st node to the last.
    
    for(i = 1; i < n; i++)
    {
        q = new node;
        
        cout<<"Enter value of next node: ";
        cin>>q->data; // user input for next node data.
        
        q->next = NULL; 
        p->next = q;
        p = p->next;   
    
    // every interation creates a node and data is assigned to it.
}

q->next = head; // last node pointing to the head node making a CLL.

p = head;

cout<<"\nCircular linked list node data: ";
do  // traversal of CCL using a do-while loop.
{
    cout<<p->data<<" ";
    p = p->next;
    
}
while(p != head);

return 0;

}
