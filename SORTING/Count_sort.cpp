// Here count array size is equall to the maximum element in the array
// Time Complexity = O(n)

#include <iostream>
#include <algorithm>
using namespace std;

// Function to perform counting sort on the given array 'A' of size 'n'
void count_sort(int A[], int n, int max)
{
    // Initialize an array 'count' to store the frequency of each element (assuming elements are in the range 0-15)
    int *count = new int[max];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    // Count the occurrences of each element in the array 'A'
    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        count[x] = count[x] + 1;
    }

    int k = 0;

    // Clear the original array 'A' by setting all elements to 0
    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
    }

    // Reconstruct the sorted array by placing elements in their correct positions based on their counts
    for (int i = 0; i < max; i++)
    {
        while (count[i] > 0)
        {
            A[k] = i;
            k++;
            count[i]--;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    // Deallocate the memory used for the 'count' array
    delete[] count;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate memory for the array 'A' based on the input size
    int *A = new int[size];

    // Input the elements of the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    // Using std::max_element to find the maximum element in the array
    int max = *max_element(A, A + size);

    // Call the counting sort function to sort the array
    count_sort(A, size, max + 1);

    // Deallocate the memory used for the array 'A'
    delete[] A;

    return 0;
}
