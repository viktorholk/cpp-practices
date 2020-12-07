#include "inventory.h"

void Inventory::AddBook(Book book){
    Inventory::Books.push_back(book);
}

void Inventory::CheckBook(Book book, bool checked){
    book.CheckedOut = checked;
}
