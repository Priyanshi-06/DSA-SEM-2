// Time Complexity = O(n^2)

#include <iostream>
using namespace std;

void selection(int A[], int n)
{
    int j, k;
    for (int i = 0; i < n; i++) // This for loop is for passes
    {
        k = i; // Assume the first unsorted element is the smallest
        j = i + 1; // Start from the next element

        // Find the smallest element in the remaining unsorted array
        while (j < n)
        {
            if (A[j] < A[k])
            {
                k = j; // Update the index of the smallest element
            }
            j++;
        }

        // Swap the found minimum element with the first unsorted element
        int temp = A[i]; 
        A[i] = A[k];
        A[k] = temp;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    selection(A, size); // Call the selection sort function

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
