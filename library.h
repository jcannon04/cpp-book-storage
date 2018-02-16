/* Author: Joshua Cannon
 * File Name: library.h 
 * Date: 11/18/2017
 * Description. Header file containing library class for csci 325 assignment 7 book struct is found in book.h
 */
#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

using namespace std;

class library : Book{
 private:
  list<Book> books;
  
 public:
  library();
  /* 
     Default Constructor
  */

  ~library();
  /*
    Destructor
  */
  
  void read_from_file(string file_name);
  /*
    Description: reads book  information from a file and stores it in list
    Parameters: name of data file as string
  */
  void write_to_file(string file_name);
  /*
    Description: writes book information stored is list  to a file
    Parameters: name of file where data is to be written
  */
  void insert_sorted(string insert_title, list<string> inserted_authors, int insert_pages, string insert_isbn, float insert_price, int insert_year );
  /*
    Description: inserts a book information into the list in alphabetical order based on title
    Parameters: information on book to be added; title, authors names, number of pages, ISBN, price and year of publication
  */

  void  find_book(string search_title);
  /*
    Description: looks up book  information for book with given title and prints to console
    Parameters: title  of requested book
    Returns: 
  */

  void author_search(string search_author);
  /*
    Description: searches for books by given author and prints information to console
    Parameters: name of author to be searched
  */

  void delete_book(string delete_isbn);
  /*
    Description: deletes employee from list with given first and last name
    Parameters: first name and last name of employee to be deleted
  */

  void print();
  /*
    Description: prints contents of book list to console
  */
};
#endif  
