#include "Contact.h"
#include <string.h>
#include <iostream>
#include <vector>

Contact::Contact(std::string _contactName, int _contactNumber){
    Contact::contactName    = _contactName;
    Contact::contactNumber  = _contactNumber;
    Contact::Contacts.push_back(this);
    
}

std::string Contact::GetName(){
    return Contact::contactName;
}