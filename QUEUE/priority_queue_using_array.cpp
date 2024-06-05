#include<iostream>
#include<iomanip>
using namespace std;
class Priority_Queue{
int size;
int Front;
int Rear;
int *Priority;
string *tasks;
public:
Priority_Queue(int size) {
this->size = size;
Front = -1;
Rear = -1;
Priority = new int[size];
tasks = new string[size];

}
void dequeue();
void Enqueue(int priority ,string task);
void Display(){
for(int i = Front ; i<Rear; i++)
{
cout<<tasks[i]<<" -> ";
}
cout<<"Rear"<<endl;
}
string is_Front();
bool is_Empty();
};
void Priority_Queue :: dequeue(){
if(Front == -1 && Rear == -1)
{
cout<<"The Priority Queue is Empty!!"<<endl;
}
else if(Front == 0 && Rear == 0)
{
Front =-1 ;
Rear = -1;
}
else
{
for(int i = 1; i<=Rear; i++)
{
Priority[i-1] = Priority[i];
tasks[i-1] = tasks[i];
}
Rear--;
}
}
void Priority_Queue :: Enqueue(int priority , string task){

if(Front == -1 && Rear == -1)
{

Front = 0 ;
Rear = 0;
Priority[Rear] = priority;
tasks[Rear] = task;
}
else if(Front == 0 && Rear == size-1)
{
cout<<"Priority Queue is Full!!"<<endl;
}
else{
int i =0;
for(i = 0 ; i<=Rear; i++)
{

if(priority>Priority[i]){
for(int j = Rear ; j>=i; j--)
{
Priority[j+1] = Priority[j];
tasks[j+1] = tasks[j];
}
Rear++;
Priority[i] = priority;
tasks[i] = task;
break;
}
if(i== Rear)
{
Rear++;
Priority[Rear] = priority;
tasks[Rear] = task;
break;
}

}
}

}
string Priority_Queue:: is_Front(){
return tasks[Front];
}

bool Priority_Queue:: is_Empty(){
if(Rear<Front)
return 1;
else
return 0;

}

int main()
{
Priority_Queue q1(6);
cout << "Is the Priority Queue empty? : " << boolalpha <<
q1.is_Empty() << endl
<< endl;
cout << "Enqueueing tasks with priority value(high value for high priority)" << endl;
q1.Enqueue(78, "Opening the app");
q1.Enqueue(57, "Running app");
q1.Enqueue(89, "Practicing");
q1.Enqueue(10, "Computintg");
q1.Enqueue(89, "Handling user input");
q1.Enqueue(95, "Displaying output");
q1.Enqueue(90,"ok");
cout<<endl<<"The tasks are : ";
q1.Display();
cout << "Task with highest priority now" << endl;
cout << q1.is_Front() << endl<< endl;
q1.dequeue();
q1.dequeue();
cout << "After dequeueing two times Task with highest priority now is" << endl;
cout << q1.is_Front();

cout<<endl<<"The remaining tasks are : ";
q1.Display();
return 0;
}