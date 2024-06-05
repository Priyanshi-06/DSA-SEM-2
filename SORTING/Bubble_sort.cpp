#include <iostream>
using namespace std;

// Time Complexity (Maximum time complexity) = O(n^2)
// Time Complexity (When list is already sorted) (Minimum time complexity) = O(n)
// Adaptive and stable (We make it adaptive, not already adaptive)
// Make adaptive using a flag

void Bubble(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++) // Outer loop for number of passes
    {
        flag = 0; // Initialize flag to check if any swapping happened
        for (int j = 0; j < n - 1 - i; j++) // Inner loop for each pass
        {
            if (A[j] > A[j + 1]) // If the current element is greater than the next element
            {
                int temp = A[j]; // Swap the elements
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1; // Set flag to 1 indicating a swap occurred
            }
        }

        if (flag == 0) // If no swaps occurred, the array is sorted
        {
            break; // Break out of the loop early
        }
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

    Bubble(A, size); // Call Bubble sort to sort the array

    // Print sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
