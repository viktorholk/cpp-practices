#pragma once

#include <vector>
#include "book.h"

class Inventory{
    public:
        std::vector<Book> Books;

        void AddBook(Book book);
        void RemoveBook(Book book);
        Book FindBookByTitle(std::string title);
        void CheckOutBook(Book book);
        void CheckinBook(Book book);
};  