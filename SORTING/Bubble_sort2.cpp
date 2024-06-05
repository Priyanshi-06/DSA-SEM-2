// When we need a fixed number of sorted elements in the following list

#include <iostream>
using namespace std;

void bubblesort(int A[], int size, int k)
{
    // Perform bubble sort for k iterations to get the top k largest elements
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            // Swap if the current element is less than the next element
            if (A[j] < A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size, k;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *A = new int[size];

    cout << "How many numbers you want to sort? ";
    cin >> k;

    // Input array elements from the user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    // Sort the array to get the top k largest elements
    bubblesort(A, size, k);

    // Print the sorted elements
    cout << "Sorting elements: " << endl;
    for (int i = size - 1; i > size - 1 - k; i--)
    {
        cout << A[i] << " ";
    }
    return 0;
}
