#include <iostream>
#include <string>
#include "book.h"
#include "inventory.h"

Inventory inventory;

int main(){

    while (true){
        std::cout << "Choose an option" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. List all books" << std::endl;
        std::cout << "3. Check out book" << std::endl;
        std::cout << "4. Check in book" << std::endl;

        std::cout << "0. Quit the application" << std::endl;

        int input;
        std::cin >> input;

        switch (input){
            case 0:
                std::cout << "Thank you. Goodbye" << std::endl;
                return 0;
            case 1:
                std::cout << "Title: ";
                std::string title;
                std::getline(std::cin, title);
                
                std::cout << "Author: ";
                std::string author;
                std::getline(std::cin, author);

                Book newBook(inventory.Books.size() + 1, title, author);

                inventory.AddBook(newBook);
                break;

            default:
                break;
        }
        
    }

    return 0;
}

