#include<iostream>
using namespace std;

int hash1(int key)
{
    return key%10;
}

int hash2(int key)
{
    return 7-(key%7);
}

int hash(int key,int H[])
{
    int h1=hash1(key);
    int h2=hash2(key);
    int i=0;
    while(H[(h1+i*h2)%10]!=0)
    {
        i++;
    }
    return (h1+i*h2)%10;
}


void Insert(int H[],int key)
{
    int index=::hash(key,H);
    H[index]=key;
}

void display(int H[])
{
    for(int i=0;i<10;i++)
    {
        cout<<"H["<<i<<"]: "<<H[i]<<" ";
        cout<<endl;
    }
    
}

int search(int H[],int key)
{
    int index=::hash(key,H);

    int i=0;
    while(H[(index+i)%10]!=key)
    i++;
    return (index+i)%10;
}

int main()
{
    int HT[10]={0};
    Insert(HT,5);
    Insert(HT,25);
    Insert(HT,15);
    Insert(HT,35);
    Insert(HT,95);
    // Insert(HT,33);
    // Insert(HT,43);
    // Insert(HT,42);
    display(HT);
   cout<<"key found at : "<<search(HT,40)<<endl;

return 0;
}