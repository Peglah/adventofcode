#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

const string file = "input_example";

vector<bitset<5>> lines;
int answer = 0;

bool calcCrit(vector<bitset<5>> myVector, int bitNum, string gas);
int findValue();

int main () {
  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;
    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        lines.push_back(bitset<5>(line));
        cout << line << " " << lines.back() << endl;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;


/*
  while (oxygen.size() > 1) {
    for (int i = 0; i < 5; i++) {
      int count = 0;
      for (int j = 0; j < lines.size() ; j++) {
        if (lines[j][i] == 1)
          count++;
      }
      if (count > lines.size()/2) {
        for (int j = 0; j < lines.size() ; j++) {
          if (lines[j][i] == 0)
            oxygen.erase(oxygen.begin()+j);
        }
      } else {
        for (int j = 0; j < lines.size() ; j++) {
          if (lines[j][i] == 1)
            oxygen.erase(oxygen.begin()+j);
        }

      }
    }
  }
*/

  cout << "First bitCrit is: " << calcCrit(lines, 4, "gas") << endl;
  //answer = gamma.to_ulong() * epsilon.to_ulong();
  //cout << endl << "Answer: " << answer << endl;
  return 0;
}

//Function to find the bit criteria.
//Take in a pointer to the vector and the gas (oxy, co2)
bool calcCrit(vector<bitset<5>> myVector, int bitNum, string gas) {
  // Doing stuff.
  int count = 0;
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector[i][bitNum] == 1) {
      count++;
    }
  }

  //Return the bool.
  if (count > myVector.size()/2) {
    return 1;
  } else {
    return 0;
  }
}

//Funtion find the value.
//Take in a vector and the bit criteria.
int findValue(vector<bitset<5>> myVector, int bitNum, bool bitCrit) {


//Loop for as long as the vector is greater then 1.

//Return the value.
  return 0;
}
