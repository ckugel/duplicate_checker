#include <iostream>
#include <fstream>
#include <filesystem>

#include <vector>

#include <bitset>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

void strReplacement(string &str, const char& toBeReplaced, char toReplaceWith) {
    while (str.find(toBeReplaced) >=0 && str.find(toBeReplaced) <= str.size()) {
        str[str.find(toBeReplaced)] = toReplaceWith;
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

void getFileNames() {
    string path = "E:";
    string temp;
    vector<string> paths;
    for (const auto & entry : filesystem::directory_iterator(path)) {
        temp = entry.path().string();
/*        temp.replace(temp.begin(), temp.end(), ".", "\\");*/
        cout << temp << endl;
/*        paths.push_back(temp);*/
/*        readFile(temp);*/
    }
/*    for (int i = 0; i < paths.size(); i++) {
        for (const auto & entry : filesystem::directory_iterator(paths[i])) {
            try {
                temp = (basic_string<char> &&) entry.path();
                paths.push_back(temp);
                readFile(temp);
            }
            catch (exception &e) {

            }
        }
    }*/
/*    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }*/
}


int main() {
    getFileNames();


    return 0;
}




