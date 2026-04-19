#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <algorithm>

static string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return start == string::npos ? string() : s.substr(start, end - start + 1);
}

static Relationship stringToRelationship(string value) {
    value = trim(value);
    for (char& c : value) c = toupper((unsigned char)c);

    if (value == "FAMILY") return FAMILY;
    if (value == "FRIEND") return FRIEND;
    if (value == "TEACHER") return TEACHER;
    if (value == "COLLEAGUE") return COLLEAGUE;
    return FRIEND;
}

vector<Contact> FileHandler::loadFromFile(const string& filename) {
    vector<Contact> contacts;
    ifstream input(filename);
    if (!input.is_open()) {
        return contacts;
    }

    string line;
    while (getline(input, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string name, phone, relation;

        if (!getline(ss, name, ',')) continue;
        if (!getline(ss, phone, ',')) continue;
        if (!getline(ss, relation)) continue;

        name = trim(name);
        phone = trim(phone);
        relation = trim(relation);

        if (name.empty() || phone.empty()) continue;

        contacts.emplace_back(name, phone, stringToRelationship(relation));
    }

    return contacts;
}

void FileHandler::saveToFile(const string& filename, const vector<Contact>& contacts) {
    ofstream output(filename);
    if (!output.is_open()) {
        return;
    }

    for (const auto& contact : contacts) {
        output << contact.name << "," << contact.phone << "," << relationToString(contact.relation) << "\n";
    }
}
