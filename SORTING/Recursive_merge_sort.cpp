#include<iostream>
using namespace std;

// Function to merge two sorted halves of an array
void sorted_array(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low; // Initialize pointers for merging

    int *B = new int[high + 1]; // Create a new array to hold the merged elements

    // Merge elements from the two sorted halves of the array
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i]; // Add element from the first half
            i++;
        }
        else
        {
            B[k] = A[j]; // Add element from the second half
            j++;
        }
        k++;
    }

    // If there are remaining elements in the first half, add them to B
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // If there are remaining elements in the second half, add them to B
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    // Copy the merged elements back into the original array
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }

    delete[] B; // Free the dynamically allocated memory
}

// Recursive function to perform merge sort on an array
void Rmerge_sort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2; // Find the midpoint
        Rmerge_sort(A, low, mid); // Recursively sort the first half
        Rmerge_sort(A, mid + 1, high); // Recursively sort the second half
        sorted_array(A, low, mid, high); // Merge the two sorted halves
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size]; // Dynamically allocate memory for the array

    // Input the elements of the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    Rmerge_sort(A, 0, size - 1); // Sort the array using merge sort

    // Output the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[] A; // Free the dynamically allocated memory
    return 0;
}
