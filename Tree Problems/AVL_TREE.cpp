// C++ program to implement AVL Tree  
#include<bits/stdc++.h> 
using namespace std; 
  
// An AVL tree node  
class Node{  
    public: 
    int key;  
    Node *left;  
    Node *right;  
    int height;  
};  
  
// A function to get height of the tree  
int height(Node *N){  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
  
/* A function to generate a new node */
Node* newNode(int key){  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially added at leaf  
    return(node);  
}  
  
// A function to right 
// rotate subtree rooted with y  
Node *rightRotate(Node *y){  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
    x->height = max(height(x->left),  
                    height(x->right)) + 1;  
  
    // Return new root  
    return x;  
}  
  
// A function to left  
// rotate subtree rooted with x 
Node *leftRotate(Node *x){  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  
  
// Get Balance factor of node N  
int getBalance(Node *N){  
    if (N == NULL)  
        return 0;  
    return height(N->left) -  
           height(N->right);  
}  
  
Node* insert(Node* node, int key){  
    /* 1. Perform the normal BST rotation */
    if (node == NULL) return(newNode(key));  

    if (key < node->key)  
        node->left = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
    else // Equal keys disallowed  
        return node;  
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));  
  
    /* 3. Get the balance factor of this  
        ancestor node to check whether  
        this node became unbalanced */
    int balance = getBalance(node);  
  
    // If this node becomes unbalanced, then there are 4 cases: 
    // Left Left Case  
    if (balance > 1 && key < node->left->key)  
        return rightRotate(node);    
    // Right Right Case  
    if (balance < -1 && key > node->right->key)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->key){  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->key){  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    /* return the (unchanged) node pointer */
    return node;  
}  
  
/* Given a non-empty binary search tree,  
return the node with minimum key value  
found in that tree. Note that the entire  
tree does not need to be searched. */
Node * minValueNode(Node* node){  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  
  
// Recursive function to delete a node  
// with given key from subtree with  
// given root. It returns root of the  
// modified subtree.  
Node* deleteNode(Node* root, int key){  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else {  
        // node with only one child or no child  
        if( (root->left == NULL) ||(root->right == NULL)){  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL){  
                temp = root;  
                root = NULL;  
            }  
            else 				// One child case  
				*root = *temp; 	// Copy the contents of  
								// the non-empty child  
            free(temp);  
        }  
        else{  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL) return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 && getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 && getBalance(root->left) < 0){  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 && getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 && getBalance(root->right) > 0){  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
  
// A utility function to print preorder  
// traversal of the tree.  
void preOrder(Node *root){  
    if(root != NULL){  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

// A utility function to print inorder  
// traversal of the tree. 
void inorder(Node *root){
    if (root == NULL) return;
    inorder (root->left);
    cout<<root->key<<"  ";
    inorder (root->right);
}

// A utility function to print postorder  
// traversal of the tree. 
void postorder(Node *root){
    if (root == NULL) return;
    postorder ( root ->left );
    postorder ( root ->right );
    cout<<root->key<<"  ";
}
bool search(Node *root, int item){
	if (root == NULL) return false;
    if (root->key == item) return true;
    bool s1 = search(root->left, item);
    bool s2 = search(root->right, item);
    return s1 || s2;
}  
// Driver Code 
int main()  {  
	int choice, item;
	Node *root = NULL;
	
	while (1){
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Remove Element from the tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice) {
			case 1:
				cout<<"Enter value to be inserted: ";
				cin>>item;
				root = insert(root, item);
				break;
			case 2:
				cout<<"Enter value to be deleted: ";
				cin >> item;
				if (root == NULL)
				{
					cout<<"Tree is Empty"<<endl;
					continue;
				}
				deleteNode(root, item);
				if(search(root, item))
					cout << item << " has seccessfully deleted" << endl;
				else
					cout << item << " is not the member of the tree" << endl;
				break;
			case 3:
				cout<<"Inorder Traversal:"<<endl;
				inorder(root);
				cout<<endl;
				break;
			case 4:
				cout<<"Preorder Traversal:"<<endl;
				preOrder(root);
				cout<<endl;
				break;
			case 5:
				cout<<"Postorder Traversal:"<<endl;
				postorder(root);    
				cout<<endl;
				break;
			case 6:
				exit(1);    
				break;
			default:
				cout<<"Wrong Choice"<<endl;
		}
    }
    return 0;  
}
