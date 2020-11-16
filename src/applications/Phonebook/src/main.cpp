#include <iostream>
#include "Contact.h"
#include "Phonebook.h"
#include <string.h>
int main(){
    Phonebook phonebook(125);

    phonebook.AddContact(Contact("Brian", 12345));

    std::cout << phonebook.Contacts.size() << std::endl;

    return 0;
}