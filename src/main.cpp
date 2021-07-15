#include <iostream>
#include <fstream>
#include <filesystem>

#include <vector>

#include <bitset>
#include "Node.h"
#include "LinkedList.h"

using namespace std;
typedef unsigned char uint8;
typedef filesystem::path path;

void strReplacement(string &str, const char& toBeReplaced, char toReplaceWith) {
    while (str.find(toBeReplaced) >= 0 && str.find(toBeReplaced) <= str.size()) {
        int index = str.find(toBeReplaced);
        str[index] = toReplaceWith;
        str.insert(index, "\\");
    }
}

bool compareFiles(const std::string& p1, const std::string& p2) {
    ifstream f1(p1, ifstream::binary|ifstream::ate);
    ifstream f2(p2, ifstream::binary|ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, ifstream::beg);
    f2.seekg(0, ifstream::beg);
    return equal(istreambuf_iterator<char>(f1.rdbuf()),
                      istreambuf_iterator<char>(),
                      istreambuf_iterator<char>(f2.rdbuf()));
}

LinkedList checkForDuplicates(vector<path> pathers) {
    LinkedList toBeRemoved;
    toBeRemoved.push("END");
    for (int i = 0; i < pathers.size() - 1; i++) {
            if (compareFiles(pathers[i].generic_string(), pathers[i + 1].generic_string())) {
                toBeRemoved.push(pathers[i].generic_string());
        }
    }
    return toBeRemoved;
}

vector<path> getFileNames() {
    string pathsz = R"(E:\coding\duplicate checker\test)";
    string temp;
    vector<string> pathsTemp;
    vector<path> pathsFiles;
    for (const auto & entry : filesystem::directory_iterator(pathsz)) {
        temp = entry.path().generic_string();
        pathsTemp.push_back(temp);
    }
    for (int i = 0; i < pathsTemp.size(); i++) {
        path path1(pathsTemp[i]);
        if (is_directory(path1)) {
            for (const auto &entry : filesystem::directory_iterator(pathsTemp[i])) {
                temp = entry.path().generic_string();
                pathsTemp.push_back(temp);
            }
        }
        else if (is_regular_file(path1)) {
            pathsFiles.push_back(path1);
        }
        else {
            cout << "scuffed pathsz: " + pathsTemp[i];
        }
    }
    for (int i = 0; i < pathsTemp.size(); i++) {
        cout << pathsTemp[i] << endl;
    }
    return pathsFiles;
}


int main() {


    LinkedList temp = checkForDuplicates(getFileNames());

    while (!temp.peak()._Equal("END")) {
        string a = temp.pop().getData();
        int result = remove(a.c_str());
        cout << result << endl;
    }
    return 0;
}




