#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Student {
public:
    string name;
    string id;
    int age;
    double gpa;

    void inputData()
     {
        cout << "Name: "; cin >> name;
        cout << "ID: "; cin >> id;
        cout << "Age: "; cin >> age;
        cout << "GPA: "; cin >> gpa;
        cout << endl;


    }

    void displayStudentData(int index) 
    {
        cout << "Student " << index + 1 << ": \n";
        cout << "  Name: " << name << endl;
        cout << "  ID: " << id << endl;
        cout << "  Age: " << age << endl;
        cout << "  GPA: " << gpa << endl;
        cout<<endl;
    }
};

int main() {
    
    Student students[100];
    int number;
    
    cout << "Input the number of students: ";
    cin >> number;
     do {
        cout << "Input the number of students: ";
        cin >> number;
        if (cin.fail() || number <= 0) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
            cout << "Input integer only..!!\n";
        }
    } while (cin.fail() || number <= 0);
    

    for (int i = 0; i < number; ++i)
    {
        cout << "Input data for student " << i + 1 << ":\n";
        students[i].inputData();
    }

    cout << "Student data:\n";
    for (int i = 0; i < number; ++i) 
    {
        students[i].displayStudentData(i);
    }

    return 0;
}
