#include<iostream>
using namespace std;

//Time Complexity = O(n)
//Space complexity = O(n) because of creating stack
//Recursive Function

int sum(int n)
{
    if(n==0)
    {
        return 0;
    }

    else 
    return sum(n-1)+n;
}


//Time Complexity = O(n)
//Space Complexity = O(1) 
//Iterative Function

int Isum(int n)
{
    int sum=0;

    for(int i=1;i<=n;i++)
    {
        sum=sum+i;
    }

    return sum;
}

int main()
{
    int x;
    cout<<"Enter the number of positive numbers : ";
    cin>>x;

    cout<<"Sum (Recursion) : "<<sum(x)<<endl;
    cout<<"Sum (Iterative) : "<<Isum(x)<<endl;

return 0;
}