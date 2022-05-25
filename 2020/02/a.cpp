#include <iostream>
#include <fstream>
using namespace std;

bool debug = true;

int valid = 0;

int main () {
  string line;

  ifstream myfile ("input");
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
//      if (debug) { cout << line << endl; }

      int min = stoi(line.substr(0, line.find("-")));
//      if (debug) { cout << min << endl; }
      line.erase(0, line.find("-")+1);

      int max = stoi(line.substr(0, line.find(" ")));
//      if (debug) { cout << max << endl; }
      line.erase(0, line.find(" ")+1);

      char pwChar = line.substr(0, line.find(":"))[0];
//      if (debug) { cout << pwChar << endl; }
      line.erase(0, line.find(" ")+1);

      string pw = line;
//      if (debug) { cout << pw << endl; }

      int count = 0;
      for (int i = 0; i < pw.size(); i++) {
        if (pw[i] == pwChar) {
          count++;

        }
      }

      if (count >= min && count <= max) {
        valid++;
      }
    }

    myfile.close();
  }

  else cout << "Unable to open file";
  cout << valid << endl;
  return 0;
}
