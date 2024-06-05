#include <iostream>
using namespace std;

// For array
// Time Complexity = O(n^2)
// Adaptive and stable (Naturally adaptive)
// Minimum Time Complexity = O(n) // list is already in ascending sorted order
// Maximum Time Complexity = O(n^2)

void Insertion(int A[], int n)
{
    // Iterate over each element starting from the second element
    for (int i = 1; i < n; i++) // Here we assume that 0th index element is already sorted
    {
        int j = i - 1; // Start comparing from the previous element
        int x = A[i]; // Store the current element

        // Shift elements of the sorted segment forward to find the correct position for x
        while (j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }

        // Place x at its correct position
        A[j + 1] = x;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size];

    // Input array elements from the user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value: ";
        cin >> A[i];
    }

    Insertion(A, size); // Call the insertion sort function

    // Print sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
