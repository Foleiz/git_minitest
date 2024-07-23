#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Mother_product {
public:
    string name;
    string id;
    int amount;
    double price;

    void input();
    void display();
    string getID();
    double calculate_price();
};

class Child_product : public Mother_product {
public:
    void input() 
    {   
        cout << "===============================\n";
        cout << "ใส่ชื่อของผลิตภัณฑ์: ";
        getline(cin, name);
        cout << "ใส่หมายเลขผลิตภัณฑ์: ";
        cin >> id;
        cout << "ใส่จำนวน: ";
        cin >> amount;
        cout << "ใส่ราคา: ";
        cin >> price;
        cout << "\n===============================\n\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() 
    {
        cout << "===============================\n";
        cout << "ชื่อผลิตภัณฑ์: " << name << endl;
        cout << "หมายเลขผลิตภัณฑ์: " << id << endl;
        cout << "จำนวน: " << amount << endl;
        cout << "ราคา: " << price << endl;
        cout << "===============================\n\n";

    }

    string getID() {
        return id;
    }

    double calculate_price() {
        return amount * price;
    }
};

int main() {
    Child_product products[100];
    int Count = 0;

    while (true) {
        cout << "XoXoXoXoXoX [ เมนู ] XoXoXoXoXoX\n";
        cout << "1. เพิ่มสินค้า\n";
        cout << "2. แสดงสินค้าทั้งหมด\n";
        cout << "3. ค้นหาสินค้าโดยรหัส\n";
        cout << "4. คำนวณมูลค่ารวมของสินค้าทั้งหมด\n";
        cout << "5. ออก\n";
        cout << "XoXoXoXoXoXoXoXoXoXoXoXoXoXoXoX\n\n";
        cout << "เลือกทำรายการ: ";
        int choice;
        cin >> choice;
        cout<<endl;

        while (choice < 1 || choice > 5 || cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "กรุณาเลือก 1-5 เท่านั้น: ";
            cin >> choice;

        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) 
        {
            products[Count].input();
            Count++;
        } 
        else if (choice == 2)
        {
            bool found = false;
            for (int i = 0; i < Count; ++i) 
            {
                cout << "สินค้าที่ " << i + 1 << ":\n";
                products[i].display();
                cout << endl;
                found = true;
            }
 
            if (!found) 
            {
                cout << "ไม่พบสินค้า!\n\n";
            }
        } 

        else if (choice == 3) 
        {
            if(Count !=0)
            {
                string search_id;
                cout << "ป้อนรหัสสินค้าที่ต้องการค้นหา:";
                cin >> search_id;
                bool found = false;
                for (int i = 0; i < Count; ++i) 
                {
                    if (products[i].getID() == search_id) 
                    {
                        products[i].display();
                        found = true;
                        break;
                    }
                }

                if (!found) 
                {
                    cout << "ไม่พบสินค้า!\n";
                }
            }

            else
                cout<<"ไม่มีข้อมูลในระบบ!\n\n";
            
        } 

        else if (choice == 4) 
        {
            double totalValue = 0;
            for (int i = 0; i < Count; ++i) {
                totalValue += products[i].calculate_price();
            }
            cout << "มูลค่ารวมของสินค้าทั้งหมด: " << totalValue << "\n\n";
        } 
        else if (choice == 5) 
        {
            break;
        } 
        else 
        {
            cout << "กรุณาเลือก 1-5.\n";
        }
    }

    return 0;
}
