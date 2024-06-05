#include <iostream>
#define T 32767
using namespace std;

int set[8]{-1};
    int included[9]{0};
    int t[2][6];

void Union(int u,int v)
{
    if(set[u]<set[v])
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else
    {
        set[v]=set[u]+set[v];
        set[u]=v;
    }
}

int find(int u)
{
    int x=u;
    int v=0;

    while(set[x]>0)
    {
        x=set[x];
    }

    while(u!=x)
    {
        v=set[u];
        set[u]=x;
        u=v;
    }

    return x;
}

void PrintMCST(int edges[][9],int n)
{
    cout<<"Minimum Cost Spanning Tree Edeges : "<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<"["<<t[0][i]<<"]---["<<t[1][i]<<"]"<<endl;
    }
    cout<<endl;
}

void Kruskal(int edges[][9],int n)
{
    int i=0,j,k,e=9,min,u,v;
    while(i<6)
    {
        min=T;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min=edges[2][j];
                k=j;
                u=edges[0][j];
                v=edges[1][j];
            }
        }

        if(find(u)!=find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
            Union(find(u),find(v));
            i++;
        }

        included[k]=i;
    }

    PrintMCST(edges,9);
}
int main()
{
    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
                    
    Kruskal(edges,3);
    return 0;
}