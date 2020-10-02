// A simple C++ program for deleting a node from a Doubly linked list

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
    int i, n, key;
    
    node *p, *q, *head, *tail, *temp;
    
    // q is the DLL node.
    // p is a temporary variable used to iterate over the DLL q.
    // head is pointer that points to the first node of the DLL.
    // tail is pointer that points to the last node of the 
    // temp is used to store the previous node
    
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
// Linked List nodes are indexed on Zero based indexing.
cout<<"\nEnter an index position to delete node from the doubly linked list: ";
cin>>key;

if(key == 0)  // this block of code points head to the node which is next to 1st node i.e. 2nd node.
{
    p = head;
    p = p->next;
    head = p;
    p->prev = NULL;
}
else if(key == n-1) // this block of code points tail to the 2nd last node of the list.
{
    p = tail->prev;
    tail = p;
    p->next = NULL;
    tail->next = NULL;
}
else if(key > 0 && key < n-1)// this block manages deletion of the node for other index value 0 to n-1.
{
    p = head;
    for(i = 0; i < key; i++) 
    {
        temp = p;
        p = p->next;
    }

    // temp stores the node, previous to the node which is at index 'key'.
    p = p->next;
    temp->next = p;
    p->prev = temp;
}
else // if key value is greater than, equal to n or less than 0.
{
    cout<<"Entered an invalid index. Try again!";
    goto start;
}

p = head;

//printing the list after deletion.
cout<<"\nDoubly linked list node data after deletion: ";
while(p != NULL)
{
    cout<<p->data<<" ";
    p = p->next;
}

return 0;

}
