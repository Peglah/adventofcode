#include <iostream>
#include <fstream>
using namespace std;
enum class byte : unsigned char {} ;

bool debug = false;

string file = "input";

int getRow(string line);
int getColumn(string line);
int getSeatID(int row, int column);

bool firstRun = true;
u_int64_t sumID;

int main () {
  int lowestID;
  int highestID;

  // Read input file
  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;
    while ( getline (myfile,line) ) {
      if (debug) { cout << line << endl; }
      int seatID = getSeatID(getRow(line), getColumn(line));
      cout << seatID << endl;
      if (firstRun) {
        lowestID = seatID;
        highestID = seatID;
        firstRun = false;
      }
      if (seatID < lowestID) {
        lowestID = seatID;
      }
      if (seatID > highestID) {
        highestID = seatID;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;

  for ( int i = lowestID; i <= highestID; i++ ) {
    sumID += i;
  }

  ifstream myfile2 (file);
  if (myfile2.is_open()) {
    string line;
    while (getline(myfile2, line)) {
      sumID -= getSeatID(getRow(line), getColumn(line));
    }
    myfile2.close();
  }
  else cout << "Unable to open file again" << endl;

  cout << "Lowest seat ID is: " << lowestID << endl;
  cout << "Highest seat ID is: " << highestID << endl;
  cout << "My seat ID is: " << sumID << endl;
  return 0;
}

int getRow(string line) {
  unsigned char row = 0x00;
  unsigned char mask = 0x40;

  while (line.length() > 3) {
    if (line.substr(0, 1) == "B") {
      row = row | mask;
    }
    line.erase(0, 1);
    mask = mask >> 1;
  }
  if (debug) { cout << "Row = " << +row << endl; }
  return +row;
}

int getColumn(string line) {
  unsigned char column = 0x00;
  unsigned char mask = 0x04;
  line.erase(0, 7);

  while (line.length() > 0) {
    if (line.substr(0, 1) == "R") {
      column = column | mask;
    }
    line.erase(0, 1);
    mask = mask >> 1;
  }
  if (debug) { cout << "Column = " << +column << endl; }
  return +column;
}

int getSeatID(int row, int column) {
  int seatID = row * 8 + column;
  return seatID;
}
