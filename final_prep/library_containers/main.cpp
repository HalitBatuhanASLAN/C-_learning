#include <iostream>
#include <string>
#include<vector>
#include<set>
#include<map>
using namespace std;

// Include your class definitions (e.g., Book, Library) here.

class Book
{
    public:
        Book(const int& id,const string& title,const string& auther):title(title),auther(auther),id(id){}
        void display()const
            {cout << "title : "<< title << "\nauther : "<< auther<< "\nid : " <<id<<endl;}
        friend bool operator<(const Book& o,const Book& other);
        const int getId()const{return id;}
    private:
        int id;
        string title;
        string auther;
};

class Library
{
    public:
        void addBook(const Book& o)
        {

            alls.push_back(o);
            id_looking.emplace(o.getId(),o);
            unique.insert(o);
        }
        void displayBooks()const
        {
            for(auto it = alls.begin();it <= alls.end();it++)
                it->display();
        }
        void searchBookById(const int& wanted)const
        {
            for(auto it = id_looking.begin();it != id_looking.end();it++)
            {
                if(it->first == wanted)
                {
                    it->second.display();
                    break;
                }
            }
        }
        void displayUniqueBooks()const
        {
            for(auto it = unique.begin();it != unique.end();it++)
                it->display();
        }
    private:
        vector<Book> alls;
        map<int,Book> id_looking;
        set<Book> unique;
};

bool operator<(const Book& o,const Book& other)
{
    return o.id < other.id;
}

int main() {
    // Create a Library object
    Library library;

    // Add books to the library
    cout << "Adding books to the library...\n";
    library.addBook(Book(1, "The Great Gatsby", "F. Scott Fitzgerald"));
    library.addBook(Book(2, "1984", "George Orwell"));
    library.addBook(Book(3, "To Kill a Mockingbird", "Harper Lee"));
    //library.addBook(Book(1, "The Great Gatsby", "F. Scott Fitzgerald")); // Duplicate book to test uniqueness

    // Display all books
    cout << "\nDisplaying all books in the library:\n";
    library.displayBooks();

    // Search for a book by ID (valid case)
    cout << "\nSearching for book with ID 2:\n";
    library.searchBookById(2);  // Should find the book and display details

    // Search for a book by ID (invalid case)
    cout << "\nSearching for book with ID 5:\n";
    library.searchBookById(5);  // Should not find the book and display an error message
    // Display unique books
    cout << "\nDisplaying unique books (no duplicates):\n";
    library.displayUniqueBooks();

    return 0;
}
