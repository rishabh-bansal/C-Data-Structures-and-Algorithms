// A simple C++ program to insert a node at user-defined position in a Doubly linked list

#include<iostream>
using namespace std;

class node
{
    public:
    
    int data;
    node *next, *prev; 
    // next is a pointer that points to the next node of the DLL(doubly linked list).
    // prev is a pointer that points to the previous node of the DLL.
};

int main()
{
    int i, n, key, pos;
    
    node *p, *q, *head, *tail, *temp, *new_node;
    
    // q is the DLL node.
    // p is a temporary variable used to iterate over the DLL q.
    // head is pointer that points to the first node of the DLL.
    // tail is pointer that points to the last node of the 
    // temp is used to store the previous node
    // new_node is the node which is inserted in the list.

    // taking user input for number of nodes.
    cout<<"Enter number of nodes: ";
    cin>>n;
    
    q = new node; // creating a node using new keyword.
    
    cout<<"Enter value of 1st  node: ";
    cin>>q->data; // assign data to the 1st node.
    
    q->next = NULL;
    q->prev = NULL;
    head = q; // head points to the first node of the DLL
    tail = q; // tail points to the last node of the DLL
    
    for(i = 1; i < n; i++)
    {
        q = new node;
        
        cout<<"Enter value of next node: ";
        cin>>q->data; // user input for next node data.
        
        q->next = NULL;
        q->prev = tail;
        tail->next = q;
        tail = tail->next;   
    
    // every interation creates a node and data is assigned to it.
}
tail->next = NULL; 

p = head;

// printing the doubly linked list.
cout<<"\nDoubly linked list node data: ";

while(p != NULL)
{
    cout<<p->data<<" ";
    p = p->next;
}

start:
// Doubly Linked List nodes are indexed on Zero based indexing.
cout<<"\nEnter data to insert node in the doubly linked list: ";
cin>>key;      // Data for the new node.
cout<<"\nEnter index position to insert node: ";
cin>>pos;     // Position to insert the newly created node in list.

if(pos == 0)  // this block of code creates and insert the newly created node in the begining.
{
    p = head;
    new_node = new node;
    new_node->data = key;
    new_node->prev = NULL;
    new_node->next = p;
    p->prev = new_node;
    head = new_node;
}
else if(pos == n) // this block of code creates and insert the newly created node at the end of the list.
{
    p = tail;
    new_node = new node;
    new_node->data = key;
    new_node->next = NULL;
    new_node->prev = p;
    p->next = new_node;
    tail = new_node;
}
else if(pos > 0 && pos <= n-1) // this block of code creates and insert node from 2nd position to n-1th position.
{
    p = head;
    for(i = 0; i < pos; i++) 
    {
        temp = p;
        p = p->next;
    }
    
    // temp stores the node, previous to the node which is at index 'pos'.
    
    new_node = new node;
    new_node->data = key;
    new_node->next = p;
    new_node->prev = temp;
    temp->next = new_node;
    p->prev = new_node;
}
else // if pos < 0 || pos > n. Then node cannot be inserted.
{
    cout<<"Entered an invalid index. Try again!";
    goto start; // Again enter the position to insert.
}

p = head;

//printing the list after inserting the node.
cout<<"\nDoubly linked list node data after insertion: ";
while(p != NULL)
{
    cout<<p->data<<" ";
    p = p->next;
}

return 0;

}
