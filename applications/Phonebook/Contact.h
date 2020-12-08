#if !defined(PHONEBOOK_CONTACT)
#define PHONEBOOK_CONTACT
#include <string.h>
#include <iostream>
#include <vector>
class Contact{
    public:
        std::string Name;
        int         PhoneNumber;
        std::string City;
        std::string Address;

        Contact(std::string name, int phonenumber, std::string city, std::string address);
};

#endif // PHONEBOOK_CONTACT
