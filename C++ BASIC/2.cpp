#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    string str;
    cout<<"enter string:";
    cin>>str;

    int count=0;
    
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i+1;str[j]!='\0';j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
        }
    }

    int length1=str.length();
    int length2=length1-count;

    if(length2%2==0)
    {
        cout<<"CHAT WITH HER!";
    }

    else
    {
        cout<<"IGNORE HIM!";
    }

    return 0;
}