#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string file = "input";

vector<int> lines;
vector<int> windows;
int answer = 0;

bool first = true;

int main () {
  int totalCount = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;

    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        lines.push_back(stoi(line));
      }
    }
    myfile.close();

    for (int i = 0; i < lines.size(); i++) {
      windows.push_back(lines[i]+lines[i+1]+lines[i+2]);
    }
    for (int i = 0; i < windows.size()-1; i++) {
      if (windows[i+1] > windows[i]) {
        answer++;
      }
    }
  }
  else cout << "Unable to open file" << endl;
  cout << endl << "Answer: " << answer << endl;
  return 0;
}
