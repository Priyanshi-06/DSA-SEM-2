// Merge four sorted lists into another sorted list
// Time Complexity = O(size1+size2)

#include <iostream>
using namespace std;

int *merge_two_list(int A[], int size1, int B[], int size2)
{
    // Function to merge two sorted arrays A and B into a single sorted array C
    int i = 0, j = 0, k = 0;
    int *C = new int[size1 + size2]; // Create a new array to hold the merged elements

    // Merge elements from both arrays until one of them is exhausted
    while (i < size1 && j < size2)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from A, if any
    while (i < size1)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    // Copy any remaining elements from B, if any
    while (j < size2)
    {
        C[k] = B[j];
        j++;
        k++;
    }

    // Print merged array
    cout << "After Merging : " << endl;
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;

    return C; // Return the merged array
}

int main()
{
    int size1, size2, size3, size4;

    // Input for the first sorted array
    cout << "Enter the size of 1st sorted array : ";
    cin >> size1;
    int *A = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the value of index " << i << " : ";
        cin >> A[i];
    }

    // Input for the second sorted array
    cout << "Enter the size of 2nd sorted array : ";
    cin >> size2;
    int *B = new int[size2];
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter the value of index " << i << " : ";
        cin >> B[i];
    }

    // Input for the third sorted array
    cout << "Enter the size of 3rd sorted array : ";
    cin >> size3;
    int *C = new int[size3];
    for (int i = 0; i < size3; i++)
    {
        cout << "Enter the value of index " << i << " : ";
        cin >> C[i];
    }

    // Input for the fourth sorted array
    cout << "Enter the size of 4th sorted array : ";
    cin >> size4;
    int *D = new int[size4];
    for (int i = 0; i < size4; i++)
    {
        cout << "Enter the value of index " << i << " : ";
        cin >> D[i];
    }

    // Merge first two arrays into P
    int *P = merge_two_list(A, size1, B, size2);

    // Merge second two arrays into E
    int *E = merge_two_list(C, size3, D, size4);

    // Merge P and E into the final sorted array F
    int *F = merge_two_list(P, size1 + size2, E, size3 + size4);

    return 0;
}
