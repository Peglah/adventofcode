#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

const string file = "input_example";
const int bits = 5; // 12 bit numbers


int main () {

  //Variables
  vector<bitset<bits>> lines;
  ifstream fin(file);
  string line;

  //Read in file as a vector of bitsets
  while(fin >> line) {
    lines.push_back(bitset<bits>(line));
    cout << line << " " << lines.back() << endl;
  }

  //The code
  vector<bitset<bits>> oxygen_generator_rating = lines;
  vector<bitset<bits>> co2_scrubber_rating = lines;

  //cout << endl << "Answer: " << answer << endl;
  cout << "End" << endl;
  return 0;
}

// --Calculate bit criteria--

//To find oxygen generator rating, determine the most common value (0 or 1) in
//the current bit position, and keep only numbers with that bit in that
//position. If 0 and 1 are equally common, keep values with a 1 in the position
//being considered.

bool calcMostCommonBit(vector<bitset<bits>> myVector) {
  int oneCount = countOnes(myVector);
  if (oneCount >= myVector.size()/2) {
    return 1;
  } else {
    return 0;
  }
}

//To find CO2 scrubber rating, determine the least common value (0 or 1) in the
//current bit position, and keep only numbers with that bit in that position. If
//0 and 1 are equally common, keep values with a 0 in the position being
//considered.

bool calcLeastCommonBit(vector<bitset<bits>> myVector) {
  int oneCount = countOnes(myVector);
  if (oneCount < myVector.size()/2) {
    return 1;
  } else {
    return 0;
  }
}

int oneCount(vector<bitset<bits>> myVector) {
  int count = 0;
  for (int i = 0; i < myVector.size(); i++) {
    count += myVector[i][bits];
  }
  return count;
}

//Calculate life support rating
//which can be determined by multiplying the oxygen generator rating by the CO2
//scrubber rating.
//
//Keep only numbers selected by the bit criteria for the type of rating value
//for which you are searching. Discard numbers which do not match the bit
//criteria.
//If you only have one number left, stop; this is the rating value for which you
//are searching.
//Otherwise, repeat the process, considering the next bit to the right.
