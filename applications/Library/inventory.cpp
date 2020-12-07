#include "inventory.h"

void Inventory::AddBook(Book book){
    Inventory::Books.push_back(book);
}