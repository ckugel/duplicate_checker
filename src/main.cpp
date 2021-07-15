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
    std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

LinkedList checkForDuplicates(vector<filesystem::path> pathers) {
    LinkedList toBeRemoved;
    toBeRemoved.push("END");
    for (int i = 0; i < pathers.size() - 1; i++) {
            if (compareFiles(pathers[i].generic_string(), pathers[i + 1].generic_string())) {
                toBeRemoved.push(pathers[i].generic_string());
        }
    }
    return toBeRemoved;
}

vector<filesystem::path> getFileNames() {
    string path = R"(E:\coding\duplicate checker\test)";
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
        /*cout << pathsTemp[i] << endl;*/
    }
    return pathsFiles;
}


int main() {

/*    cout << compareFiles(R"(E:\coding\duplicate checker\test\IMG_7324.jpeg)", R"(E:\coding\duplicate checker\test\IMG_7325.jpeg)") << endl;*/

    LinkedList temp = checkForDuplicates(getFileNames());

    while (!temp.peak()._Equal("END")) {
        string a = temp.pop().getData();
        // cout << a << endl;
        int result = remove(a.c_str());
        cout << result << endl;
    }
    return 0;
}




