// Trees can be traversed in the following ways:
// - Depth First Traversals
//     1.Inorder
//     2.Preorder
//     3.Postorder
// - Breadth First Traversal/Level Order Traversal


#include "iostream"
#include "queue"
using namespace std;

//Creating the tree structure
struct Node {
    int data;
    struct Node* left, *right;
};

//Inorder Traversal
void inorder(Node *root)
{
    if (root==NULL)               //Base case: return if node does not exist
        return;
    inorder(root->left);          //Accessing left node first
    cout<<root->data<<" ";        //Print the data
    inorder(root->right);         //Accessing right node
}

//Preorder Traversal
void preorder(Node *root)
{
    if (root==NULL)               //Base case: return if node does not exist
        return;
    cout<<root->data<<" ";        //Print the data first    
    preorder(root->left);         //Accessing left node
    preorder(root->right);        //Accessing right node
}

//Postorder Traversal
void postorder(Node *root)
{
    if (root==NULL)               //Base case: return if node does not exist
        return;
    postorder(root->left);        //Accessing left node first
    postorder(root->right);       //Accessing right node
    cout<<root->data<<" ";        //Print the data
}

//Level Order
void levelorder(Node *root)
{
    if(root==NULL)                          //Base case
        return;
        
    queue<Node*> order;                     //Initialise a queue
    order.push(root);                       //Push root of tree in queue

    while(!order.empty())                   //While queue is not empty
    {
        Node *temp = order.front();         //Store node at front of queue in temp
        cout<<temp->data<<" ";              //Print its value
        order.pop();                        //Pop the node from queue

        if(!temp->left)                     //If temp has a left node
            order.push(temp->left);         //push in queue
        if(!temp->right)                    //If temp has a right node
            order.push(temp->right);        //push in queue
    }
}
