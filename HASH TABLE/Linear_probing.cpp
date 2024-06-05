#include<iostream>
using namespace std;

int hash(int key)
{
    return key%10;
}

int probe(int H[],int key)
{
    int index=::hash(key);
    int i=0;
    while(H[index+i]%10!=0)
    {
        i++;
    }
    return (index+i)%10;


}
void Insert(int H[],int key)
{
    int index=probe(H,key);
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
    int index=::hash(key);

    int i=0;
    while(H[(index+i)%10]!=key)
    i++;
    return (index+i)%10;
}

int main()
{
    int HT[10]={0};
    Insert(HT,12);
    Insert(HT,13);
    Insert(HT,23);
    Insert(HT,22);
    Insert(HT,32);
    Insert(HT,33);
    Insert(HT,43);
    Insert(HT,42);
    display(HT);
    cout<<"key found at : "<<search(HT,12)<<endl;

return 0;
}