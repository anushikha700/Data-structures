#include<iostream> 
using namespace std;
int sum(int n); 
int main(){
    int num=0;
    cout<<"Enter a number : ";
    cin>>num;
    cout<<sum(num)<<endl;
    return 0 ;
}

int sum(int n ){
    if(n<=3){
        return n;
    }
    
    else
    {
        return sum(n-1)+sum(n-2)+sum(n-3);
    }
    
}