#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;

int mvRight = 3;
int mvDown = 1;

string file = "input";

int fileLines(string fname);
int lineChars(string fname);

int main () {
  int lines = fileLines(file);
  int chars = lineChars(file);
//  cout << "Lines: " << lines << endl;
//  cout << "Chars: " << chars << endl;

  string line;
  string map[lines][chars];
  int encounter = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    int i = 0;
    while ( getline (myfile,line) ) {
      if (debug) { cout << "Line " << i << " : "; }
      for ( int j = 0; j < line.size(); j++ ) {
        map[i][j] = line[j];
        if (debug) { cout << map[i][j]; }
      }
      i++;
      if (debug) { cout << endl; }
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  int x = 0;
  int y = 0;
  while ( x < lines) {
    if (debug) { cout << "pos=" << x << "," << y << " "; }
    for ( int i = 0; i < chars; i++) {
      if (debug) { cout << map[x][i]; }
    }
    if (map[x][y] == "#") {
      encounter++;
      if (debug) { cout << map[x][y] << " =hitt" << endl; }
    }
    else {
     if (debug) {  cout << map[x][y] << " =miss" << endl; }
    }

    x += mvDown;
    y += mvRight;
    if (y >= chars) { y -= chars; }
  }

  cout << "Encounters: " << encounter << endl;
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
  }
  else cout << "Unable to open file";
  return count;
}

int lineChars(string fname) {
  int count = 0;
  string line;

  ifstream myfile (fname);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      count = line.size();
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return count;
}
