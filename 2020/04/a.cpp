#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;

string file = "input";

int fileLines(string fileName);
string purgeLine(string line, string erase);

int main () {
  int lines = fileLines(file);
//  cout << "Lines: " << lines << endl;

  string line;
  int valid = 0;
  int invalid = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    int fields = 0;
    while (getline (myfile,line) ) {
      line = purgeLine(line, "cid:");

      while (line.find(":") != string::npos) {
        line.erase(line.find(":"), 1);
        fields++;
      }

      if (line.length() == 0) {
        if (fields == 7) { valid++; } else invalid++;
        fields = 0;
      }
    }

    if (fields == 7) { valid++; } else invalid++;
    myfile.close();
  }

  else cout << "Unable to open file" << endl;
  cout << "Valid passports: " << valid << endl;
  cout << "Invalid passports: " << invalid << endl;
  return 0;
}

int fileLines(string fileName) {
  int count = 0;
  string line;

  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      count++;
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return count;
}

string purgeLine(string line, string erase) {
  if (line.find(erase) != string::npos) {
    line.erase(line.find("cid:"), 4);
  }
  return line;
}
