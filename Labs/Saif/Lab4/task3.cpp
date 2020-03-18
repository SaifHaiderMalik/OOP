#include<iostream>
#include<string>

using namespace std;

class bookType{

    string title;
    string author[4];
    string publisher;
    string ISBN;
    double price;
    int numberOfBooks;
    int numberOfAuthors;
    
    public:

    bookType()//string Title,string Aut,string Pub,string isbn,double Pri,int NOB,int NOA
    {
        title = " ";
        author[0] = " ";
        author[1] = " ";
        author[2] = " ";
        author[3] = " ";
        publisher = " ";
        ISBN = " ";
        price = 0;
        numberOfBooks = 1;
        numberOfAuthors = 1;
    }

    void setTitle(string _title){

        title = _title;
    }

    void showTitle(){

        cout << "The Title is: " << title <<endl;
    }

    string getTitle(){

        return title;
    }

    void checkTitle(string _title){

        if(title == _title){

            cout << "The Title is the same" <<endl;

        }

        else{

            cout << "Title is Different" <<endl;
        }
    }


    void showNumberOfBooks(){

        cout << "The Number of Books are: " << numberOfBooks <<endl;

    }

    void setNumberOfBooks(int numOfBooks){

        numberOfBooks = numOfBooks;
    }

    void IncreaseNumberOfBooks(int _numOfBooks){

        numberOfBooks = numberOfBooks + _numOfBooks;

    }

    void decreaseNumberOfBooks(int NumOfBooks){

        numberOfBooks = numberOfBooks - NumOfBooks;
    }

    
    void setPublisher(string _publisher){

        publisher = _publisher;

    }

    string getPublisher(){

        return publisher;

    }


    void setISBN(string _ISBN){

        ISBN = _ISBN;

    }

    string getISBN(){

        return ISBN;

    }

    void checkISBN(string _ISBN){

        if(ISBN == _ISBN){

            cout <<"The Book ISBN is same" <<endl;

        }

        else{

            cout << "The Book ISBN is not same" <<endl;

        }
    }

    void setPrice(double _price){

        price = _price;

    }

    double getPrice(){

        return price;

    }
  

    void setAuthor(int _numberOfAuthor){

        if(_numberOfAuthor > 0 && _numberOfAuthor < 5 ){

          numberOfAuthors = _numberOfAuthor;

          for(auto i=0;i < _numberOfAuthor;i++){
            
              cout << "Enter Author Name: " <<endl;
              cin >> author[i];
           }

         }
              
    }

    void getAuthor(){

        int i;

        for(i=0;i<4;i++){

            cout << "The Author(s) is/are: " << author[i] <<endl;
        }
    }

};


int main(void){
    

    bookType ob[100];

    string titleOB;
    string authorOB[4];
    string publisherOB;
    string ISBNOB;
    double priceOB;
    int numberOB;
    int numberOA;
    int i,choice;
    int count = 1;
    int j = 0;
    int index;
    char con = 'y';
    char aut = 'x';
    int z;

    while(count ==1){

        cout << "Press 1 to set Book Details " <<endl;
        cout << "Press 2 to Add a Books Details" <<endl;
        cout << "Press 3 to Update Number of Copies of Book" <<endl;
        cout << "Press 4 to Search a Book by its Title" <<endl;
        cout << "Press 5 to Search a Book by its ISBN" <<endl;
        cout << "Press 6 to Show all Book Details" <<endl;
        cout << "Press 0 to Quit" <<endl;

        switch(choice){

            case 1:

                for(i=0;i<100;i++){

                    if(con != 'y'){

                        break;

                    }

                    else{

                        cout << "Enter Book Title: " <<endl;
                        cin >> titleOB;

                        ob[i].setTitle(titleOB);

                        cout << "Enter Number of Authors: " <<endl;
                        cin >> numberOA;

                        ob[i].setAuthor(numberOA);
                

                        /*while(aut == 'x'){

                        cout << "Enter Author/Authors" <<endl;
                        cin >> authorOB[j];


                        
                        cout << "Enter 'x' to Add another Author: " <<endl;
                        cin >> aut;

                        j++;

                        }*/

                        cout << "Enter Publisher of Book: " <<endl;
                        cin >> publisherOB;

                        ob[i].setPublisher(publisherOB);

                        cout << "Enter ISBN: " <<endl;
                        cin >> ISBNOB;

                        ob[i].setISBN(ISBNOB);

                        cout << "Enter Price of Book: " <<endl;
                        cin >> priceOB;

                        ob[i].setPrice(priceOB);

                        cout << "Enter Number of Copies of Book: " <<endl;
                        cin >> numberOB;

                        ob[i].setNumberOfBooks(numberOB);

                    }

                    break;

                }


                case 2:

                    cout << "Enter index on which Book to Add: " <<endl;
                    cin >> index;

                    cout << "Enter Book Title: " <<endl;
                    cin >> titleOB;

                    ob[index].setTitle(titleOB);

                    cout << "Enter Number of Authors: " <<endl;
                    cin >> numberOA;

                    ob[index].setAuthor(numberOA);

                    cout << "Enter Publisher of Book: " <<endl;
                    cin >> publisherOB;

                    ob[index].setPublisher(publisherOB);

                    cout << "Enter ISBN: " <<endl;
                    cin >> ISBNOB;

                    ob[index].setISBN(ISBNOB);

                    cout << "Enter Price of Book: " <<endl;
                    cin >> priceOB;

                    ob[index].setPrice(priceOB);

                    cout << "Enter Number of Copies of Book: " <<endl;
                    cin >> numberOB;

                    ob[index].setNumberOfBooks(numberOB);

                    break;


                case 3:
                    
                    cout << "Enter Index of Book to Update: " <<endl;
                    cin >> index;

                    cout << "Enter Updated Number of Copies: " <<endl;
                    cin >> numberOB;

                    ob[index].setNumberOfBooks(numberOB);

                    break;
                
                case 4:

                    cout << "Enter Title of Book to Search: " <<endl;
                    cin >> titleOB;

                    for(z = 0 ; z <= 99; z++){

                        if( titleOB == ob[z].getTitle() ){

                           ob[z].showTitle();
                        }

                        else if(z == 99){

                            cout << "No Title Availabel: " << ob[z].getTitle <<endl;
                        }
                    }

                    break;

                case 5:
                    cout << "Enter ISBN of Book to Search: " <<endl;
                    cin >> ISBNOB;

                    for( z = 0; z <= 99; z++){

                        if(ISBNOB == ob[z].getISBN()){

                            //cout << "The ISBN of the book is: " << ob[z].getISBN <<endl;
                        }
                    }


        }
    }

    

}