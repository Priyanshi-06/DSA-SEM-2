#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

void DFS(int i,int A[][8],int n)
{
    static int visited[8]{0};

    if(visited[i]==0)
    {
        cout<<"Vertex : "<<i<<" -> ";
        visited[i]=1;
        s.push(i);

        while(!s.empty())
        {
            int u=s.top();
            s.pop();

            for(int v=1;v<n;v++)
            {
                if(A[u][v]==1 && visited[v]==0)
                {
                    visited[v]=1;
                    cout<<v<<" ";
                    s.push(v);
                    u=v; //update the value of u
                }
            }
        }
    }

    

}

int main()
{
     int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    DFS(4, A, 8);

return 0;
}