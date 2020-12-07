#pragma once

#include <vector>
#include "book.h"

class Inventory{
    public:
        std::vector<Book> Books;

        void AddBook(Book book);
        void RemoveBook(Book book);
        void CheckBook(Book book, bool checked);
        Book FindBookById(int id);
};  