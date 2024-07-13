#include <iostream>
#include <string>
#include <ctype.h>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

   
struct Person {
    int sequence;
    string firstName;
    string lastName;
    string nickname;
    int age;
};
 
int main()
{
//     ifstream Myfile ("numbers.txt");
//     if(!Myfile){
//         cout<<"ไม่สามรถเปิดไฟล์ได้";
//         return 1 ;
//     }

//     string lines_2;
//     int sum = 0;
//     while (getline(Myfile, lines_2)) 
//     {
//     string word = "";  // ตัวแปรสำหรับเก็บคำ
//     for (char c : lines_2) {  // วนลูปผ่านแต่ละอักขระในบรรทัด
//         if (isspace(c)) {  // ถ้าเจอช่องว่าง
//             if (!word.empty()) {  // ถ้า word ไม่ว่างเปล่า
//                 try {
//                     int number = stoi(word);  // แปลงคำเป็นตัวเลข
//                     sum += number;  // บวกตัวเลขเข้ากับผลรวม
//                 } catch (invalid_argument& e) {
//                     // ถ้าคำไม่สามารถแปลงเป็นตัวเลขได้ จะเกิดข้อยกเว้น และเราจะไม่ทำอะไร
//                 }
//                 word = "";  // เคลียร์คำสำหรับคำถัดไป
//             }
//         } else {
//             word += c;  // เพิ่มอักขระในคำปัจจุบัน
//         }
//     }
//     // ตรวจสอบคำสุดท้ายในบรรทัด
//     if (!word.empty()) {
//         try {
//             int number = stoi(word);
//             sum += number;
//         } catch (invalid_argument& e) {
//             // ไม่ทำอะไร
//         }
//     }
// }


//     Myfile.close();
//     cout << "ผลรวมของตัวเลขในไฟล์คือ: " << sum << endl;


    ifstream inFile("text.txt");
    if (!inFile) {
        cerr << "ไม่สามารถเปิดไฟล์ได้" << endl;
        return 1;
    }

    string lines_2;
    while (getline(inFile, lines_2)) {
        stringstream ss(lines_2);
        string item;

        Person person;
        getline(ss, item, ',');  // อ่านลำดับ
        person.sequence = stoi(item);

        getline(ss, person.firstName, ',');  // อ่านชื่อ
        getline(ss, person.lastName, ',');   // อ่านนามสกุล
        getline(ss, person.nickname, ',');   // อ่านชื่อเล่น

        getline(ss, item);  // อ่านอายุ (ไม่ต้องใช้ ',' เพราะเป็นตัวสุดท้ายในบรรทัด)
        person.age = stoi(item);

        // แสดงข้อมูล
        cout << "ลำดับ: " << person.sequence << endl;
        cout << "ชื่อ: " << person.firstName << endl;
        cout << "นามสกุล: " << person.lastName << endl;
        cout << "ชื่อเล่น: " << person.nickname << endl;
        cout << "อายุ: " << person.age << endl;
        cout << endl;
    }

    inFile.close();
    return 0;
    
   
    //    int count;

    //     int id[100];
    //     string name[100];
    //     int age[100];
    //     string position[100];
    //     int salary[100];

    //     cout << "Enter the number of employees: ";
    //     while (!(cin >> count) || count <= 0) {
    //         cout << "Invalid input. Please enter a positive integer: ";
    //         cin.clear(); // Clear error flag
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
    //     }

    //     for (int i = 0; i < count; i++) {
    //         cout << "Enter Employee ID for employee " << i + 1 << ": ";
    //         while (!(cin >> id[i])) {
    //             cout << "Invalid input. Please enter a valid integer ID: ";
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         }

    //         cout << "Enter Name for employee " << i + 1 << ": ";
    //         cin.ignore(); // Ignore leftover newline character from previous input
    //         getline(cin, name[i]);

    //         cout << "Enter Age for employee " << i + 1 << ": ";
    //         while (!(cin >> age[i]) || age[i] <= 0) {
    //             cout << "Invalid input. Please enter a positive integer for age: ";
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         }

    //         cout << "Enter Position for employee " << i + 1 << ": ";
    //         cin.ignore(); // Ignore leftover newline character from previous input
    //         getline(cin, position[i]);

    //         cout << "Enter Salary for employee " << i + 1 << ": ";
    //         while (!(cin >> salary[i]) || salary[i] < 0) {
    //             cout << "Invalid input. Please enter a non-negative integer for salary: ";
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         }
    //     }

    //     cout << "All Employees:\n";
    //     cout << "ID\tName\tAge\tPosition\tSalary\n";

    //     for (int i = 0; i < count; i++) {
    //         cout << id[i] << "\t" << name[i] << "\t" << age[i] << "\t" << position[i] << "\t" << salary[i] << endl;
    //     }

    //     int search;
    //     bool found = false;

    //     while (!found) {
    //         cout << "Enter Employee ID to search: ";
    //         while (!(cin >> search)) {
    //             cout << "Invalid input. Please enter a valid integer ID: ";
    //             cin.clear();
    //             cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //         }

    //         for (int i = 0; i < count; i++) {
    //             if (search == id[i]) {
    //                 cout << "Employee Details:\n";
    //                 cout << "ID: " << id[i] << "\n";
    //                 cout << "Name: " << name[i] << "\n";
    //                 cout << "Age: " << age[i] << "\n";
    //                 cout << "Position: " << position[i] << "\n";
    //                 cout << "Salary: " << salary[i] << "\n";
    //                 found = true;
    //                 break;
    //             }
    //         }

    //         if (!found) {
    //             cout << "Employee ID {"<<search<<"} not found. Please try again.\n";
    //         }
    //     }
    
    

    // int number;
    // int score [100];
    // bool check_error = false;
    // cout<<"Enter the number of subjects: ";cin>>number;

    // for (int i = 0; i < number; i++) {
    //     do {
    //         cout << "Enter score for subject " << i + 1 << ": ";
    //         cin >> score[i];
    //         if (score[i] > 100 || score[i] < 0) {
    //             cout << "Invalid.!!! Please enter a score between 0 and 100.\n";
    //             check_error = true;
    //         } else 
    //         {
    //             check_error = false;
    //         }
    //     } while (check_error);
    // }

    // for (int i = 0; i < number; i++)
    // {
    //     if(score[i] >=0 &&score[i] <=49)
    //     {
    //         cout<<"Subject "<<i+1<<": F\n";
    //     }
    //     else if(score[i] >=50 &&score[i] <=59)
    //     {
    //         cout<<"Subject "<<i+1<<": D\n";
    //     }
    //     else if(score[i] >=60 &&score[i] <=69)
    //     {
    //         cout<<"Subject "<<i+1<<": C\n";
    //     }
    //     else if(score[i] >=70 &&score[i] <=79)
    //     {
    //         cout<<"Subject "<<i+1<<": B\n";
    //     }
    //     else
    //         cout<<"Subject "<<i+1<<": A\n";
    // }

    // int total =0;
    // for (int i = 0; i < number; i++)
    // {
    //     total +=score[i];
    // }
    
    // double avg = static_cast<double>(total) / number;
    // char grade;

    // if (avg >= 80) {
    //     grade = 'A';
    // } else if (avg >= 70) {
    //     grade = 'B';
    // } else if (avg >= 60) {
    //     grade = 'C';
    // } else if (avg >= 50) {
    //     grade = 'D';
    // } else {
    //     grade = 'F';
    // }

    // cout << "Average Grade: " << grade << endl;
    
    


    



    // int number;
    // string name[100] ;
    // int score[100];
    // cout<<"Enter the number of students: ";cin>>number;
    // // รับค่า
    // for (int i = 0; i < number; i++)
    // {
    //     cout<<"Enter the name of student"<<i+1<<": ";cin>>name[i];
    //     cout<<"Enter the score of "<<name[i]<<":";cin>>score[i];
    // }
    
    // int total = 0;
    // for (int i = 0; i < number; i++)
    // {
    //     total +=score[i];
    // }
    // double avg = static_cast<double>(total) / number;

    // int max = score[0];
    // int min = score[0];
    // string namemax = name[0];
    // string namemin = name[0];
    // for (int i = 0; i < number; i++)
    // {
    //     if(score[i] > max)
    //     {
    //         max = score[i];
    //         namemax = name[i];
    //     }
    //     if(score[i] < min)
    //     {
    //         min = score[i];
    //         namemin = name[i];
    //     }

    // }
    // cout<<"Average score: "<<avg<<endl;
    // cout << "Highest score: " << namemax << " with " << max << " points" << endl;
    // cout << "Lowest score: " << namemin << " with " << min << " points" << endl;
    
    
    
    



    // char text [] = {'S','H','A','C','K'};
    // int length = sizeof(text);

    // string input;

    // cout<<"What is the answer?\n->> ";
    // getline(cin,input);

    // for (int i = 0; i < length; i++)
    // {
    //     if(input[i]==text[i])
    //     {
    //         cout<<"ตำแหน่งที่ "<<i+1<<" ถูกต้อง = "<<input[i]<<" \n";
    //     }
    //     else
    //         cout<<"ตำแหน่งที่ "<<i+1<<" ยังไม่ถูกต้อง  \n";
    // }
}

