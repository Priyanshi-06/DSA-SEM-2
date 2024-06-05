#include<iostream>
#include<string>
using namespace std;
/*Polycarpus has n friends in Tarasov city. Polycarpus knows phone numbers of all his friends: they are strings s1, s2, ..., sn. All these strings consist only of digits and have the same length.

Once Polycarpus needed to figure out Tarasov city phone code. He assumed that the phone code of the city is the longest common prefix of all phone numbers of his friends. In other words, it is the longest string c which is a prefix (the beginning) of each si for all i (1 ≤ i ≤ n). Help Polycarpus determine the length of the city phone code.

Input
The first line of the input contains an integer n (2 ≤ n ≤ 3·104) — the number of Polycarpus's friends. The following n lines contain strings s1, s2, ..., sn — the phone numbers of Polycarpus's friends. It is guaranteed that all strings consist only of digits and have the same length from 1 to 20, inclusive. It is also guaranteed that all strings are different.

Output
Print the number of digits in the city phone code.

Examples
inputCopy
4
00209
00219
00999
00909
outputCopy
2
inputCopy
2
1
2
outputCopy
0
inputCopy
3
77012345678999999999
77012345678901234567
77012345678998765432
outputCopy
12

int main()
{
    int n;
    cin>>n;

    string phone[n];

    for(int i=0;i<n;i++)
    {
        cin>>phone[i];
    }





return 0;
}*/

struct equal
{
    int n;
    int arr[];
};

int main()
{
    int t;
    cin>>t;

    struct equal arr1[t];

    for(int i=0;i<t;i++)
    {
        cin>>arr1[i].n;
        cin>>arr1.arr[];
    }




}