#include <iostream>
#include "book.h"




Book::Book(int id, std::string title, std::string author, bool checkedout = false){
    Book::Id = id;
    Book::Title = title;
    Book::Author = author;
    Book::CheckedOut = checkedout;
}