#include <iostream>
using namespace std;

int stack[10];
int n = 5, top = -1;

void push(int val) // ดึงเข้า // top คือ เลข index ที่เก็บข้อมูล
{
    if (top >= n - 1)
        cout << "Stack Overflow" << endl; // ข้อมูลเต็ม
    else 
    {
        top++;
        stack[top] = val;
    }
}

void pop() // ลบออก 
{
    if (top <= -1)
        cout << "Stack Underflow" << endl; // ไม่มีข้อมูลให้ลบ
    else 
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void display() 
{
    if (top >= 0) 
    {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty" << endl;
        
    
}

int main() 
{
    int choice, num1_2;
    int num1_1;

    while (1)
    {
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Display\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter amount: ";
                cin >> num1_1;
                for (int i = 0; i < num1_1; i++)
                {
                    cout << "Enter your push " << i + 1 << ": ";
                    cin >> num1_2;
                    push(num1_2);
                }
                break; 
            case 2:
                pop();
                break;
            case 3:
                display();
                break; 
            case 4:
                exit(0); 
            default:
                cout << "Invalid please try again." << endl;
        }
    }
    
    return 0;
}
