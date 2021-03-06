#include <iostream>
using namespace std;

/* Structure of a node */
struct Node
{
    int data;          // Data
    struct Node *next; // Address
}*head;


/*
 * Functions to create and display list
 */
void create(int n);
void display();
void ins_begin(int  new_data);
void ins_end(int new_data);
void ins_middle(int new_data);
void search_data(int data);
void length();
void revers();
void del_beg();
void del_end();
void del_mid();



int main()
{
    int ch,n,new_data,data;
    while(1)
    {
        cout<<"1.create list \n";
        cout<<"2.add at beginning \n";
        cout<<"3.add at end \n";
        cout<<"4.add at middle\n ";
        cout<<"5.display\n";
        cout<<"6.Search\n";
        cout<<"7.Count nodes\n";
        cout<<"8.Reverse list\n";
        cout<<"9.Delete at beginning\n";
        cout<<"10.Delete at end\n";
        cout<<"11.Delete in middle\n";
        cin>>ch;

    switch(ch)
    {
    case 1:   cout<<"Enter the total number of nodes: ";
                cin>>n;
                create(n);
                break;
    case 2:
                ins_begin(new_data);
                break;
    case 3:
                ins_end(new_data);
                break;
    case 4:     ins_middle(new_data);
                break;
     case 5:   cout<<"\nData in the list : ";
                display();
                break;
    case 6:    search_data( data);
                break;
    case 7:    length();
                break;
    case 8:     revers();
                break;
     case 9:    del_beg();
                break;
     case 10:  del_end();
                break;
     case 11: del_mid();
                break;
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
    struct Node *newNode, *temp;
    int data, i;

    head = new Node();

    if(head == NULL)

    {
        cout<<"Unable to allocate memory.";
        exit(0);
    }



    cout<<"Enter node 1: ";
    cin>>data;

    head->data = data;
    head->next = NULL;



    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = new Node();

\
        if(newNode == NULL)
        {
            cout<<"Unable to allocate memory.";
            break;
        }

        cout<<"Enter node  "<<i<<" : " ;
        cin>>data;
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
}


void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        cout<<"List is empty.";
        return;
    }
    else
    {
        cout<<"\nList : ";
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

    }
}

void ins_begin(int new_data)
{
    struct Node *temp,*newNode;
    cout<<"Enter data: ";
    cin>>new_data;
    if(head==NULL)
    {
        cout<<"cannot add, list is empty ";
    }
    else
    {
        newNode=new Node();
        newNode->data=new_data;
        newNode->next=head;
        head=newNode;
    }
}

void ins_end(int new_data)
{
    struct Node *temp,*new_node;
    cout<<"Enter data: ";
    cin>>new_data;
    if(head==NULL)
    {
        cout<<"cannot add ,list is empty ";
    }

    else
    {
        temp=head;
        new_node=new Node();
        new_node->data=new_data;
        new_node->next=NULL;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;


    }
}

void ins_middle(int new_data)
{
    struct Node *temp,*new_node;

    int p=1,pos;
    cout<<"Enter position where you want to enter node: ";
    cin>>pos;
    cout<<"Enter data: ";
    cin>>new_data;
    if(head ==NULL)
    {
        cout<<"Cannot add list is empty ";
    }
    else
    {
        temp=head;
        new_node=new Node();
        new_node->data=new_data;
        while(p!=pos-1)
        {
            temp=temp->next;
            p++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }

}

void search_data(int data)
{

    struct Node *temp;
    cout<<"Enter data you want to search: ";
    cin>>data;
    int p=1;
    temp=head;
    while(temp->data!=data)
    {
        temp=temp->next;
        p++;
    }
    cout<<data<<" is at node "<<p;


}
void length()
{
    struct Node *temp;
    int p=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        p++;
    }
    cout<<"Number of nodes : "<<p;

}

//https://codeforwin.org/2015/09/c-program-to-reverse-singly-linked-list.html
void revers()
{
    struct Node *prev , *cur;

    if(head !=NULL)
    {
        prev=head;
        cur=head->next;
        head=head->next;
        prev->next=NULL;
        while(head!=NULL)
        {
            head=head->next;
            cur->next=prev;
            prev=cur;

            cur=head;
        }
        head=prev;
    }
    cout<<"List is reversed.";
    display();
}

void del_beg()
{
    struct Node *temp;
    temp=head;
    head=head->next;
    delete temp;
    cout<<"Node is deleted\n";
    display();
}
void del_end()
{
    struct Node *temp ,*temp2;
    temp=head;
    temp2=head;
    if(head->next!=NULL)
    {
        while(temp->next!=NULL )
        {
            temp=temp->next;
        }

        while(temp2->next!=temp)
        {
            temp2=temp2->next;
        }
        temp2->next=NULL;
        delete temp;

    }
    else
    {
        head=NULL;
        delete head;
    }

    cout<<"Node is deleted\n";
    display();
}

void del_mid()
{
    struct Node *temp,*prev,*cur;
    int pos,p=1;
    cout<<"Enter the position of node you want to delete: ";
    cin>>pos;
    temp=head;
    prev=head;
    if(head->next!=NULL)
    {
        while(p!=pos)
        {
            temp=temp->next;
            p++;
        }
        while(prev->next!=temp)
        {
            prev=prev->next;
        }
        prev->next=temp->next;
        delete temp;

    }
    else
    {
        head=NULL;
        delete head;
    }

    cout<<"Node is deleted\n";
    display();

}
