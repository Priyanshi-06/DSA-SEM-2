// This program performs bin sort on an array
// Required array size is equal to the maximum element in the given array

#include <iostream>
#include <algorithm>
using namespace std;

// Node class to represent each element in the linked list
class Node
{
public:
    int data;
    Node *next;
    // Constructor to initialize the node with data and next pointer as NULL
    Node(int d):data(d),next(NULL){};
};

// Function to perform bin sort
void bin_sort(int A[], int n, int max)
{
    // Create an array of pointers to Node, initialized to NULL
    Node **temp = new Node *[max];

    // Initialize all pointers in temp array to NULL
    for (int i = 0; i < max; i++)
    {
        temp[i] = NULL;
    }

    // Insert elements into their respective bins
    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        Node *newNode = new Node(x);

        // If the bin is empty, add the new node as the first node
        if (temp[x] == NULL)
        {
            temp[x] = newNode;
        }
        else
        {
            // Otherwise, find the end of the linked list and add the new node
            Node *ptr = temp[x];
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
    }

    int j = 0;
    // Reconstruct the array by extracting elements from the bins
    for (int i = 0; i < max; i++)
    {
        Node *ptr = temp[i], *temp2;
        while (ptr != NULL)
        {
            int x = ptr->data;
            A[j] = x; // Place node data back into the array
            j++;
            temp2 = ptr;
            ptr = ptr->next;
            delete temp2; // Delete the node to free memory
        }
        ptr = NULL;
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

    int *A = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> A[i];
    }

    // Find the maximum element in the array
    int max = *max_element(A, A + size);
    // Perform bin sort
    bin_sort(A, size, max + 1);

    return 0;
}
