#include<iostream>
#include<iomanip>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    //public:
    Node(int d) : data(d), next(nullptr){}
};
class Queue{
    Node *head; 
    Node *front;
    Node *rear;
    public:
    Queue():head(nullptr){
        front = head;
        rear = head;
    }
    void enqueue(int data)
    {
        Node *new_node = new Node(data);
        if(rear == head && front == head && head == NULL)
        {
            front = new_node;
            rear = new_node;;
           // rera;
        }
        else
        {
            //Node *new_node = new Node(data);
             rear->next = new_node;
             rear = new_node;
             
        }
    
    }
    void display()
    {
        Node*tmp = front;
        while(tmp!= NULL){
            cout<<tmp->data<<" ";
            tmp = tmp ->next;
        }
        cout<<endl;
        
    }
    void dequeue()
    {
        if(front == head && rear == head)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            
            front = front->next;
            head = front;
        }
    }
};
int main(){
    
    Queue q;
    q.enqueue(14);
    q.display();
    q.enqueue(12);
    q.display();
    q.enqueue(13);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(16);
    q.display();

    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}