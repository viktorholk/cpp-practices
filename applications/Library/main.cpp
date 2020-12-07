#include <iostream>
#include <string>
#include <conio.h>
#include "book.h"
#include "inventory.h"

Inventory inventory;

int main(){

    while (true){
        std::cout << std::endl;
        std::cout << "Choose an option" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. List all books" << std::endl;
        std::cout << "3. Check out book" << std::endl;
        std::cout << "4. Check in book" << std::endl;
        std::cout << "5. Clear the console" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Quit the application" << std::endl;

        int input;
        std::cin >> input;
        std::cin.ignore();
        switch (input){
            case 0: {
                std::cout << "Thank you. Goodbye" << std::endl;
                return 0;
            }
            case 1: {
                std::cout << "Title: ";
                std::string title;
                std::getline(std::cin, title);
                
                std::cout << "Author: ";
                std::string author;
                std::getline(std::cin, author);

                Book newBook(inventory.Books.size() + 1, title, author);

                inventory.AddBook(newBook);
                break;
            }
            case 2: {
                for (int i = 0; i < inventory.Books.size(); i++){
                    std::cout << inventory.Books[i].Id << " > " << inventory.Books[i].Title;
                    std::cout << std::endl;
                }
                getch();
                break;
            }
            
            case 5: {
                system("cls");
                break;
            }

            default:
                break;
        }
        
    }

    return 0;
}

