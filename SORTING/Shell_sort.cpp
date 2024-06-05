#include <iostream>
#include <algorithm>
using namespace std;

// Function to perform shell sort on an array
void shell_sort(int A[], int n)
{
    // Initialize the gap value
    int gap = n / 2, j;

    // Continue sorting while gap is greater than 0
    while (gap > 0)
    {
        // Perform insertion sort for the elements with the current gap
        for (int i = gap; i < n; i++)
        {
            int temp = A[i]; // Store the current element
            j = i - gap;
            // Shift elements of the sorted segment to the right position
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            // Place the current element at its correct position
            A[j + gap] = temp;
        }
        // Reduce the gap for the next iteration
        gap = gap / 2;
    }

    // Print the sorted array
    cout << "final : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int size;
    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array : ";
    cin >> size;

    // Dynamically allocate memory for the array
    int *A = new int[size];
    // Prompt the user to enter the values for the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of the index " << i << " : ";
        cin >> A[i];
    }

    // Call the shell sort function to sort the array
    shell_sort(A, size);

    delete []A;
    return 0;
}
