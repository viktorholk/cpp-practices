#if !defined(PHONEBOOK_PHONEBOOK)
#define PHONEBOOK_PHONEBOOK
#include "Contact.h"
#include <vector>
#include <algorithm>
class Phonebook{
    public:
        std::vector<Contact> Contacts;

        void AddContact(Contact contact);
        void RemoveContact(int id);
        void EditContact(Contact contact, Contact overwrite);


};

#endif // PHONEBOOK_PHONEBOOK
