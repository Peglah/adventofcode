#include <iostream>
#include <fstream>
using namespace std;

const string file = "input";

int oldLine = 0;
int newLine = 0;
int answer = 0;

bool first = true;

int main () {
  int totalCount = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;

    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        if (first) {
          oldLine = stoi(line);
          first = !first;
        } else {
          newLine = stoi(line);
          if (newLine > oldLine) { answer++; }
          oldLine = newLine;
        }
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;
  cout << endl << "Answer: " << answer << endl;
  return 0;
}
