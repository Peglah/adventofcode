#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;
const string file = "input";

int countAnswers(string groupAnswers, int groupSize);

int main () {
  int totalCount = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;
    string groupAnswers;
    int groupSize = 0;

    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        // Concat if line is not empty
        // and increment groupSize
        groupAnswers.append(line);
        groupSize++;
      } else {
        // Count answers and add to totalCount
        totalCount += countAnswers(groupAnswers, groupSize);
        groupAnswers = "";
        groupSize = 0;
      }
    }
    // Count the last group sinces the file does not end with an empty line.
    totalCount += countAnswers(groupAnswers, groupSize);
    myfile.close();
  }
  else cout << "Unable to open file" << endl;
  cout << endl << "Sum of counts: " << totalCount << endl;
  return 0;
}

int countAnswers(string groupAnswers, int groupSize) {
  int personCount = 0;
  int groupCount = 0;

  while (groupAnswers.length() != 0) {
    char c = groupAnswers[0];
    while (groupAnswers.find(c) != string::npos) {
      personCount++;
      groupAnswers.erase(groupAnswers.find(c), 1);
    }
    if (personCount == groupSize) {
      groupCount++;
      personCount = 0;
    } else {
      personCount = 0;
    }
  }
  return groupCount;
}
