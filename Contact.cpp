#include "Contact.h"

// Constructor
Contact::Contact(string name, string phone, Relationship relation) {
    this->name = name;
    this->phone = phone;
    this->relation = relation;
}

// Getter
string Contact::getName() {
    return name;
}

string Contact::getPhone() {
    return phone;
}

Relationship Contact::getRelation() {
    return relation;
}

// Setter
void Contact::setName(string name) {
    this->name = name;
}

void Contact::setPhone(string phone) {
    this->phone = phone;
}

void Contact::setRelation(Relationship relation) {
    this->relation = relation;
}

// Convert enum -> string
string relationToString(Relationship r) {
    switch (r) {
        case FAMILY: return "FAMILY";
        case FRIEND: return "FRIEND";
        case TEACHER: return "TEACHER";
        case COLLEAGUE: return "COLLEAGUE";
    }
    return "UNKNOWN";
}

// Display
void Contact::display() {
    cout << "Name: " << name
         << " | Phone: " << phone
         << " | Relation: " << relationToString(relation)
         << endl;
}
