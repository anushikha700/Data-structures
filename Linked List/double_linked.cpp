#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
}*head,*last;

void create(int n);
void display();
void ins_begin();
void ins_end();
void ins_middle();
void del_beg();
void del_end();
void del_mid();
void search_data();
void revers();
void del_alt();

int main()
{
    int ch,n,new_data;
    while(1)
    {
        cout<<"1.create list \n";
        cout<<"2.display\n";
        cout<<"3.add at beginning \n";
        cout<<"4.add at end \n";
         cout<<"5.add at middle\n ";
         cout<<"6.Delete at beginning\n";
         cout<<"7.Delete at end\n";
         cout<<"8.Delete in middle\n";
        cout<<"9.Search\n";
        cout<<"10.Reverse list\n";
        cout<<"11.delete alternate nodes\n";
      /*     cout<<"7.Count nodes\n";


      //
    //    */
        cin>>ch;

    switch(ch)
    {
    case 1:   cout<<"Enter the total number of nodes: ";
                cin>>n;
                create(n);
                break;
    case 2:   cout<<"\nData in the list : ";
                display();
                break;
    case 3:
                ins_begin();
                break;
    case 4:
                ins_end();
                break;
     case 5:     ins_middle();
                break;
    case 6:    del_beg();
                break;
    case 7:     del_end();
                break;
    case 8: del_mid();
                break;
    case 9:    search_data();
                break;
    case 10:     revers();
                break;
    case 11:    del_alt();
                break;
/*   case 7:    length();
                break;



 */
     default: cout<<"wrong value";
    }
    int ch2;
    cout<<"\ncontinue (1/0):";
    cin>>ch2;
    if(ch2==0)
    {
        break;
    }

    }

    return 0;
}

void create(int n)
{
    int new_data,i;
    head=new Node();
    cout<<"Enter data 1: ";
    cin>>new_data;
    head->data=new_data;
    head->prev=NULL;
    head->next=NULL;
    last=head;
    for(i=2;i<=n;i++)
    {
        struct Node * new_node ;
        new_node= new Node();
        cout<<"Enter data "<<i<<":";
        cin>>new_data;
        new_node->data=new_data;
        new_node->prev=last;
        new_node->next=NULL;

        last->next=new_node;
        last=new_node;

    }

}

void display()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        cout<<"list is empty\n";
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

void ins_begin()
{
    int new_data;
    cout<<"Enter data : ";
    cin>>new_data;
    struct Node *new_node, *temp=head;
    new_node=new Node();
    new_node->data=new_data;
    new_node->next=temp;
    new_node->prev=NULL;
    temp->prev=new_node;
    head=new_node;

    display();
}

void ins_end()
{
    int new_data;
    cout<<"Enter data : ";
    cin>>new_data;
    struct Node *new_node,*temp;

    new_node=new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    new_node->prev=last;
    last->next=new_node;
    last=new_node;

    display();
}

void ins_middle()
{
    int new_data,p;
    cout<<"Enter data : ";
    cin>>new_data;
    cout<<"Enter position : ";
    cin>>p;
    struct Node *new_node,*temp;

    new_node=new Node();
    new_node->data=new_data;
    temp=head;
    p=p-1;
    while(p--)
    {
        if(temp->next!=NULL)
        {
            temp=temp->next;
        }

    }
    new_node->next=temp;
    new_node->prev=temp->prev;
    temp->prev->next=new_node;

    temp->prev=new_node;

    display();


}

void del_beg()
{
    struct Node *temp;
    if(head->next!=NULL)
    {
        temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        delete temp;

    }
    else
    {
        head=NULL;
        delete head;
    }
    cout<<"After deleting : ";
    display();
}

void del_end()
{
    struct Node *temp=last;
    if(head->next!=NULL)
    {
        last=temp->prev;
        temp->prev=NULL;
        last->next=NULL;


        temp=NULL;
        delete temp;

    }
    else
    {
        head=NULL;
        delete head;
    }
    cout<<"After deleting : ";
    display();

}
void del_mid()
{
    int p;
    cout<<"Enter postion of node to be deleted: ";
    cin>>p;
    p=p-1;
    struct Node *temp=head;
    if(head==last)
    {
        head=NULL;
        delete head;

    }
    else if(last->next==NULL)
    {
        temp=last;
        last=temp->prev;
        temp->prev->next=NULL;
        delete temp;
    }
    else
    {
        while(p--)
        {
            if(temp->next!=NULL)
            {
                temp=temp->next;
            }
        }
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            temp->next=NULL;
            temp->prev=NULL;
            temp=NULL;
            delete temp;


    }
    cout<<"After deleting : ";
    display();

}

void search_data()
{
    int d;
    cout<<"Enter node to be searched : ";
    cin>>d;
    int p=1;
    struct Node *temp=head;
    while(temp->data!=d)
    {
        temp=temp->next;
        p++;
    }
    cout<<"position of "<<d<<" is index"<<p;
}

void revers()
{
    struct Node *temp,*temp2;
    if(head!=NULL)
    {

        temp=head;
        temp2=head;
        head=head->next;
        temp->prev=temp->next;
        temp->next=NULL;

        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            temp->prev=temp->next;
            temp->next=temp2;
            temp2=temp;

        }
        head=temp;


    }
    cout<<"List is reversed : ";
    display();
}

void del_alt()
{
    struct Node *temp,*temp2,*temp3;
    if(head==last)
    {
        head=NULL;
        delete head;
    }
    else
    {
        temp=head;
        temp2=head->next;

        while(temp!=NULL&&temp2!=NULL)
        {
            temp->next=temp2->next;
            temp3=temp2->next;
            delete temp2;
            if(temp3)
            {
                temp3->prev=temp;
                temp2=temp3->next;
            }
            else
            {
                temp2=NULL;
                delete temp2;
            }
            temp=temp3;
        }

    }
    cout<<"After deleting : ";
    display();
}
