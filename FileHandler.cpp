#include "FileHandler.h"
void FileHandler::saveToFile(const string& filename, const vector<Contact>& contacts) {
    ofstream outFile(filename);
    if (!outFile) {
        return; // Hoặc báo lỗi nếu không mở được file
    }

    for (const auto& c : contacts) {
        // Lưu theo cấu trúc: Tên|Số điện thoại|Mối quan hệ(số nguyên)
        outFile << c.name << "|" << c.phone << "|" << (int)c.relation << endl;
    }
    outFile.close();
}

vector<Contact> FileHandler::loadFromFile(const string& filename) {
    vector<Contact> contacts;
    ifstream inFile(filename);
    if (!inFile) {
        return contacts; // Trả về vector rỗng nếu file chưa tồn tại
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string name, phone, relStr;

        // Tách các thành phần dựa trên dấu '|'
        if (getline(ss, name, '|') &&
            getline(ss, phone, '|') &&
            getline(ss, relStr, '|')) {

            // Chuyển chuỗi mối quan hệ về kiểu enum Relationship
            Relationship rel = static_cast<Relationship>(stoi(relStr));
            contacts.push_back(Contact(name, phone, rel));
        }
    }
    inFile.close();
    return contacts;
}