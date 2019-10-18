#include<iostream>
using namespace std;
void insert_first(string d);
void insert_last(string d);
void insert_middle(string d);

class node{
	public:
	string data;
	node*next;
};
node*head=NULL;
void display();
int main()
{
	insert_first("A");
	insert_first("B");
	cout<<"insertfirst:"<<" ";
	display();
	cout<<"\n";
	insert_last("C");
	insert_last("D");
	cout<<"insert_last:"<<" ";
	display();
	cout<<"\n";
	insert_middle("F");
	insert_middle("G");
	cout<<"insert_middle:"<<" ";
	display();
	return 0;
}
void insert_first(string d)
{
	node*newnode;
	newnode=new node;
	newnode->data=d;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else{
		newnode->next=head;
		head=newnode;
	}
	
}
void insert_last(string d)
{
	node*newnode;
	newnode=new node;
	newnode->data=d;
	newnode->next=NULL;
	node*t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=newnode;
}
void insert_middle(string d)
{
		node*newnode;
	newnode=new node;
	newnode->data=d;
	newnode->next=NULL;
	node*t=head;
	string dd="A";
	while(t->data!=dd)
	{
		t=t->next;
	}
	newnode->next=t->next;
	t->next=newnode;
}
void display()
{
	node*t=head;
	while(t!=NULL)
	{
		cout<<t->data<<"-->";
		t=t->next;
	}
	cout<<"Null";
}
