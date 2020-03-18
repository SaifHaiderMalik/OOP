#include <iostream>
#include <string>

using namespace std;

class bookType{
private:
    string bookTitle = "";
    int bookAuthorsCount = 0;
    string bookAuthors = "";
    string bookPublisher = "";
    string bookISBN = "";
    int bookPrice = 0;
    int bookYear = 0;
    int bookCopies = 0;

public:
    string getBookTitle(){return bookTitle;}
    int getBookAuthorsCount(){return bookAuthorsCount;}
    string getBookAuthors(){return bookAuthors;}
    string getBookPublisher(){return bookPublisher;}
    string getBookISBN(){return bookISBN;}
    string getBookISBNv2(){return bookISBN.substr(0, 3)+"-"+bookISBN[3]+"-"+bookISBN.substr(4, 2)+"-"+bookISBN.substr(6, 6)+"-"+bookISBN[12];}
    int getBookPrice(){return bookPrice;}
    int getBookYear(){return bookYear;}
    int getBookCopies(){return bookCopies;}
    
    void setBookTitle(string _bookTitle){
        bookTitle = _bookTitle;
    }

    void setBookAuthorsCount(int _bookAuthorsCount){
        bookAuthorsCount = _bookAuthorsCount;
        bookAuthors = "";
    }

    void setBookAuthors(int _bookAuthorsCount){
        while(_bookAuthorsCount < 1 || _bookAuthorsCount > 4){
            cout << "ALERT: Number of Authors Allowed is 1 to 4" << endl;
            cout << "Number of Authors: ";
            cin >> _bookAuthorsCount;
        }

        bookAuthorsCount = _bookAuthorsCount;
        string bookAuthor;

        for(int count = 1; count <= bookAuthorsCount; count++){
            cout << "Name of Author " << count << ": ";
            cin >> bookAuthor;
            bookAuthors += bookAuthor;

            if(count != bookAuthorsCount){
                bookAuthors += ", ";
            }
        }
    }

    void setBookPublisher(string _bookPublisher){
        bookPublisher = _bookPublisher;
    }

    void setBookISBN(string _bookISBN){
        if(_bookISBN.length() < 13){
            for(int i = 1; i <= (13 - _bookISBN.length()); i++){
                bookISBN.push_back('0');
            }
        }
        
        bookISBN += _bookISBN;
    }

    void setBookPrice(int _bookPrice){
        bookPrice = _bookPrice;
    }

    void setBookYear(int _bookYear){
        bookYear = _bookYear;
    }

    void setBookCopies(int _bookCopies){
        bookCopies = _bookCopies;
    }

    void findBookTitle(string _bookTitle){
        for(int i = 0; bookTitle.length() >= (_bookTitle.length() + i); i++){
            if(bookTitle.substr(i, _bookTitle.length()) == _bookTitle){
                cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                     << bookPrice << bookYear << bookCopies << endl;
                break;
            }
        }
    }

    void findBookAuthors(string _bookAuthor){
        for(int i = 0; bookAuthors.length() >= (_bookAuthor.length() + i); i++){
            if(bookAuthors.substr(i, _bookAuthor.length()) == _bookAuthor){
                cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                     << bookPrice << bookYear << bookCopies << endl;
                break;
            }
        }
    }

    void findBookPublisher(string _bookPublisher){
        for(int i = 0; bookPublisher.length() >= (_bookPublisher.length() + i); i++){
            if(bookPublisher.substr(i, _bookPublisher.length()) == _bookPublisher){
                cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                     << bookPrice << bookYear << bookCopies << endl;
                break;
            }
        }
    }

    void findBookISBN(string _bookISBN){
        if(bookISBN.substr((13 - _bookISBN.length()), _bookISBN.length()) == _bookISBN){
            cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                 << bookPrice << bookYear << bookCopies << endl;
        }
    }

    void findBookPrice(int _minPrice, int _maxPrice){
        if(bookPrice >= _minPrice && bookPrice <= _maxPrice){
            cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                 << bookPrice << bookYear << bookCopies << endl;
        }
    }

    void findBookYear(int _startYear, int _endYear){
        if(bookYear >= _startYear && bookYear <= _endYear){
            cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                 << bookPrice << bookYear << bookCopies << endl;
        }
    }

    void findBookCopies(int _minCopies, int _maxCopies){
        if(bookCopies >= _minCopies && bookCopies <= _maxCopies){
            cout << bookTitle << bookAuthors << bookPublisher << getBookISBNv2()
                 << bookPrice << bookYear << bookCopies << endl;
        }
    }
};

class memberType{
private:
    string memberName = "";
    string memberID = "";
    bool membershipFeePaid = false;
    int totalBooksPurchased = 0;
    int amountSpent = 0;
    int totalAmountSpent = 0;
    bookType* memberBooks = new bookType[0];

public:
    string getMemberName(){return memberName;}
    string getMemberID(){return memberID;}
    bool getMembershipFeePaid(){return membershipFeePaid;}
    int getTotalBooksPurchased(){return totalBooksPurchased;}
    int getAmountSpent(){return amountSpent;}
    int getTotalAmountSpent(){return totalAmountSpent;}
    bookType* getMemberBooks(){return memberBooks;}

    void setMemberName(string _memberName){}
    void setMemberID(string memberID){}
    void setMembershipFeePaid(bool membershipFeePaid){}
    void setTotalBooksPurchased(int totalBooksPurchased){}
    void setAmountSpent(int amountSpent){}
    void setTotalAmountSpent(int totalAmountSpent){}
    void setMemberBooks(bookType _memberBooks){}

};

int main(){
    int option, i = 0, index;
    bookType books[100];
    string bookTitle, bookAuthor, bookAuthors, bookPublisher, bookISBN;
    int bookAuthorsCount, bookPrice, bookYear, bookCopies, minPrice, maxPrice, startYear, endYear, minCopies, maxCopies;

    MENU:
    cout << "1) Add Book\n2) Modify Book Details\n3) Delete Book\n4) Search Book by Title\n5) Show All Books Record\n6) EXIT\nSelect Option: ";
    cin >> option;

    switch(option){
    case 1:
        while(books[i].getBookTitle().length() != 0){
            i++;
            if(i == 100){break;}
        }

        if(i > 99){
            cout << "Books Catalogue FULL!" << endl;
            break;
        }

        cout << "Book Title: ";
        cin >> bookTitle;
        books[i].setBookTitle(bookTitle);

        cout << "Number of Authors: ";
        cin >> bookAuthorsCount;
        books[i].setBookAuthors(bookAuthorsCount);

        cout << "Publisher Name: ";
        cin >> bookPublisher;
        books[i].setBookPublisher(bookPublisher);

        cout << "Book ISBN: ";
        cin >> bookISBN;
        books[i].setBookISBN(bookISBN);

        cout << "Book Price: ";
        cin >> bookPrice;
        books[i].setBookPrice(bookPrice);

        cout << "Year of Publishing: ";
        cin >> bookYear;
        books[i].setBookYear(bookYear);

        cout << "Number of Copies: ";
        cin >> bookCopies;
        books[i].setBookCopies(bookCopies);

        i = 0;
        break;
    
    case 2:
        goto MenuModify;
        break;
    
    case 3:
        goto MenuDelete;
        break;
    
    case 4:
        goto MenuSearch;
        break;
    
    case 5:
        cout << "Index: ";
        cin >> index;

        cout << "Book Title: " << books[index].getBookTitle() << endl;
        cout << "Number of Authors: " << books[index].getBookAuthorsCount() << endl;
        cout << "Name of Author " << books[index].getBookAuthors() << endl;
        cout << "Publisher Name: " << books[index].getBookPublisher() << endl;
        cout << "Book ISBN: " << books[index].getBookISBNv2() << endl;
        cout << "Book Price: " << books[index].getBookPrice() << endl;
        cout << "Year of Publishing: " << books[index].getBookYear() << endl;
        cout << "Number of Copies: " << books[index].getBookCopies() << endl;
        break;
    
    case 6:
        cout << "Closing Program..." << endl;
        exit(0);
        break;

    default:
        break;
    }
    goto MENU;

    MenuModify:
    cout << "1) Modify Book Details (Title)\n2) Modify Book Details (ISBN Number)\n3) Back to Main Menu\nSelect Option: ";
    cin >> option;

    switch(option){
    case 1:
        cout << "Book Title: ";
        cin >> bookTitle;

        while(books[i].getBookTitle() != bookTitle){
            i++;
            if(i == 100){break;}
        }

        if(i > 99){
            cout << "Book Title Not Found!" << endl;
            break;
        }

        cout << "Old > Book Title: " << books[i].getBookTitle() << endl;
        cout << "New > Book Title: ";
        cin >> bookTitle;
        books[i].setBookTitle(bookTitle);

        cout << "Old > Number of Authors: " << books[i].getBookAuthorsCount() << endl;
        cout << "New > Number of Authors: ";
        cin >> bookAuthorsCount;

        cout << "Old > Name of Author: " << books[i].getBookAuthors() << endl;
        cout << "New > Name of Author: " << endl;
        books[i].setBookAuthors(bookAuthorsCount);

        cout << "Old > Publisher Name: " << books[i].getBookPublisher() << endl;
        cout << "New > Publisher Name: ";
        cin >> bookPublisher;
        books[i].setBookPublisher(bookPublisher);

        cout << "Old > Book ISBN: " << books[i].getBookISBN() << endl;
        cout << "New > Book ISBN: ";
        cin >> bookISBN;
        books[i].setBookISBN(bookISBN);

        cout << "Old > Book Price: " << books[i].getBookPrice() << endl;
        cout << "New > Book Price: ";
        cin >> bookPrice;
        books[i].setBookPrice(bookPrice);

        cout << "Old > Year of Publishing: " << books[i].getBookYear() << endl;
        cout << "New > Year of Publishing: ";
        cin >> bookYear;
        books[i].setBookYear(bookYear);

        cout << "Old > Number of Copies: " << books[i].getBookCopies() << endl;
        cout << "New > Number of Copies: ";
        cin >> bookCopies;
        books[i].setBookCopies(bookCopies);

        i = 0;
        break;

    case 2:
        cout << "Book ISBN: ";
        cin >> bookISBN;

        while(books[i].getBookISBN() != bookISBN){
            i++;
            if(i == 100){break;}
        }

        if(i > 99){
            cout << "Book ISBN Not Found!" << endl;
            break;
        }

        cout << "Old > Book Title: " << books[i].getBookTitle() << endl;
        cout << "New > Book Title: ";
        cin >> bookTitle;
        books[i].setBookTitle(bookTitle);

        cout << "Old > Number of Authors: " << books[i].getBookAuthorsCount() << endl;
        cout << "New > Number of Authors: ";
        cin >> bookAuthorsCount;

        cout << "Old > Name of Author: " << books[i].getBookAuthors() << endl;
        cout << "New > Name of Author: " << endl;
        books[i].setBookAuthors(bookAuthorsCount);

        cout << "Old > Publisher Name: " << books[i].getBookPublisher() << endl;
        cout << "New > Publisher Name: ";
        cin >> bookPublisher;
        books[i].setBookPublisher(bookPublisher);

        cout << "Old > Book ISBN: " << books[i].getBookISBN() << endl;
        cout << "New > Book ISBN: ";
        cin >> bookISBN;
        books[i].setBookISBN(bookISBN);

        cout << "Old > Book Price: " << books[i].getBookPrice() << endl;
        cout << "New > Book Price: ";
        cin >> bookPrice;
        books[i].setBookPrice(bookPrice);

        cout << "Old > Year of Publishing: " << books[i].getBookYear() << endl;
        cout << "New > Year of Publishing: ";
        cin >> bookYear;
        books[i].setBookYear(bookYear);

        cout << "Old > Number of Copies: " << books[i].getBookCopies() << endl;
        cout << "New > Number of Copies: ";
        cin >> bookCopies;
        books[i].setBookCopies(bookCopies);

        i = 0;
        break;
    
    default:
        break;
    }
    goto MenuModify;

    MenuDelete:
    cout << "1) Delete Book (Title)\n2) Delete Book (ISBN Number)\n3) Back to Main Menu\nSelect Option: ";
    cin >> option;

    switch (option){
    case 1:
        cout << "Book Title: ";
        cin >> bookTitle;

        while(books[i].getBookTitle() != bookTitle){
            i++;
            if(i == 100){break;}
        }

        if(i > 99){
            cout << "Book Title Not Found!" << endl;
            break;
        }

        books[i].setBookTitle("");
        books[i].setBookAuthorsCount(0);
        books[i].setBookPublisher("");
        books[i].setBookISBN("");
        books[i].setBookPrice(0);
        books[i].setBookYear(0);
        books[i].setBookCopies(0);

        i = 0;
        break;
    
    case 2:
        cout << "Book ISBN: ";
        cin >> bookISBN;

        while(books[i].getBookISBN() != bookISBN){
            i++;
            if(i == 100){break;}
        }

        if(i > 99){
            cout << "Book ISBN Not Found!" << endl;
            break;
        }

        books[i].setBookTitle("");
        books[i].setBookAuthorsCount(0);
        books[i].setBookPublisher("");
        books[i].setBookISBN("");
        books[i].setBookPrice(0);
        books[i].setBookYear(0);
        books[i].setBookCopies(0);

        i = 0;
        break;
    
    default:
        break;
    }
    goto MenuDelete;

    MenuSearch:
    cout << "1) Show Book(s) with Title\n2) Show Book(s) by Author(s)\n3) Show Book(s) by Publisher\n4) Show Book(s) with ISBN\n5) Show Book(s) with Price (Min/Max)\n6) Show Book(s) published in Years (Start/End)\n7) Show Book(s) with Stock (Min/Max)\n8) Back to Main Menu\nSelect Option: ";
    cin >> option;

    switch (option){
    case 1:
        cout << "Book Title: ";
        cin >> bookTitle;

        //cout

        for(int i = 0; i < 100; i++){
            books[i].findBookTitle(bookTitle);
        }

        /*while(books[i].getBookTitle().length() != 0){
            i++;
            if(i == 100){break;}
        }*/

        /*if(i > 99){
            cout << "Books Catalogue FULL!" << endl;
            break;
        }*/

        break;
    
    case 2:
        cout << "Book Author: ";
        cin >> bookAuthor;

        for(int i = 0; i < 100; i++){
            books[i].findBookAuthors(bookAuthor);
        }
        break;
    
    case 3:
        cout << "Book Publisher: ";
        cin >> bookPublisher;

        for(int i = 0; i < 100; i++){
            books[i].findBookAuthors(bookPublisher);
        }
        break;
    
    case 4:
        cout << "Book ISBN: ";
        cin >> bookISBN;

        for(int i = 0; i < 100; i++){
            books[i].findBookISBN(bookISBN);
        }
        break;
    
    case 5:
        cout << "Book Price Range (Minimum Maximum): ";
        cin >> minPrice >> maxPrice;

        for(int i = 0; i < 100; i++){
            books[i].findBookPrice(minPrice, maxPrice);
        }
        break;
    
    case 6:
        cout << "Book Published in Year (Start End): ";
        cin >> startYear >> endYear;

        for(int i = 0; i < 100; i++){
            books[i].findBookYear(startYear, endYear);
        }
        break;
    
    case 7:
        cout << "Show Book(s) with Stock (Minimum Maximum): ";
        cin >> minCopies >> maxCopies;

        for(int i = 0; i < 100; i++){
            books[i].findBookCopies(minCopies, maxCopies);
        }
        break;
    
    case 8:
        goto MENU;
        break;

    default:
        cout << "ERROR! Please Enter value between (1 - 8)";
        break;
    }
    goto MenuSearch;
}