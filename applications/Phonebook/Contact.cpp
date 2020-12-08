#include "Contact.h"
#include <string.h>
#include <iostream>
#include <vector>


Contact::Contact(std::string name, int phonenumber, std::string city, std::string address){
    Contact::Name           = name;
    Contact::PhoneNumber    = phonenumber;
    Contact::City           = city;
    Contact::Address        = address;
}