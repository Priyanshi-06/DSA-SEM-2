#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void BFS(int i, int A[][8], int n)
{
    static int visited[8]{0};
    int u;
    cout << "Vertex : " << i << " -> ";
    visited[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
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

    BFS(1, A, 8);

    return 0;
}