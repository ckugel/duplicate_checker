#include <iostream>
#include <fstream>
#include <filesystem>

#include <vector>

#include <bitset>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

void strReplacement(string &str, const char& toBeReplaced, char toReplaceWith) {
    while (str.find(toBeReplaced) >= 0 && str.find(toBeReplaced) <= str.size()) {
        int index = str.find(toBeReplaced);
        str[index] = toReplaceWith;
        str.insert(index, "\\");
    }
}

void readFile(string path) {
    cout << path << endl;
/*    typedef unsigned char uint8;
    ifstream source("path", ios_base::binary);
    LinkedList list;
    while (source) {
        ios::pos_type before = source.tellg();
        uint8 x;
        source >> x;
        ios::pos_type after = source.tellg();
        Node *temp = new Node(reinterpret_cast<void *>(x));
        list.push(temp);
    }*/
}

vector<filesystem::path *> getFileNames() {
    string path = "E:\\coding";
    string temp;
    vector<string> pathsTemp;
    vector<filesystem::path*> pathsFiles;
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
            pathsFiles.emplace_back(path1);
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


    return 0;
}




