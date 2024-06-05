// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the size of array : ";
//     cin>>n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//     {
//         cout<<"Enter the element of arr["<<i<<"] : "<<endl;
//         cin>>arr[i];
//     }

//     int index;
//     cout<<"Enter the place where you want to insert the element : ";
//     cin>>index;

//     int data;
//     cout<<"Enter the value which you want to insert : ";
//     cin>>data;

//     for(int i=0;i<n;i++)
//     {
//         if(i==index && arr[i]==0)
//         {
//             arr[i]=data;
//         }

//         else
//         {
//             int j=0;
//             while(j!=n-1)
//             {
//                 if(arr[j]==0)
//                 {
//                     arr[j]=arr[j+1];
//                     j++;
//                 }

//                 else
//                 {
//                     j++;
//                 }
//             }

            
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int k;
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int u = 9;
    if (arr[9] != '\0')
    {
        cout << "arr is full.we can not insert ";
    }
    else
    {
        for (k = 0; arr[k] != '\0'; k++)
        {
        }
        cout << "array last number at index:" << k - 1 << endl;
        int location;
        cout << "enter that loction(index) in you want to isert a element:";
        cin >> location;
        int isertnum;
        cout << "enter that number you want to add";
        cin >> isertnum;
        int i = k;
        while (i > location)
        {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[i] = isertnum;
    }
    for (int i = 0; i <= k; i++)
    {
        cout << arr[i] << endl;
    }
}