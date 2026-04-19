#include "Contact.h"

// Constructor
Contact::Contact(string n, string p, Relationship r) {
    name = n;
    phone = p;
    relation = r;
}

// Hàm chuyển enum → string
string relationToString(Relationship r) {
    switch (r) {
        case FAMILY: return "FAMILY";
        case FRIEND: return "FRIEND";
        case TEACHER: return "TEACHER";
        case COLLEAGUE: return "COLLEAGUE";
    }
    return "UNKNOWN";
}

// Hiển thị
void Contact::display() {
    cout << "Name: " << name
         << " | Phone: " << phone
         << " | Relation: " << relationToString(relation)
         << endl;
}
