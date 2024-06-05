
#include <iostream>
#include <string>
using namespace std;

class Node
{

    Node *next;

public:
    int data;
    Node *temp, *ptr, *head, *prev;
    Node()
    {
        next = NULL;
        head = NULL;
    }
    void insertSorted(Node *&head, int x); //*H[] is array of pointer which is pointing out to the linklist
    int hash(int key);
    void insert(Node *H[], int key);
    void display(Node *H[]);
    void search(Node *H[], int key);
};

void Node::insertSorted(Node *&head, int x)
{
    temp = new Node;
    temp->data = x;
    temp->next = NULL;

    ptr = head;
    prev = NULL;

    if (head == NULL) // when linked list have no element
    {
        head = temp;
    }

    else
    {
        while (ptr != NULL && ptr->data < temp->data) // compare the data
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev == NULL) // insert at beginning
        {
            temp->next = head;
            head = temp;
        }

        else // insert at middle
        {
            prev->next = temp;
            temp->next = ptr;
            // prev=temp;
        }
    }
}

int Node::hash(int key)
{
    return (key) % 20;
}

void Node::insert(Node *H[], int key)
{
    int index = hash(key);
    insertSorted(H[index], key);
}

void Node::search(Node *H[], int key)
{
    int index = hash(key);
    Node *p = H[index];
    while (p != NULL)
    {
        if (key == p->data)
        {
            cout << "Key found : " << p->data << endl;
            return;
        }

        p = p->next;
    }

    cout << "Key is not found." << endl;
}
void Node::display(Node *H[])
{

    for (int i = 0; i < 20; i++)
    {
        cout << "H[" << i << "]:";
        ptr = H[i];
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << endl;
    }
}

int main()
{
    Node n;
    Node *HT[20]; // creating hash table with size 10

    for (int i = 0; i < 20; i++)
    {
        HT[i] = NULL; // initiliase with null value
    }

    n.insert(HT, 12);
    n.insert(HT, 22);
    n.insert(HT, 42);
    n.insert(HT, 15);
    n.search(HT, 22);
    n.insert(HT,89);
    n.insert(HT,100);
    n.insert(HT,0);

    n.display(HT);
    return 0;
}

// Chatgpt
//  #include<iostream>
//  #include<string>
//  using namespace std;

// class Node
// {
//     Node *next;

// public:
//     int data;
//     Node() {
//         next = nullptr;
//     }
//     void insertSorted(Node* &head, int x);
//     int hash(int key);
//     void insert(Node* H[], int key);
//     void display(Node* H[]);
//     void search(Node* H[], int key);
// };

// void Node::insertSorted(Node* &head, int x)
// {
//     Node *temp = new Node;
//     temp->data = x;
//     temp->next = nullptr;

//     Node *ptr = head;
//     Node *prev = nullptr;

//     if (head == nullptr) {
//         head = temp;
//     }
//     else {
//         while (ptr != nullptr && ptr->data < temp->data) {
//             prev = ptr;
//             ptr = ptr->next;
//         }

//         if (prev == nullptr) {
//             temp->next = head;
//             head = temp;
//         }
//         else {
//             prev->next = temp;
//             temp->next = ptr;
//         }
//     }
// }

// int Node::hash(int key)
// {
//     return key % 10; // Modified to match the hash table size
// }

// void Node::insert(Node* H[], int key)
// {
//     int index = hash(key);
//     insertSorted(H[index], key);
// }

// void Node::search(Node* H[], int key)
// {
//     int index = hash(key);
//     Node* p = H[index];
//     while (p != nullptr) {
//         if (key == p->data) {
//             cout << "Key found: " << p->data << endl;
//             return;
//         }
//         p = p->next;
//     }
//     cout << "Key not found." << endl;
// }

// void Node::display(Node* H[])
// {
//     for (int i = 0; i < 10; ++i) {
//         cout << "HT[" << i << "]: ";
//         Node* ptr = H[i];
//         while (ptr != nullptr) {
//             cout << ptr->data << " ";
//             ptr = ptr->next;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     Node n;
//     Node* HT[10]; // Creating hash table with size 10

//     for (int i = 0; i < 10; ++i) {
//         HT[i] = nullptr; // Initialize with null value
//     }

//     n.insert(HT, 12);
//     n.insert(HT, 22);
//     n.insert(HT, 42);
//     n.insert(HT, 15);
//     n.search(HT, 22);
//     n.display(HT);

//     return 0;
// }
