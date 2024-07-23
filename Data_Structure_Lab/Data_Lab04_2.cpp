#include <iostream>
#define SIZE 5
using namespace std;
class Queue {
private:
	int items[SIZE], front, rear;

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	bool isFull() {
		if (front == 0 && rear == SIZE - 1) {
			return true;
		}
		return false;
	}
	bool isEmpty() {
		if (front == -1)
			return true;
		else
			return false;
	}
	void enQueue(int element) 
    {
		if (isFull()) 
        {
			cout << "Queue is full";
		}
		else 
        {
			if (front == -1) front = 0;
			rear++;
			items[rear] = element;
			cout << endl << "Inserted " << element << endl;
		}
	}
	int deQueue() //เลื่อนเฉพาะหัว 
    {
		int element;
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return (-1);
		}
		else {
			element = items[front];
			if (front >= rear) {
				front = -1;
				rear = -1;
			} /* Q has only one element, so we reset the queue after deleting it. */
			else {
				front++;
			}
			cout << endl << "Deleted -> " << element << endl;
			return (element);
		}
	}
	void display() {
		/* Function to display elements of Queue */
		int i;
		if (isEmpty()) {
			cout << endl << "Empty Queue" << endl;
		}
		else {
			cout << endl << "Front index-> " << front;
			cout << endl << "Items -> " << endl;
			for (i = front; i <= rear; i++)
				printf("Address: %p => val: %d\n", &items[i], items[i]);
			cout << endl << "Rear index-> " << rear << endl;
		}
		cout << "\n--------------------------------------------------------------------\n";
	}
};
int main() 
{
	Queue q;
	int main,choice,push;
	while (true)
	{
		cout<<"1) Enqueue\n";
		cout<<"2) Dequeue\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		cout<<"Select 1-4: ";
		cin>>main;
		if(main ==1)
		{
			cout<<"Enter choice: ";
			cin>>choice;
			cout<<"Enter value to be pushed: ";
			cin>>push;
			q.enQueue(push);
		}

		else if(main==2)
		{
			q.deQueue();
		}
		else if(main==3){
			q.display();
		}
		else if(main==4){
			break;
		}
		else
			cout<<"Invalid.!!\n";

	}
	
	return 0;
}