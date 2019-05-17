/*Q.. Given an linked list modify same link list such that all element at odd place should
come first and even place element should added after that in reverse order.
eg. 1->2->3->4->-5
output:  1->3->5->4->2 */

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

void odd_even()
{
    struct Node *odd,*even,*ep,*t1,*temp3;
    if(head->next!=NULL)
    {
        odd=head;
        ep=head->next;      //ep points to previous even node .

        temp3=ep;
        t1=ep->next;

        while(1)
        {

            if(odd->next!=NULL)
            {
                if(t1!=NULL)
                {
                    odd->next=t1;
                    odd=odd->next;
                }
                else
                {
                    odd->next=ep;
                    break;
                }


            }
            else
            {
                break;
            }



            if(odd->next!=NULL)
            {
               even=odd->next;
                t1=even->next;
                even->next=ep;
                ep=even;
            }
            else
            {
                odd->next=ep;
                break;
            }
        }

        temp3->next=NULL;
    }

        display();
}
