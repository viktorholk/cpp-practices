#if !defined(PHONEBOOK_CONTACT)
#define PHONEBOOK_CONTACT
#include <string.h>
#include <iostream>
#include <vector>
class Contact{
    public:
        std::string contactName;
        int contactNumber;
        Contact(std::string _contactName, int _contactNumber);

        std::string GetName();
};

#endif // PHONEBOOK_CONTACT
