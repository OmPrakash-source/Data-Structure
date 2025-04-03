#include<iostream>
#include<vector>
#include<iostream>
 
using namespace std;

class Book{
    public:
        int id;
        string author, title;
        bool isItAvailable = true;
        Book (int bookId, string bookauthor, string booktitle){
            this->author = bookauthor;
            this->id = bookId;
            this->title = booktitle;
            
        }
        void dispaly (){
            cout<<"ID: "<<id << ", Title: " << title << ", Author: " << author << ", Available: " << (isItAvailable ? "Yes" : "No") << endl;
        }
        void markAsBorrowed(){
            isItAvailable = false;
        }
        void markAsRetuened(){
            isItAvailable = true;
        }
};

class Library {
    private:
        vector<Book>books;
    public:
        void addBook(const Book &book){
            books.push_back(book);
        }
        void borrrowBook(int bookId){
            for (auto &book : books){
                if(book.id == bookId && book.isItAvailable){
                    book.markAsBorrowed();
                    cout<<"You succesfully borrow : "<<book.title;
                    return;
                }
            }
            cout<<"!Oops'this book is not available\n";
        }
        void displayBooks(){
            for (auto &book : books){
                book.dispaly();
            }   
        }
        void searchBooks(string title){
            for (auto &book : books){
                if(title == book.title){
                    cout<<title<<" book found \n";
                    book.dispaly();
                    return;
                }
            }
        }
        void returnBook(int bookId){
            for (auto &book : books){
                if(book.id == bookId && !book.isItAvailable){
                    book.markAsRetuened();
                    cout<<"You succesfully return : "<<book.title;
                    return;
                }
            }
            cout<<"You not borrow this book \n";
        }
};

int main(){
    Library library;
    library.addBook(Book(1,"Lippman","CPP Prime"));
    library.addBook(Book(2,"R.C Martin","Clean Code"));
    library.addBook(Book(3,"J.R.R.T","The Habbit"));

    int choice;
    do{
        cout<<"\n_____ Library Manu _____\n";
        cout<<" 1.Display Book\n 2.Search Book\n 3.Borrow Book\n 4.Return Book\n 5.Add book\n 6.Exit\n";

        cout<<"\nEnter your choice : ";
        cin >> choice;
        switch (choice){
        case 1:
            library.displayBooks();
            break;
        case 2:{
            string title;
            cout<<" Enter book title: ";
            cin.ignore();
            getline(cin,title);
            library.searchBooks(title);
            break;
        }
        case 3:{
            int id;
            cout<<" Enter book Id to borrow ";
            cin>>id;
            library.borrrowBook(id);
            break;
        }
        case 4:{
            int id;
            cout<<" Enter book Id to return ";
            cin>>id;
            library.returnBook(id);
            break;
        }
        case 5:{
            int id ;
            string n , aut;
            cout<<"Enter book detail : \n";
            cout<< "1. id "; 
            cin >> id;
            cin.ignore();
            cout<< "2. auther "; 
            getline(cin,aut);
            cout<< "3. title "; 
            getline(cin,n);
            library.addBook(Book(id,aut,n));
            cout<<"book successfully added \n";
            break;
        }
        case 6: 
            cout<<" Exiting......\n";
            break;
        default:
            cout<<"Invalid choice \n try again...";
            break;
        }

    } while (choice != 6);
    
}