#include <iostream>
#include <string>
using namespace std;
//Library Menegment Code
class Book{
    private:
    string Title;
    string Author;
    int PublicYear;
    string ISBN;
    public:
    void setBookDetails(string bookname  ,string author , int year , string isbn){
       Title = bookname;
       Author = author;
       PublicYear = year;
       ISBN = isbn;
    }
    void displayBookDetails(){
        cout << Title <<endl;
        cout << Author << endl;
        cout << PublicYear << endl;
        cout << ISBN << endl;
    }
};
int main() {
    Book book1;
    book1.setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565");
    
    Book book2;
    book2.setBookDetails("To Kill a Mockingbird", "Harper Lee", 1960, "9780060935467");
    
    // Display book details
    cout << "Book 1 Details:" << endl;
    book1.displayBookDetails();
    cout << endl;
    
    cout << "Book 2 Details:" << endl;
    book2.displayBookDetails();
    cout << endl;

    return 0;
}
