#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
node* midpoint(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;

    }
    node*slow=head;
    node*fast =head->next;
    while(fast!= NULL && fast->next!= NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void insertAtTAil(node* &head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }tail->next =new node(data);
    return;
}
void buildList(node* &head,int n)
{
    int data,counter=0;
    cin>>data;
    while(counter!=n)
    {
        insertAtTAil(head,data);
        cin>>data;
        counter++;

    }

}
int main() {

    int n,flag=1;
    cin>>n;
    node*head=NULL;
    buildList(head,n);

    node*rtemp=midpoint(head);
    node*c=rtemp;
    node* p=NULL;
    node*x;
    while(c!=NULL)
    {
        x=c->next;
        c->next=p;
        p=c;
        c=x;
    }rtemp=p;
    rtemp=rtemp->next;
    while(rtemp!=NULL)
    {   
        //compare 
        if(head->data==rtemp->data)
        {
            head=head->next;
            rtemp=rtemp->next;
        }
        else
        {
            flag=0;
            break;
        }
    }//cout<<flag;
    return 0;
}