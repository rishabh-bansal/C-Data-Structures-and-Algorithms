#include<iostream>
using namespace std;
#define SIZE 5

struct queue
{
    int front;
    int rear;
    int arr[SIZE];
}Q;

class simple
{
private:
public:int i;
    int Qempty()
    {
        if((Q.front==-1) ||(Q.front>Q.rear))
            return 1;

        else
            return 0;
    }

    int Qfull()
    {
        if(Q.rear>=SIZE-1)
           { return 1;
           }
        else
		{return 0;
		}
    }

    void insert_rear( int x )
    {
        if(Qfull()==1)
        {   cout<<"\n Queue is full.";

        }
        else
        {
            if(Qempty()==1)
            {
                Q.front=0;  //Initial condition
            }

                Q.arr[++Q.rear]=x;

        }
    }
    void delete_rear()
    {
        if(Qempty()==1)
        {
            cout<<"\nQueue is empty.";
        }
        else
        {
            cout<<"\nDeleted element is :"<<Q.arr[Q.rear]<<endl;
            Q.rear--;
        }
    }
    void insert_front(int x)
    {
        if(Qfull()==1)
        {
            cout<<"\nQueue is full.";
        }
        else
        {
            if(Qempty()==1) //if Q.front==-1 && Q.rear==-1;
            {
                Q.front=0;
            }

            i=Q.rear;
            while(i>=Q.front)
            {
                Q.arr[i+1]=Q.arr[i];
                i--;
            }
            Q.arr[Q.front]=x;
            Q.rear++;
         }
    }
    void delete_front()
    {
        if(Qempty())
        {
            cout<<"\nQueue is empty.";
        }
        else
        {
            int x=Q.arr[Q.front];
            cout<<"\nDeleted element is :"<<x;
            Q.front++;
        }
    }


    void displayall()
    {
    	cout<<"\nAll elements of queue are :";
                for(int i=Q.front;i<=Q.rear;i++)
                {
            		cout<<Q.arr[i]<<"\t";
                }
    }

};

int main()
{
    Q.front=Q.rear=-1;
    simple s1;
    int item,ch;
    char z;

    cout<<"\n*****DEQUE (DOUBLY ENDED) QUEUE*****\n";

    do
    {
        cout<<"\nEnter ";
        cout<<"\n1.To insert element in Queue from Rear ";
        cout<<"\n2.To delete element from Queue from Rear"; //IMPORTANT
        cout<<"\n3.To Insert element in Queue from Front";  //IMPORTANT
        cout<<"\n4.To delete an element from Queue from Front";
        cout<<"\n5.To display whole queue :";
        cin>>ch;

        switch(ch)
        {
            case 1:	cout<<"\nEnter the number you want to insert :";
            		cin>>item;
					s1.insert_rear(item);
            break;

            case 2:s1.delete_rear();
            break;

            case 3: cout<<"\nEnter the number you want to insert :";
            		cin>>item;
                    s1.insert_front(item);
            break;

            case 4: s1.delete_front();
            break;

            case 5: s1.displayall();
            break;

            default:cout<<"\nSORRY";
            break;

        }cout<<"\nEnter Y to cintinue else N :";
         cin>>z;
    }while(z=='Y'||z=='y');
    return 0;
}