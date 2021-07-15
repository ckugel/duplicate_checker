#include <iostream>
#include <fstream>
#include <filesystem>

#include <vector>

#include <bitset>
#include "Node.h"
#include "LinkedList.h"

using namespace std;
typedef unsigned char uint8;

void strReplacement(string &str, const char& toBeReplaced, char toReplaceWith) {
    while (str.find(toBeReplaced) >= 0 && str.find(toBeReplaced) <= str.size()) {
        int index = str.find(toBeReplaced);
        str[index] = toReplaceWith;
        str.insert(index, "\\");
    }
}

LinkedList readFile(string path) {
    cout << path << endl;
    ifstream source("path", ios_base::binary);
    LinkedList list;
    while (source) {
        ios::pos_type before = source.tellg();
        uint8 x;
        source >> x;
        ios::pos_type after = source.tellg();
        Node *temp = new Node(reinterpret_cast<void *>(x));
        list.push(temp);
    }
    return list;
}

LinkedList checkForDuplicates(vector<filesystem::path *> pathers) {
    LinkedList toBeRemoved;
    vector<filesystem::path> pathes = (vector<filesystem::path>&) pathers;
    for (int i = 0; i < pathes.size(); i++) {
        for (int k = 0; k < pathes.size(); k++) {
            if (file_size(pathes[i]) != file_size(pathes[k]) ||
                pathes[i].filename().generic_string()._Equal(pathes[k].filename().generic_string())) {
                cout << pathes[i].generic_string() + " in terms of size and extension is different from: " +
                        pathes[k].generic_string() << endl;
            } else {
                bool NotDif = false;
                LinkedList one = readFile(pathes[i].generic_string());
                LinkedList two = readFile(pathes[k].generic_string());
                while (one.peak() != nullptr || two.peak() != nullptr) {
                    if ((uint8) one.pop().getData() == (uint8) two.pop().getData()) {

                    }
                    else {
                        NotDif = true;
                    }
                }
                if (NotDif) {
                    toBeRemoved.push(new Node((void*) &pathes[i]));
                }
            }
        }
    }
    return toBeRemoved;
}

vector<filesystem::path> getFileNames() {
    string path = R"(E:\coding\duplicate_checker\test)";
    string temp;
    vector<string> pathsTemp;
    vector<filesystem::path> pathsFiles;
    for (const auto & entry : filesystem::directory_iterator(path)) {
        temp = entry.path().generic_string();
        pathsTemp.push_back(temp);
/*        readFile(temp);*/
    }
    for (int i = 0; i < pathsTemp.size(); i++) {
        filesystem::path path1(pathsTemp[i]);
        if (is_directory(path1)) {
            for (const auto &entry : filesystem::directory_iterator(pathsTemp[i])) {
                temp = entry.path().generic_string();
                pathsTemp.push_back(temp);
                /*readFile(temp);*/
            }
        }
        else if (is_regular_file(path1)) {
            pathsFiles.push_back(path1);
        }
        else {
            cout << "scuffed path: " + pathsTemp[i];
        }
    }
    for (int i = 0; i < pathsTemp.size(); i++) {
        cout << pathsTemp[i] << endl;
    }
    return pathsFiles;
}


int main() {
    getFileNames();
/*    LinkedList temp = checkForDuplicates(getFileNames());

    while (temp.peak() != nullptr) {
        filesystem::path *a = (filesystem::path*) (temp.pop().getData());
        cout << a->generic_string().c_str() << endl;
        remove(a->generic_string().c_str());
    }*/


    return 0;
}




