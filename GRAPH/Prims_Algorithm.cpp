#include<iostream>
#define T 32767
using namespace std;

int near[8]{T};
int t[2][6];

void printMST(int t[][6],int cost[8][8])
{
    cout<<"Minimum Spanning Tree Edges : "<<endl;
    int sum=0;
    
    for(int i=0;i<6;i++)
    {
        int c=cost[t[0][i]][t[1][i]];
        cout<<"["<<t[0][i]<<"]---["<<t[1][i]<<"] cost : "<<c<<endl;
        sum=sum+c;
    }
    cout<<endl;
    cout<<"Total cost of MST : "<<sum<<endl;
}

void primsMST(int cost[][8],int n)
{
    int i,j,k,u,v,min=T;

    //Finding minimum value using upper triangular
    for(i=1;i<n;i++) //for row
    {
        near[i]=T;
        for(j=i;j<n;j++) //for column
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }

    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;

    for(i=1;i<n;i++) //compare the value and put the small value in near array
    {
        if(near[i]!=0)
        {
        if(cost[i][u]<cost[i][v])
        near[i]=u;
        else
        near[i]=v;
        }
    }


    //Repeating condition 

    for(i=1;i<n-2;i++) // fill the 2D array
    {
        min=T;

        for(j=1;j<n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min) //find the minimum value so that 2nd column of 2D array will fill by this value
            {
                min=cost[j][near[j]];
                k=j;
            }
        }

        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;

        for(j=1;j<n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
            {
                near[j]=k;
            }
        }

    }
    printMST(t,cost);
}

int main()
{
    int cost[8][8]={{T,T,T,T,T,T,T,T},
                    {T,T,25,T,T,T,5,T},
                    {T,25,T,12,T,T,T,10},
                    {T,T,12,T,8,T,T,T},
                    {T,T,T,8,T,16,T,14},
                    {T,T,T,T,16,T,20,18},
                    {T,5,T,T,T,20,T,T},
                    {T,T,10,T,14,18,T,T}};

                
  
 primsMST(cost,8);

    
return 0;
}