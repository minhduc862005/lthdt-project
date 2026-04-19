#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

enum Relationship {
    FAMILY, FRIEND, TEACHER, COLLEAGUE
};

class Contact {
public:
    string name;
    string phone;
    Relationship relation;

    // Constructor
    Contact(string n = "", string p = "", Relationship r = FRIEND);

    // Hàm hiển thị
    void display();
};

// Hàm hỗ trợ
string relationToString(Relationship r);

#endif
