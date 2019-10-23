#include <iostream>
using namespace std;

struct node
{
	string data;
	node *lf, *rt;
};

class AVLTree
{
	node * root;
public:
	AVLTree()
	{
		root = NULL;
	}

	int BF(node * );
	int height(node * );
	node * balance(node * );
	void Delete(node*);
	node * insert(node * , string );

	node * rotateLeft(node * );
	node * rotateRight(node * );
	node * LL(node * );
	node * LR(node * );
	node * RR(node * );
	node * RL(node * );

	void Preorder(node *);
	void Inorder(node *);
	void Postorder(node *);

	void search();
};

int AVLTree ::BF(node *root)
{
	int bf = height(root->lf) - height(root->rt);
	return bf;
}

node * AVLTree ::balance(node *T)
{
	int bal_factor = BF(T);

	if(bal_factor > 1)
	{
		if(BF(T->lf) > 0)
			T = LL(T);
		else
			T = LR(T);
	}
	else if(bal_factor < -1)
	{
		if(BF(T->rt) > 0)
			T = RL(T);
		else
			T = RR(T);
	}
	return T;
}

int AVLTree ::height(node * temp)
{
	int h = 0;
	if(temp != NULL)
	{
		int l_height = height(temp->lf);
		int r_height = height(temp->rt);

		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

node * AVLTree ::insert(node *root, string val)
{

	if(root == NULL)
	{
		root = new node;
		root->data = val;
		root->lf = root->rt = NULL;
		return root;
	}
	else if(val < root->data)
	{										 //go to left
		root->lf = insert(root->lf, val);
		root = balance(root);
	}
	else if(val >= root->data)
	{ 										 //go to right
		root->rt = insert(root->rt, val);
		root = balance(root);
	}
	this->root = root;
	return root;
}

node * AVLTree ::rotateLeft(node * x)
{
	node *z;
	z = x->rt;
	x->rt = z->lf;
	z->lf = x;
	return z;
}

node * AVLTree ::rotateRight(node * x)
{
	node *y;
	y = x->lf;
	x->lf = y->rt;
	y->rt = x;
	return y;
}

node * AVLTree ::LL(node * x)
{
	node * y;
	y = rotateRight(x);
	return y;
}

node * AVLTree ::RR(node * x)
{
	node * y;
	y = rotateLeft(x);
	return y;
}

node * AVLTree ::LR(node *x)
{
	node *y, *z;
	y = x->lf;
	z = rotateLeft(y);
	x->lf = z;
	z = rotateRight(x);
	return z;
}

node * AVLTree ::RL(node *x)
{
	node *y, *z;
	y = x->rt;
	z = rotateRight(y);
	x->rt = z;
	z = rotateLeft(x);
	return z;
}

void AVLTree :: Inorder(node *cn)
{
	if(cn != NULL)
	{
		Inorder(cn->lf);
		cout << "   " << cn->data;
		Inorder(cn->rt);
	}
}

void AVLTree :: Preorder(node *cn)
{
	if(cn != NULL)
	{
		cout << "   " << cn->data;
		Preorder(cn->lf);
		Preorder(cn->rt);
	}
}

void AVLTree :: Postorder(node *cn)
{
	if(cn != NULL)
	{
		Postorder(cn->lf);
		Postorder(cn->rt);
		cout << "   " << cn->data;
	}
}

void AVLTree :: search()
{
	node *cn;
	cn = root;
	int flag=0;

	string tdata;
	cout << "Enter the data to be searched : ";
	cin >> tdata;

	while(cn != NULL)
	{
		if(cn->data == tdata)
		{
			flag = 1;
			break;
		}
		else if(tdata > cn->data)
			cn = cn->rt;
		else
			cn = cn->lf;
	}

	if(flag == 1)
		cout << "\nData found !!!!\n";
	else
		cout << "\nData not found !!!!\n";
}




void AVLTree :: Delete(node *)
{
	node *parent, *ptr;
	ptr = root;

	int flag = 0;
	string tword;
	cout << "Enter the word to be deleted : ";
	cin >> tword;
	while(ptr != NULL)
	{
		if(ptr->data == tword)
		{
			flag = 1;
			break;
		}
		parent = ptr;
		if(tword > ptr->data)
			ptr = ptr->rt;
		else
			ptr = ptr->lf;
	}

	if(flag == 1)
	{
		//case 1 : Leaf node

		if(ptr->lf == NULL && ptr->rt == NULL)
		{
			if(parent->lf == ptr)
				parent->lf = NULL;
			else
				parent->rt = NULL;
		delete(ptr);
		balance(parent);
		}

		//case 2 : Only one child

		else if(ptr->lf == NULL)
		{
			if(parent->rt == ptr)
				parent->rt = ptr->rt;
			else
				parent->lf = ptr->rt;
				
		delete(ptr);
		balance(parent);
		}

		else if(ptr->rt == NULL)
		{
			if(parent->rt == ptr)
				parent->rt = ptr->lf;
			else
				parent->lf = ptr->lf;
		delete(ptr);
		balance(parent);
		}

		//case 3 : Two children

		else
		{
			parent = ptr;
			node *temp;

			temp = ptr->rt;			//Go to right child
			while(temp->lf)			//Go to leftmost child
			{
				parent = temp;
				temp = temp->lf;
			}

			ptr->data = temp->data;
		//	ptr->meaning = temp->meaning;

			if(parent == ptr)
				ptr->rt = temp->rt;
			else
				ptr->lf = temp->rt;
		delete(temp);
		balance(parent);
		}
		cout << "\nNode is deleted!!";
	}
	else
		cout << "\nData not found....Cannot be deleted!!";
}


int main()
{
	AVLTree a;
	int ch, n;
	string val;
	node *root = new node;
	root = NULL;

	while(1)
	{
			cout <<"\n1.Insert data \n2.Display tree \n3.Search\n4.Exit";
			cout << "\nEnter choice : ";
			cin >> ch;
			switch(ch)
			{
			case 1: cout <<"Enter the no. of nodes you want to insert : ";
					cin >> n;
					for(int i=0; i<n; i++)
					{
						cout << "Enter the data to be inserted : ";
						cin >> val;
						root = a.insert(root ,val);
					}
					break;
			case 2: cout << "\nInorder display : ";
					a.Inorder(root);
					cout << "\nPreorder display : ";
					a.Preorder(root);
					cout << "\nPostorder display : ";
					a.Postorder(root);
					cout << endl;
					break;
			case 3: a.search();
					break;
			case 4:a.Delete(root);
				break; cout << "\n\nExit from program......";
					//return 0;
			}
	}
}
