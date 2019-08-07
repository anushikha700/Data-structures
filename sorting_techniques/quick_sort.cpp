#include<iostream>
using namespace std;

int part(int a[],int p, int r)
{
    int temp;
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {

            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }

    }

    int temp1=a[i+1];
    a[i+1]=a[r];
    a[r]=temp1;

    return i+1;


}

void quicksort(int a[],int p, int r,int n)
{
    for(int i=1;i<=n;i++)     /* for output of array at every iteration */
    {
        cout<<a[i];
    }
    cout<<endl;
    if(p<r)
    {
        int q=part(a,p,r);
        quicksort(a,p,q-1,n);
        quicksort(a,q+1,r,n);

    }



}



int main()
{
    int n,i;
    cout<<"enter n: ";
    cin>>n;
    int a[n];
    cout<<"Enter array : ";
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int p=1,r=n;

    quicksort(a,p,r,n);
    cout<<"Sorted array : "
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;

    return 0;

}
