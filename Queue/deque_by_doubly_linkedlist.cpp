#include<iostream>
#include<string>
using namespace std;

class node
{   public:
	int prn;
	string name;
	node *next;
    node *prev;
};

class list
{   private:node *nn;
	public: node *front;  //IMPORTANT
            node *rear;   //IMPORTANT

	list()
	{
		front=rear=NULL;
	}
	void insert_front()
	{
		nn=new node;
		cout<<" Enter the name of member ";
		cin>>nn->name;
		cout<<" Enter the prn number ";
		cin>>nn->prn;
        nn->next=nn->prev=NULL;

		if(front==NULL && rear==NULL)
		{
			front=rear=nn;
		}
		else
		{   nn->next=front;
            front->prev=nn;
            front=nn;
		}
	}
	void insert_rear()
	{
		nn=new node;

		cout<<" Enter the name of member ";
		cin>>nn->name;
		cout<<" Enter the prn number "<<endl;
		cin>>nn->prn;
		nn->next=nn->prev=NULL;  //IMPORTANT

        if(front==NULL && rear==NULL)
        {
            front=rear=nn;
        }
        else
        {
            rear->next=nn;
            nn->prev=rear;
            rear=nn;  //IMPORTANT
        }
    }
    void delete_front()
    {
        if(front==NULL)
            cout<<"\nQueue is empty.";
        else if(front==rear)
            front=rear=NULL;
        else
        {
         front=front->next;
        }
    }
    void delete_rear()
    {   if(rear==NULL)
        cout<<"\nQueue is empty.";
        else if(front==rear)
            front=rear=NULL;
        else
        {   rear=rear->prev;
            rear->next=NULL; //IMPORTANT
        }
    }
	void put()
	{   node *temp;
	    cout<<" The linked list is : "<<endl;
		temp=front;
		do
		{
			cout<<temp->name<<"\t";
			cout<<temp->prn<<endl;
			temp=temp->next;
		}while(temp!=NULL);
	}
};

int main()
{	list l1;
	int ch;
	char z;

	cout<<"\n**********DQUEUE BY DOUBLY LINK LIST***********\n";
	do
{
	cout<<" \nEnter\n1.Insert element at Front.\n2.Insert element at Rear.\n3.Delete element at Front.\n4.Delete element at Rear.\n5.To display whole queue :"<<endl;
	cin>>ch;
	switch(ch)
	{
            case 1:l1.insert_front();
            break;

            case 2:l1.insert_rear();
            break;

			case 3:l1.delete_front();
            break;

			case 4:l1.delete_rear();
            break;

            case 5:l1.put();
            break;

            default :cout<<" !!!!SORRY!!!! ";
			break;


	}cout<<" \nEnter y for another operation else n :"<<endl;
	 cin>>z;

}while(z=='y' || z=='Y');

}