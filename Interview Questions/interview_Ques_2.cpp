/*Given a singly linked list of size N, and an integer K,
you need to swap the Kth node from beginning and Kth node from end in linked list. */

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
void odd_even();




int main()
{
    int ch,n,new_data,data;
    while(1)
    {
        cout<<"1.create list \n";
        cout<<"2.display\n";
        cout<<"3.odd-even list\n";

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
    case 3:    odd_even();
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

void swap_node()
{
    int num,K;
    cout<<"Enter size of Linked list and Kth node to be swapped : ";
    cin>>num>>K;

    struct Node *t1=head,*t2=head,*temp ,*p1=NULL,*p2=NULL;

    if (num < K || 2*K-1==num)
        return  ;
    for (int i = 1; i < K; i++)
    {
        p1=t1;
        t1=t1->next;
    }
    cout<<"t1->data = "<<t1->data;
    for (int i = 1; i<num-K+1; i++)
    {
        p2=t2;
        t2=t2->next;
    }
    cout<<"t2->data = "<<t2->data;
    if(p1)
    {
        p1->next=t2;
    }
    if(p2)
    {
        p2->next=t1;
    }


    temp=t1->next;

    t1->next=t2->next;
    t2->next=temp;

    if (K == 1)
        head = t2;
    if (K == num)
        head = t1;
    display();
}
