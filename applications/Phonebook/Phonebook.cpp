#include "Phonebook.h"
#include "Contact.h"

void Phonebook::AddContact(Contact contact){
    Phonebook::Contacts.push_back(contact);
}

void Phonebook::RemoveContact(int id){
    Phonebook::Contacts.erase(id);
}