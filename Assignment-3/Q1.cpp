
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

    static int checkCopies(int c)
    {
        if (c < 0)
        {
            throw invalid_argument("Number of copies cannot be negative");
        }
        return c;
    }

public:

    Book() : Book("", "Unknown", 0)
    {
    }

    explicit Book(string t) : Book(t, "Unknown", 1)
    {
    }

    // Parameterised constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(checkCopies(c))
    {
    }

    // Display book details
    void display() const
    {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << copies << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    try
    {
        // Creating objects using different constructors
        Book b1;
        Book b2("C++ Programming");
        Book b3("Data Structures", "Mark Allen", 5);

        cout << "DEFAULT CONSTRUCTOR" << endl;
        b1.display();

        cout << "DONATED BOOK CONSTRUCTOR" << endl;
        b2.display();

        cout << "PARAMETERISED CONSTRUCTOR" << endl;
        b3.display();

        // Array of Book objects using default constructor
        Book shelf[3];

        // Testing negative number of copies
        cout << "TESTING INVALID COPIES" << endl;
        Book b4("Operating Systems", "Galvin", -2);

    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

