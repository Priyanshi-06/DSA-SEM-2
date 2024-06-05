#include <iostream>
using namespace std;

void insert(int arr[],int n);

void merge(int arr1[],int arr2[],int n1,int n2);

int main()
{
   int n1,n2;

   cout<<"Enter the number of element in 1st array:";
   cin>>n1;

   cout<<"Enter the number of element in 2nd array:";
   cin>>n2;

   int arr1[n1];
   int arr2[n2];

   if(n1==0 && n2==0)
   {
    cout<<"Both array are empty";
   }
   
   else
   {
    cout<<"Enter the value of 1st array's element:"<<endl;
    insert(arr1,n1);

    cout<<"Enter the value of 2nd array's element:"<<endl;
    insert(arr2,n2);
    
    merge(arr1,arr2,n1,n2);

   }

    
    return 0;
}

void insert(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void merge(int arr1[],int arr2[],int n1,int n2)
{
    int m[n1+n2];

    if((n1!=0 && n2!=0)||(n1!=0 && n2==0))
    {
        for(int i=0;i<n1;i++)
        {
           m[i]=arr1[i];
        }

        for(int i=n1;i<n1+n2;i++)
        {
            m[i]=arr2[i-n1];
        }
    }

    if(n1==0 && n2!=0)
    {
        for(int i=0;i<n2;i++)
        {
            m[i]=arr2[i];
        }
    }

    for(int i=0;i<n1+n2;i++)
    {
        cout<<m[i]<<endl;
    }


}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, m;
//     cout << "Enter size of first array:";
//     cin >> n;
//     cout << "Enter size of second array:";
//     cin >> m;
//     int arr[n], arr1[m];
//     if (n == 0 && m == 0)
//     {
//         cout << "Both array are empty!";
//     }
//     else
//     {

//         if (n != 0)
//         {
//             cout << "Enter element of array 1:" << endl;
//             for (int i = 0; i < n; i++)
//             {
//                 cin >> arr[i];
//             }
//         }
//         if (m != 0)
//         {
//             cout << "Enter element of array 2:" << endl;
//             for (int i = 0; i < m; i++)
//             {
//                 cin >> arr1[i];
//             }
//         }

//         int finalarr[n + m];
//         for (int i = 0; i < n; i++)
//         {
//             finalarr[i] = arr[i];
//         }
//         for (int i = n, k = 0; k < m; i++, k++)
//         {
//             finalarr[i] = arr1[k];
//         }
//         cout << "After merging:";
//         for (int i = 0; i < n + m; i++)
//         {
//             cout << finalarr[i] << " ";
//         }
//     }
//     return 0;
// }