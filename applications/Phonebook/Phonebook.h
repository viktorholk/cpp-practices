#if !defined(PHONEBOOK_PHONEBOOK)
#define PHONEBOOK_PHONEBOOK
#include "Contact.h"
#include <vector>
#include <algorithm>
class Phonebook{
    public:
        static inline std::vector<Contact> Contacts;

        void AddContact(Contact contact);
        void RemoveContact(Contact contact);

        int inline GetContactIndex(Contact contact);

        int maxContacts;
        Phonebook(int _maxContacts);

  private:

};

#endif // PHONEBOOK_PHONEBOOK
