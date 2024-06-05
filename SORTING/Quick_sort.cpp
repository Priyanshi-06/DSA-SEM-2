// Quick sort works when the list has at least two elements

#include <iostream>
#include <algorithm>
using namespace std;

int partition(int A[], int n, int p)
{
    int pivot = A[p]; // Choose the pivot element
    int i = p, j = n; // Initialize pointers

    do
    {
        // Increment i until an element greater than the pivot is found
        do
        {
            i++;
        } while (A[i] <= pivot); // Use condition of j to move forward when condition is false

        // Decrement j until an element less than or equal to the pivot is found
        do
        {
            j--;
        } while (A[j] > pivot);

        // Swap elements at i and j if i is less than j
        if (i < j)
        {
            swap(A[i], A[j]);

            // Alternative swapping code
            // int temp = A[i];
            // A[i] = A[j];
            // A[j] = temp;
        }

    } while (i < j);

    // Swap pivot element with the element at j
    swap(A[p], A[j]);
    // Alternative swapping code
    // int temp = A[p];
    // A[p] = A[j];
    // A[j] = temp;

    return j; // Return the partition index
}

void Quicksort(int A[], int high, int low)
{
    if (low < high)
    {
        // Partition the array and get the partition index
        int j = partition(A, high, low);

        // Recursively sort the left part
        Quicksort(A, j, 0); // j acts as the boundary for the left part

        // Recursively sort the right part
        Quicksort(A, high, j + 1); // Sort the right part from j+1 to high
    }
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *A = new int[size];

    // Input array elements from the user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    int p;
    cout << "Enter the index of pivot: ";
    cin >> p;

    // Print the index of the pivot after partitioning
    cout << "Pivot at index: " << partition(A, size, p) << endl;

    // Call the quicksort function
    Quicksort(A, size, p);

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
