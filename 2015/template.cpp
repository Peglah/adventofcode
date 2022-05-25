#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;

string file = "input";

int main () {
  string line;
  int floor = 0;
  bool bsmntNotVisited = true;
  int firstVisit;

  ifstream myfile (file);
  if (myfile.is_open()) {
    int position = 0;
    while (getline (myfile,line) ) {
      while (line.length() > 0) {
        if (line.substr(0, 1) == "(") { floor++; }
        if (line.substr(0, 1) == ")") { floor--; }
        line.erase(0, 1);

        position++;
        if (floor == -1 && bsmntNotVisited) {
          firstVisit = position;
          bsmntNotVisited = false;
        }
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;
  cout << "Floor: " << floor << endl;
  cout << "Basement first visit at: " << firstVisit << endl;
  return 0;
}
