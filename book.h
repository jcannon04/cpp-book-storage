/* Author: Joshua Cannon
 * File Name: book.h 
 * Date: 11/18/2017
 * Description. Header file containing book struct for csci 325 assignment 7 library class declarations for library  found in library.h
 */
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <list>

using namespace std;

struct Book{

  string title;
  list<string> Author_Names;
  int pages;
  string ISBN;
  float price;
  int year;
};
#endif  
