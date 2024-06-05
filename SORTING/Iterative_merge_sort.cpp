// Time complexity = O(nlogn)

#include<iostream>
using namespace std;

int * merge(int A[], int low, int mid, int high)
{
    // Merges two sorted subarrays A[low..mid-1] and A[mid..high-1]
    int i = low, j = mid+1, k = low;
    int *B = new int[high]; // Temporary array to store merged subarray
    
    // Merge the two subarrays into B
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left subarray (if any)
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right subarray (if any)
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for(int i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
    
    return B; // Return merged array
}

int* IterativeMergeSort(int A[], int n)
{
    // Iteratively performs merge sort on array A of size n
    int p, i, low, mid, high;
    int *D;

    // Outer loop controls the size of subarrays to be merged
    for(p = 2; p <= n; p = p * 2)
    {
        // Inner loop controls the starting point of subarrays
        for(i = 0; i + p - 1 < n; i = i + p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            D = merge(A, low, mid, high); // Merge subarrays
        }
    }

    // If array size is odd, merge remaining elements
    if(p / 2 < n)
    {
        D = merge(A, 0, p / 2, n - 1);
    }

    return D; // Return sorted array
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size];

    // Input array elements from the user
    for(int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    // Perform iterative merge sort
    int *final = IterativeMergeSort(A, size);

    // Print sorted array
    for(int i = 0; i < size; i++)
    {
        cout << final[i] << " ";
    }

    return 0;
}
