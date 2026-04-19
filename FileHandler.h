#pragma once

#include <vector>
#include <string>
#include "Contact.h"

using namespace std;

class FileHandler {
public:
    static vector<Contact> loadFromFile(const string& filename);
    static void saveToFile(const string& filename, const vector<Contact>& contacts);
};
