//basics about stringstream
/*
stringstream ss("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56  // // <sstream> is the header file to be used here;
int tmp
ss>>tmp// extracts a integer from the stream
char ch 
ss>>ch //extracts a character from the stream
*/
problem statement :- https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> integers;
    stringstream ss(str);
    int tmp;
    char ch;
    while(ss>>tmp){
        integers.push_back(tmp);
        ss>>ch;

    }
    for(auto i = integers.begin(); i != integers.end(); i++) {
        cout <<*i << "\n";
    }
    
    return 0;
}
