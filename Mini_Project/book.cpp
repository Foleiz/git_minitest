#include <iostream>

using namespace std;
class Book
{
private:
    int id; // รหัสหนังสือ
    string title; //ชื่อหนังสือ
    string author; //ผู้แต่ง
    int year; //ปีที่พิมพ์

public:
    Book(int ID, string Title,string Author,int Year)
    {
        this->id = ID;
        this->title = Title;
        this->author = Author;
        this->year = Year;
    }
};

class Library : public Book
{
private:
    array save {100};

    
public:
    void addBook()
    {

    }
    removeBook(int id)
};

int main()
{
    Book Book1(601,"Man vs Woman","Scott",1998);
    Book Book2(602,"My Cat","James",2015);
    Book Book3(603,"Power of The Sun","Peter",2020);

    



}