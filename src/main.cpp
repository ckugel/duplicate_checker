#include <iostream>
#include <fstream>
#include <filesystem>

#include <vector>

#include <bitset>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

typedef bitset<8> BYTE;

int main() {

/*    ifstream inFile;
    size_t size = 0; // here

    inFile.open( "test.txt", ios::in|ios::binary|ios::ate );
    char* oData = 0;

    inFile.seekg(0, ios::end); // set the pointer to the end
    size = inFile.tellg() ; // get the length of the file
    cout << "Size of file: " << size;
    inFile.seekg(0, ios::beg); // set the pointer to the beginning

    oData = new char[ size+1 ]; //  for the '\0'
    inFile.read( oData, size );
    oData[size] = '\0' ; // set '\0'
    cout << " oData size: " << strlen(oData) << "\n";

    //print data
    for ( size_t i = 0; i < strlen(oData); i++ )
    {
        cout << "oData["<<i<<"] " << oData[i];
        cout << "\n";
        cout << oData[i] << " + 'a' = " << ( oData[i] + 'a' );
        cout << "\n\n";

    }
    getchar();*/

    return 0;
}


void readFile(string path) {
    typedef unsigned char uint8;
    ifstream source("path", ios_base::binary);
    LinkedList list;
    while (source) {
        ios::pos_type before = source.tellg();
        uint8 x;
        source >> x;
        ios::pos_type after = source.tellg();
        Node *temp = new Node((void*)x);
        list.push(temp);
    }
}

void getFileNames() {
    string path = "E:";
    string temp;
    vector<string> paths;
    for (const auto & entry : filesystem::directory_iterator(path)) {
        temp = (basic_string<char> &&) entry.path();
        paths.push_back(temp);
        readFile(temp);
    }
    for (int i = 0; i < paths.size(); i++) {
        for (const auto & entry : filesystem::directory_iterator(paths[i])) {
            temp = (basic_string<char> &&) entry.path();
            paths.push_back(temp);
            readFile(temp);
        }
    }
}

