#include<iostream>
using namespace std;



int main()
{
    int t,count=0;
    cout<<"enter testcase:"<<endl;
    cin>>t;

    int p[t][4],q[50];
    for(int i=0;i<t;i++)
    {
       
        for(int j=0;j<4;j++)
        {
            cout<<"Enter number"<<endl;
            cin>>p[i][j];
        }

        for(int j=0;;j++)
        {
            cout<<"Enter no."<<endl;
            cin>>q[j];
            if(q[j]==0)
            {
                break;
            }
            count++;
           
        }
    

    for(int i=0;i<count-1;i++)
    {   
        
        int m=((q[i])*(p[i][2]));
        if(m>p[i][3])
        {
            p[i][1]=(p[i][1])-(p[i][3]);
        }

        else
        {
            
            p[i][1]=p[i][1]-(((q[i+1])-(q[i]))*(p[i][2]));
            
        }
        
    }
    
    }

    for(int i=0;i<t;i++)
    {
        if(p[i][1]<=0)
       {
        cout<<"NO"<<endl;
       }
    else
       {
        cout<<"YES"<<endl;
       }
    }
    
    

return 0;
}