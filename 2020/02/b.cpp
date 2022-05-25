#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;

int valid = 0;

int main () {
  string line;

  ifstream myfile ("input");
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
//      if (debug) { cout << line << endl; }

      int min = stoi(line.substr(0, line.find("-")))-1;
//      if (debug) { cout << min << endl; }
      line.erase(0, line.find("-")+1);

      int max = stoi(line.substr(0, line.find(" ")))-1;
//      if (debug) { cout << max << endl; }
      line.erase(0, line.find(" ")+1);

      char pwChar = line.substr(0, line.find(":"))[0];
//      if (debug) { cout << pwChar << endl; }
      line.erase(0, line.find(" ")+1);

      string pw = line;
//      if (debug) { cout << pw << endl; }

      int count = 0;
      if (pwChar == pw.substr(min, 1)[0]) {
        count++;
      }

      if (pwChar == pw.substr(max, 1)[0]) {
        count++;
      }

      if (count == 1 ) {
        valid++;
      }
    }

    myfile.close();
  }

  else cout << "Unable to open file";
  cout << valid << endl;
  return 0;
}
