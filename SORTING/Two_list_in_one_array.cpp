// One array has two sorted lists. Merge these two sorted lists into a new array which is also sorted.

#include <iostream>
using namespace std;

void sorted_all_array(int A[], int n)
{
    int mid = n / 2; // Find the midpoint of the array
    int i = 0, j = mid, k = 0; // Initialize pointers for merging

    int *B = new int[n]; // Create a new array to hold the merged elements

    // Merge elements from the two sorted halves of the array
    while (i < mid && j < n)
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
    while (i < mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // If there are remaining elements in the second half, add them to B
    while (j < n)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    // Print the merged array
    cout << "After merging: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    delete[] B; // Free the dynamically allocated memory
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size];

    // Input elements for the first sorted half of the array
    for (int i = 0; i < size / 2; i++)
    {
        cout << "Enter the value of 1st sorted array at index " << i << ": ";
        cin >> A[i];
    }

    // Input elements for the second sorted half of the array
    for (int i = size / 2; i < size; i++)
    {
        cout << "Enter the value of 2nd sorted array at index " << i << ": ";
        cin >> A[i];
    }

    // Merge the two sorted halves and print the result
    sorted_all_array(A, size);

    delete[] A; // Free the dynamically allocated memory
    return 0;
}
