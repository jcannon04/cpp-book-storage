#include "book.h"
#include "library.h"


using namespace std;

int main(){
  library l;

  int user_option = 1;
  while(user_option != 0 && user_option < 7){
    cout << endl;
    cout <<"Welcome to Library Databbase! You may select one the following options: " << endl;
    cout <<"1 Read in a list of books from a file" << endl;
    cout <<"2 Write the list of books to a file" << endl;
    cout <<"3 Print the list of books to console" <<endl;
    cout <<"4 Search for book by title" <<endl;
    cout <<"5 Search for book by author's name " <<endl;
    cout <<"6 delete books by title, ISBN, or author's name " <<endl;
    cout <<"7 Exit the program" <<endl;

    cout <<"Please enter your choice now: ";
    cin >> user_option;
    cout << endl;

    if(user_option == 1){
      cout <<" Please enter file you like to read from in format filename.txt: ";
      string user_read_file;
      cin >> user_read_file;

      cout << "now reading file..." << endl;
      l.read_from_file(user_read_file);
      cout << "file read into list." << endl;
      cout << endl;
    }

    if(user_option ==  2){
      cout <<" Please enter file you would like to write to in format filename.txt: ";
      string user_out_file;
      cin >> user_out_file;

      cout << "now writing file..." << endl;
      l.write_to_file(user_out_file);
      cout << "file written." << endl;
      cout << endl;
    }

    if(user_option == 3){
      cout <<" Now printing... " << endl;
      l.print();
      cout << endl;
    }

    if(user_option == 4){
      cout <<" Please enter title or part of title to search: ";
      string title_search;
      cin >> title_search;

      cout <<" books found with that title: " << endl;
      l.find_book(title_search);
      cout << endl;
    }

    if(user_option == 5){
      cout <<" Please enter name of author in format: First_name Last_name: ";
      string author_search;
      cin >> author_search;
      cout << "books found with that author:" << endl;
      l.author_search(author_search);
      cout << endl;
    }

    if(user_option == 6){
      cout << " Please enter title, ISBN, or author witch you would to delete from list: ";
      string user_del;
      cin >> user_del;

      cout << " Deleting... " << endl;
      cout << endl;

      l.delete_book(user_del);
      cout << " Deleted" << endl;
    }	
  }
  cout << "now exiting..." << endl;
  return 0;
}

