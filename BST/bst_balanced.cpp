//Program to convert array into balanced binary search tree.

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
void inorder(Node *root)        //function to display BST in inorder.
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* newnode(int key)              // function to create new Node
{
    Node *root= new Node;
    root->data=key;
    root->left=NULL;
    root->right=NULL;
    return root;
}
void balance(int a[], int low, int high, Node *&root)
{
    if(low>high)
        return ;
    int mid = (low+high)/2;
    root = newnode(a[mid]);
    balance(a,low,mid-1,root->left);
    balance(a,mid+1,high,root->right);
}





Node* balance(int a[], int n)
{
    sort(a,a+n);
    Node *root=NULL;
    balance(a,0,n-1,root);
    return root;
}




int main()
{
    int n;
    cin>>n;
    int a[n];
    for( int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    Node* root = balance(a, n);
    inorder(root);
    return 0;
}

