#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

enum Relationship {
    FAMILY,
    FRIEND,
    TEACHER,
    COLLEAGUE
};

class Contact {
private:
    string name;
    string phone;
    Relationship relation;

public:
    // Constructor
    Contact(string name = "", string phone = "", Relationship relation = FRIEND);

    // Getter
    string getName();
    string getPhone();
    Relationship getRelation();

    // Setter
    void setName(string name);
    void setPhone(string phone);
    void setRelation(Relationship relation);

    // Display
    void display();
};

// Helper function
string relationToString(Relationship r);

#endif
