#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

bool debug = false;
const string file = "input_short";

void printVector(vector<string> myVector);
void print_map(std::map<char, int> const &m);

int main () {

  vector<string> myVector {
    "These ",
    "are ",
    "words ",
    "in ",
    "my ",
    "vector"
  };

  printVector(myVector);

  map<char, int> myMap;
  myMap['a']=10;
  myMap['b']=30;
  myMap['c']=50;
  myMap['d']=70;

  print_map(myMap);

  ifstream myfile (file);
  if (myfile.is_open()) {

    string line;

    while (getline (myfile,line) ) {
    }

    myfile.close();
  }

  else cout << "Unable to open file" << endl;

  return 0;
}

void printVector(vector<string> myVector) {
  for (int i=0; i<myVector.size(); i++) {
    cout << myVector[i] << endl;
  }
}

void print_map(std::map<char, int> const &m) {
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
