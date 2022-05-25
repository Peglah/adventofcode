#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int fileLines(string fname);
bool debug = false;

int main () {
  int myArray [fileLines("input")];
  int count = 0;
  string line;

  ifstream myfile ("input");
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      stringstream ssint(line);
      ssint >> myArray[count];
      count++;
      if (debug) { cout << line << endl; }
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  for (int i = 0; i < sizeof(myArray)/sizeof(myArray[0]); i++) {
    if (debug) { cout << "array id " << i << " = " << myArray[i] << endl; }
    for (int j = 0; j < sizeof(myArray)/sizeof(myArray[0]); j++) {
      for (int k = 0; k < sizeof(myArray)/sizeof(myArray[0]); k++) {
        if (debug) { cout << myArray[i] << " + " << myArray[j] << " + " << myArray[k] << endl; }
        if (myArray[i] + myArray[j] + myArray[k] == 2020) {
          cout << myArray[i] * myArray[j] * myArray[k];
          exit(0);
        }
      }
    }
  }
  return 0;
}

int fileLines(string fname) {
  int count = 0;
  string line;

  ifstream myfile (fname);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      count++;
    }
    myfile.close();
    if (debug) { cout << count << endl; }
  }
  else cout << "Unable to open file";
  return count;
}
