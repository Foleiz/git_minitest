#include <iostream>
#include <string>
#define SIZE 5 /* Size of Circular Queue */

using namespace std;

class Queue 
{
private:
    string items[SIZE];
    int front, rear;

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    // ตรงนี้จะเช็คว่า queue เต็มไหม
    bool isFull() 
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) 
        {
            return true;
        }
        return false;
    }

    // ตรงนี้เช็คว่า queue ว่างอยู่ไหม
    bool isEmpty() 
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    // เพิ่มท้ายแถว
    void enQueue(string element) 
    {
        if (isFull()) 
        {
            cout << "Queue is full" << endl;
        }
        else 
        {
            if (front == -1) 
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    // ลบหัวแถว
    string deQueue() 
    {
        string element;
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return "";
        }
        else 
        {
            element = items[front];
            if (front == rear) 
            {
                front = -1;
                rear = -1;
            }
            else 
            {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }

	// โชว์ตำแหน่ง address ของข้อมูลที่เก็บ และชื่อทั้งหมดที่เพื่มเข้าไป
    void display() 
	{
		int i;
		if (isEmpty()) 
		{
			cout << endl
				<< "Empty Queue" << endl;
		}
		else 
		{
			cout << endl << "Front -> " << front;
			cout << endl
				<< "Items -> " << endl;
			for (i = front; i != rear; i = (i + 1) % SIZE)
				cout<<"Address : =>"<<&items[i] <<"\tVal: >>"<<items[i]<<endl;;
				cout<<"Address : =>"<<&items[rear] <<"\tVal: >>"<<items[rear]<<endl;
				cout<< "Rear -> " << rear << endl;
		}
	}
    
};

int main() 
{
    Queue q;
    int choice;
    string value;

    while (true) 
    {
        cout << "1) Enqueue\n";
        cout << "2) Delete\n";
        cout << "3) Display\n";
        cout << "4) Exit\n";
        cout << "Please select 1-4: ";
        cin >> choice;
        cin.ignore();
        switch (choice) 
        {
            case 1:
                cout << "Enter the value to enqueue: ";
                getline(cin,value);
                q.enQueue(value);
                break;
            case 2:
                value = q.deQueue();
                if (!value.empty())
                    cout << "Dequeued: " << value << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid." << endl;
        }
    }

    return 0;
}
