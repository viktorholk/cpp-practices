#include <iostream>
#include "Contact.h"
#include "Phonebook.h"
#include <string>
#include <conio.h>

Phonebook phonebook;

int main(){
    phonebook.AddContact(Contact("Markus bjørn", 21351457, "Holstebro", "Struervej 12"));
    phonebook.AddContact(Contact("Flemming hank", 54352253, "Herning", "sykosevej 222"));
    phonebook.AddContact(Contact("Ivan henriksen", 21351457, "Holstebro", "bobvej 69"));
    phonebook.AddContact(Contact("Jens Jensen", 21351457, "København", "Sejersen 21"));
    phonebook.AddContact(Contact("Jenner jes", 21351457, "Ribe", "Paramedis 66"));



    while (true){
        std::cout << std::endl;
        std::cout << "Choose an option" << std::endl;
        std::cout << "1. Add contact" << std::endl;
        std::cout << "2. Remove contact" << std::endl;
        std::cout << "3. List all contacts" << std::endl;
        std::cout << "4. Clear the console" << std::endl;
        std::cout << std::endl;
        std::cout << "0. Quit the application" << std::endl;

        int input;
        std::cin >> input;
        std::cin.ignore();

        switch (input) {
            case 0:
                return 0;
                break;
            
            case 1: {
                std::string name;
                std::cout << "Name: ";
                std::getline(std::cin, name);

                int phoneNumber;
                std::cout << "Phone Number:";
                std::cin >> phoneNumber;
                std::cin.ignore();

                std::string city;
                std::cout << "City: ";
                std::getline(std::cin, city);

                std::string address;
                std::cout << "Address: ";
                std::getline(std::cin, address);

                Contact newContact(name, phoneNumber, city, address);
                phonebook.AddContact(newContact);
                break;

            }

            case 2: {
                int id;
                std::cout << "Contact ID: ";
                std::cin >> id;
                std::cin.ignore();

                phonebook.RemoveContact(phonebook.Contacts[id]);
                break;
            }

            case 3: {
                for (int i = 0; i < phonebook.Contacts.size(); i++){
                    auto contact = phonebook.Contacts[i];
                    std::cout << i << " > " << contact.Name << " > " << contact.PhoneNumber << " > " << contact.City << " > " << contact.Address << std::endl;
                }
                break;
            }

            default:
                break;
        }

    }


    return 0;
}