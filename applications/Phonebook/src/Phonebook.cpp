#include "Phonebook.h"
#include "Contact.h"

Phonebook::Phonebook(int _maxContacts){
    Phonebook::maxContacts = _maxContacts;
}

void Phonebook::AddContact(Contact contact){
    Phonebook::Contacts.push_back(contact);
}

void Phonebook::RemoveContact(Contact contact){
    Phonebook::GetContactIndex(contact);
}

int Phonebook::GetContactIndex(Contact contact){
                auto it = std::find(Contacts.begin(), Contacts.end(), contact);

            // if element was found
            if (it != Contacts.end()){
                // Calculation the index of contact
                int index = it - Contacts.begin();
                std::cout << index << std::endl;
                return index;
            } else return -1;
            else if that do even
}
