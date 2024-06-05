// Merge two sorted lists into another sorted list
// Time Complexity = O(size1 + size2)

#include <iostream>
using namespace std;

void merge_two_list(int A[], int size1, int B[], int size2)
{
    int i = 0, j = 0, k = 0; // Initialize pointers for A, B, and C
    int *C = new int[size1 + size2]; // Create a new array to hold the merged elements

    // Merge elements from both arrays until one of them is exhausted
    while (i < size1 && j < size2)
    {
        if (A[i] < B[j]) // If current element in A is less than current element in B
        {
            C[k] = A[i]; // Add element from A to C
            i++;
        }
        else // If current element in B is less than or equal to current element in A
        {
            C[k] = B[j]; // Add element from B to C
            j++;
        }
        k++;
    }

    // If there are remaining elements in A, add them to C
    while (i < size1)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    // If there are remaining elements in B, add them to C
    while (j < size2)
    {
        C[k] = B[j];
        j++;
        k++;
    }

    // Print the merged array
    cout << "After Merging: " << endl;
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size1, size2;

    // Input size and elements for the first sorted array
    cout << "Enter the size of 1st sorted array: ";
    cin >> size1;
    int *A = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    // Input size and elements for the second sorted array
    cout << "Enter the size of 2nd sorted array: ";
    cin >> size2;
    int *B = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> B[i];
    }

    // Merge the two sorted arrays
    merge_two_list(A, size1, B, size2);

    return 0;
}
