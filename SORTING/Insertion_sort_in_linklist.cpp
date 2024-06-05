#include <iostream>
using namespace std;

class Node
{
private:
    int data; // Data part of the node
    Node *next; // Pointer to the next node
    Node *ptr = NULL, *temp = NULL, *head = NULL; // Helper pointers

public:
    // Constructor to initialize node
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Function to insert a value into the linked list in sorted order
    void Insertion(int val);

    // Function to display the linked list
    void display();
};

void Node::Insertion(int val)
{
    temp = new Node(); // Create a new node
    temp->data = val; // Assign the value to the new node

    if (head == NULL) // If the list is empty, make the new node the head
    {
        head = temp;
    }
    else // If the list is not empty
    {
        ptr = head; // Start from the head
        Node *prev = NULL; // Previous node pointer

        // Traverse the list to find the correct position to insert
        while (ptr != NULL && ptr->data < val)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev == NULL) // Insert at the beginning if the correct position is the head
        {
            temp->next = head;
            head = temp;
        }
        else // Insert in between or at the end
        {
            prev->next = temp;
            temp->next = ptr;
        }
    }
}

void Node::display()
{
    temp = head; // Start from the head

    // Traverse and print the list
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Print a newline at the end
}

int main()
{
    Node n; // Create a Node object
    int size;
    cout << "Enter the size of the linklist: ";
    cin >> size;

    // Input values and insert them into the linked list
    for (int i = 0; i < size; i++)
    {
        int val;
        cout << "Enter the data part of node " << i << ": ";
        cin >> val;
        n.Insertion(val);
    }

    n.display(); // Display the linked list

    return 0;
}
