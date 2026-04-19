    #include "ContactManager.h"
    #include <iostream>

    using namespace std;

    // ===== SET =====
    void ContactManager::setContacts(const vector<Contact>& list) {
        contacts = list;
    }

    // ===== GET =====
    vector<Contact> ContactManager::getAll() const {
        return contacts;
    }

    // ===== DISPLAY =====
    void ContactManager::displayAll() const {
        if (contacts.empty()) {
            cout << "Contact list is empty.\n";
            return;
        }

        for (const auto& c : contacts) {
            c.display();   // nhớ: display() phải là const
        }
    }

    // ===== ADD =====
    bool ContactManager::addContact(const Contact& c) {
        // check trùng phone
        for (const auto& item : contacts) {
            if (item.phone == c.phone) {
                return false;
            }
        }

        contacts.push_back(c);
        return true;
    }

    // ===== DELETE =====
    bool ContactManager::deleteContact(const string& phone) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->phone == phone) {
                contacts.erase(it);
                return true;
            }
        }
        return false;
    }

    // ===== UPDATE =====
    bool ContactManager::updateContact(const string& phone, const Contact& newC) {
        for (auto& c : contacts) {
            if (c.phone == phone) {
                c = newC;
                return true;
            }
        }
        return false;
    }

    // ===== SEARCH =====
    vector<Contact> ContactManager::searchByName(const string& name) const {
        vector<Contact> result;

        for (const auto& c : contacts) {
            if (c.name.find(name) != string::npos) {
                result.push_back(c);
            }
        }

        return result;
    }
