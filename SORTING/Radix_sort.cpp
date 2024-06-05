#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Node class representing an element in the linked list
class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize the node with data and next pointer as NULL
    Node(int d) : data(d), next(NULL) {};
};

// Function to find the number of passes needed for radix sort
int find_pass(int max)
{
    int pass = 0;
    while (max != 0)
    {
        max = max / 10; // Divide max by 10 to reduce the number of digits
        pass++; // Increment the pass count
    }
    return pass;
}

// Function to perform radix sort on array A of size n with given number of passes
void radix_sort(int A[], int n, int pass)
{
    Node **temp = new Node *[10]; // Array of pointers to Node representing bins for decimal digits (0-9)

    for (int i = 0; i < 10; i++)
    {
        temp[i] = NULL; // Initialize all bin pointers to NULL
    }

    for (int i = 0; i < pass; i++) // Loop through each pass
    {
        int p = pow(10, i); // Calculate the place value (1, 10, 100, ...)
        for (int j = 0; j < n; j++) // Loop through all elements in the array
        {
            int x = (A[j] / p) % 10; // Find the digit at the current place value
            Node *newNode = new Node(A[j]); // Create a new node for the current element
            if (temp[x] == NULL)
                temp[x] = newNode; // If bin is empty, insert the new node as the first node
            else
            {
                Node *ptr = temp[x]; // Traverse to the end of the linked list in the bin
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode; // Insert the new node at the end of the list
            }
        }

        int k = 0;
        for (int j = 0; j < 10; j++) // Loop through all bins
        {
            Node *ptr = temp[j], *temp2;
            while (ptr != NULL) // Extract elements from the bins
            {
                int x = ptr->data;
                A[k] = x; // Place node data back into the array
                k++;
                temp2 = ptr;
                ptr = ptr->next;
                delete temp2; // Delete the node to free memory
            }
            temp[j] = NULL; // Reset the bin for the next pass
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamic array allocation
    int *A = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << " : ";
        cin >> A[i];
    }

    // Find the maximum element in the array
    int max = *max_element(A, A + size);

    // Find the number of passes needed for radix sort
    int pass = find_pass(max);

    // Perform radix sort
    radix_sort(A, size, pass);

    // Free the dynamically allocated array
    delete[] A;

    return 0;
}
