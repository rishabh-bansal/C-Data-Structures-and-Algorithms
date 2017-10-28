
#include <iostream>
using namespace std;

struct node
{
     int data;
     struct node * next;
};

struct qu
{
    struct node *f;
    struct node *r;
};
void initialise(struct qu* q)
{  q->f=q->r=NULL;

}

void create(struct qu *q,int item)
{
    struct node *newnode;
    newnode =new node;
    if(newnode==NULL)
        cout<<"queue is full";
    newnode->data=item;
    newnode->next=NULL;

    if(q->f==NULL)
    {
        q->f=q->r=newnode;
    }
    q->r->next=newnode;
    q->r=q->r->next;
}

void deleted(struct qu*q)
{  //cout<<"yes";
    if(q->f == NULL)
        cout<<"empty";
         // cout<<"yes";
        // struct node *temp;
      //   temp = q->f;
         q->f=q->f->next;


        if(q->f==NULL)
            q->r=NULL;





}

void display(struct qu *q)
{
    if(q->f==NULL)
        cout<<"empty";
    else
    {
        struct node * temp;
        while(q->f!=NULL)
        {   //temp=q->f;
            cout<<q->f->data<<"\n";
            q->f=q->f->next;
        }
         //cout<<q->f->data<<"\n";
    }

}

int main()
{
    struct qu q;

    int n,i,j;
    cin>>n;
    initialise(&q);
    for(i=0;i<n;i++)
    {
        cin>>j;
        create(&q,j);
            }
display(&q);
deleted(&q);
cout<<"\n";
display(&q);

}


