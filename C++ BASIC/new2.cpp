#include<iostream>
using namespace std;

int main()
{
    int t;
    cout << "Enter testcase:" << endl;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++)
    {
        int p[4], q[50];
        cout << "Enter 4 numbers for test case " << test_case + 1 << ":" << endl;
        for(int i = 0; i < 4; i++)
        {
            cout << "Enter number " << i+1 << ": ";
            cin >> p[i];
        }

        cout << "Enter numbers for q, terminate with 0:" << endl;
        int count = 0;
        for(int i = 0; ; i++)
        {
            cout << "Enter number " << i+1 << ": ";
            cin >> q[i];
            if(q[i] == 0)
                break;
            count++;
        }

        int total_damage = 0;
        for(int i = 0; i < count; i++)
        {
            int m = q[i] * p[2];
            if(m > p[3])
                p[1] -= p[3];
            else
                p[1] -= (q[i+1] - q[i]) * p[2];
            if(p[1] <= 0)
                break;
        }

        if(p[1] <= 0)
            cout << "Test case " << test_case + 1 << ": NO" << endl;
        else
            cout << "Test case " << test_case + 1 << ": YES" << endl;
    }
    
    return 0;
}