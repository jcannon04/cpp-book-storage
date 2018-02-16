/* Author: Joshua Cannon
 * File Name: library.cpp
 * Date: 11/18/2017
 * Description: contains function implementations for library  class. Declarations can be found in library.h
 */
#include "library.h"

library::library(){
  list<Book> books;
}

void library::read_from_file(string file_name){
  
  ifstream library_file;
  library_file.open(file_name.c_str());
  
  string line;

  while(getline(library_file, line)){
   int  char_number = 1;
   Book b;
    
      while(line[char_number] != '"'){
	b.title += line[char_number];                //grab title
	char_number ++;
      }
      char_number+=2;                                //skip space and quotation

      while(line[char_number] != ' '){
	b.ISBN += line[char_number];                 // grab ISBN
        char_number++;
      }
      char_number++;                                //skip space

      string temp_year;//year is stored as string
      while(line[char_number] != ' '){
	temp_year += line[char_number];//grab number of page
        char_number++;
      }
      b.year = atoi(temp_year.c_str());// price is stored as int
      char_number++;//skip space
      
      string temp_price;//price is stored as string
      while(line[char_number] != ' '){
	temp_price += line[char_number];//grab price
        char_number++;
      }
      b.price = atof(temp_price.c_str());//price is stored as float
      char_number++;
      
      string temp_page;//page number is stored as string
      while(line[char_number] != ' '){
	temp_page += line[char_number];//grab number of page
        char_number++;
      }
      b.pages = atoi(temp_page.c_str());// page number is stored as int
      char_number++;//skip space

 
      while(char_number < line.size()){
	string temp_author;//place holder for a single author
	while(line[char_number] != '.'){
	    temp_author += line[char_number];
	    char_number++;
	  }
	  char_number+=2;//skip period and space
	  b.Author_Names.push_back(temp_author);
	  
	  }
      //update list
      insert_sorted(b.title, b.Author_Names, b.pages, b.ISBN, b.price, b.year);
      
      }
  library_file.close();
}

void library::write_to_file(string file_name){

  ofstream fout;
  fout.open(file_name.c_str());
    
  list<Book>::iterator it;
  for(it = books.begin(); it != books.end(); ++it){
    fout<< '"' << it->title << '"'<< " " << it->ISBN << " " << it->year << " " << it->price << " " << it->pages << " ";
  
    list<string>::iterator it1;
    for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
      fout << *it1 << ". ";
    }
    fout << endl;
  }
  fout.close();

}
void library::insert_sorted(string insert_title, list<string> inserted_authors, int insert_pages, string insert_isbn, float insert_price, int insert_year){
  Book b;

  b.title = insert_title;
  b.pages = insert_pages;
  b.ISBN = insert_isbn;
  b.price = insert_price;
  b.year = insert_year;
  
  list<string>::iterator it0;
  for(it0 = inserted_authors.begin(); it0 != inserted_authors.end(); ++it0){
    b.Author_Names.push_back(*it0);
  }

  //Case 1: list is empty push_front
  if(books.size() == 0 ){
    books.push_back(b);
    return;
  }
    
  //Case 2: we need to add element to front of list 
  if(b.title <=  books.begin()->title){
    books.push_front(b);
    return;
  }
  //Case 3: We insert somewhere in middle
  list<Book>::iterator it1;
  for(it1 = books.begin(); it1 != books.end(); ++it1){
      
    if(b.title <=  it1->title){//somewhere in middle
       books.insert(it1, b);
      return;
      cout << "insert middle";
    }
  }
  //Case 4: we add element to back of list
  books.push_back(b);
}

void library::find_book(string search_title){
  list<Book> print;
  
  list<Book>::iterator it;
  list<string>::iterator it1;
  
  for(it = books.begin(); it != books.end(); it++){
    if(it->title.find(search_title) != std::string::npos){//if search_title is a substring
      print.push_back(*it);
    }
  }
  
  //print book info to console
  for(it = print.begin(); it != print.end(); ++it){
    cout << "----------------------------------" << endl;
    cout <<"Title: " << it->title << endl;
    cout <<"ISBN: " << it->ISBN << endl;
    cout <<"Year of Publication: " << it->year << endl;
    cout <<"Price: " << it->price << endl;
    cout <<"Number of Pages: " << it->pages << endl;
    cout <<"Authors: ";
    
    for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
      cout << *it1 << "||";
    }
    cout << endl;
    cout << "----------------------------------" << endl;
  }
  cout <<endl;
}

void library::author_search(string search_author){
  list<Book> print;
  
  list<Book>::iterator it;
  list<string>::iterator it1;

  //compare every author for every book
  for(it = books.begin(); it != books.end(); ++it){
    for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
      if((*it1).find(search_author) != std::string::npos){
	  print.push_back(*it);
	  break;
      }
    }
  }
  //print info for all books with given author
  for(it = print.begin(); it != print.end(); ++it){
    cout << "-----------------------------------" << endl;
    cout <<"Title: " << it->title << endl;
    cout <<"ISBN " << it->ISBN << endl;
    cout <<"Year of Publication:  " << it->year << endl;
    cout <<"Price:  " << it->price << endl;
    cout <<"Number of Pages: " << it->pages << endl;
    cout <<"Authors: ";
    for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
      cout << *it1 << "||";
    }
    cout << endl;
  }
    cout << "-----------------------------------" << endl;
}

void library::print(){

 list<Book>::iterator it;
  for(it = books.begin(); it != books.end(); ++it){
  cout << "--------------------------------------" << endl;
 
    cout <<"Title: "<< it->title << endl;
    cout <<"ISBN:  " << it->ISBN << endl;
    cout <<"Year of Pulication:  " << it->year << endl;
    cout <<"Price:  " << it->price << endl;
    cout <<"Number of Pages:  " << it->pages << endl;
    cout << "Authors:  ";
  
    list<string>::iterator it1;
    for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
      cout << *it1 << "||";
    }
    cout << endl;
    cout << "--------------------------------------" << endl;
     }
}

void library::delete_book(string delete_book){
 
  if(books.size() == 0){
    return;
  }
  
   else{
     list<Book>::iterator it;
     for(it = books.begin(); it != books.end(); it++){//delete by isbn
       if(it->ISBN.compare(delete_book) == 0 ){
	it = books.erase(it);
	it--;
       }
       if(it->title.compare(delete_book) == 0){//delete by title
	 it = books.erase(it);
	 it--;
       }

         list<string>::iterator it1;
         for(it1 = it->Author_Names.begin(); it1 != it->Author_Names.end(); ++it1){
	   if((*it1).compare(delete_book) == 0){//delete by author
	     it = books.erase(it);
	     it--;
	   }
	 }
     }
   }
}

library::~library(){
  books.clear();
}
