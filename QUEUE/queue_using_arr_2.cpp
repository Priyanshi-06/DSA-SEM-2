// #include<iostream>
// using namespace std;

// class Queue
// {
//     private:
//     int size;
//     int rear ;
//     int front;
//     int *q=NULL;

//     public:
//     Queue(int s)
//     {
//         size=s;
//         rear =-1;
//         front=0;
//         q=new int[size];
//     }

//     void enqueue(int x);
//     void dequeue();
//     void display();
// };

// void Queue::enqueue(int x)
// {
//     if(rear==size-1)
//     {
//         cout<<"Queue is full."<<endl;
//     }

//     else
//     {
//         rear++;
//         q[rear]=x;
        
//     }
// }

// void Queue::dequeue()
// {
//     int x=-1;
//     if(front==0 && rear==-1)
//     {
//         cout<<"Queue is empty."<<endl;
        
//     }

//     else
//     {
//         int x=q[front];
        
//         for(int i=0; i<rear;i++)
//         {
//             q[i]=q[i+1];
//         }
//         rear--;
//         cout<<"Dequeued element is "<<x<<endl;
//     }
// }

// void Queue::display()
// {
//     if(front==0 && rear==-1)
//     {
//         cout<<"Final Queue is empty."<<endl;
//     }

//     else
//     {
//     for(int i=front;i<=rear;i++)
//     {
//         cout<<q[i]<<" ";
//     }
//     }
// }

// int main()
// {
//     int s;
//     cout<<"Enter the size of queue : ";
//     cin>>s;

    
//     Queue q1(s); 
   
//     q1.enqueue(10);
//     q1.enqueue(20);
//     q1.dequeue();
//     q1.dequeue();
//     q1.dequeue();
//     q1.enqueue(30);
//     q1.enqueue(40);
//     q1.dequeue();
//     q1.dequeue();
//     q1.display();


// return 0;
// }


