#include <iostream>
#include "Contact.h"
#include <string.h>
int main(){
    Contact contact1("Brian", 12345678);
    Contact contact2("asss", 12345678);
    Contact contact3("Basssss", 12345678);

    std::cout << contact1.contactName << std::endl;
    std::cout << contact1.Contacts.size() << std::endl;
    return 0;
}