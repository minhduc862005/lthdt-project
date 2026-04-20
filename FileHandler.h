#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Contact.h"

using namespace std;

class FileHandler {
public:
    // Lưu toàn bộ danh sách liên hệ vào file
    static void saveToFile(const string& filename, const vector<Contact>& contacts);

    // Đọc dữ liệu từ file và chuyển thành danh sách đối tượng Contact
    static vector<Contact> loadFromFile(const string& filename);
};

#endif