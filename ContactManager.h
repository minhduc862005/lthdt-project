#pragma once
#include <vector>
#include <string>
#include "Contact.h"

using namespace std;

class ContactManager {
private:
    vector<Contact> contacts;

public:
    // set & get
    void setContacts(const vector<Contact>& list);
    vector<Contact> getAll() const;

    // chức năng chính
    void displayAll() const;

    bool addContact(const Contact& c);
    bool deleteContact(const string& phone);
    bool updateContact(const string& phone, const Contact& newC);

    vector<Contact> searchByName(const string& name) const;
};
