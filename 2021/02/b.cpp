#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string file = "input";

int hpos = 0;
int depth = 0;
int aim = 0;

int answer = 0;

int main () {
  int totalCount = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;

    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        string direction = line.substr(0, line.find(" "));
        int magnitude = stoi(line.substr(line.find(" ")+1));
        //cout << "Var direction: " << direction << endl;
        //cout << "Var magnitude: " << magnitude << endl;

        if (direction == "forward") {
          //cout << "Going forward..." << magnitude << endl;
          hpos += magnitude;
          depth += aim * magnitude;
        }
        if (direction == "down") {
          aim += magnitude;
        }
        if (direction == "up") {
          aim -= magnitude;
        }
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;
  answer = hpos * depth;
  cout << "hpos: " << hpos << ", depth: " << depth << endl;
  cout << endl << "Answer: " << answer << endl;
  return 0;
}
