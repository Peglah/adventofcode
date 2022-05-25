#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

bool debug = false;

string file = "input";

int countDistinct(string s);

int main () {

  string line;
  int sum = 0;

  ifstream myfile (file);
  if (myfile.is_open()) {
    string concatinatedLine = "";
    while (getline (myfile,line) ) {

      concatinatedLine += line;

      if (line.length() == 0) {
        if (debug) { cout << concatinatedLine << endl;
        cout << countDistinct(concatinatedLine) << endl; }
        sum += countDistinct(concatinatedLine);
        concatinatedLine = "";
      }
    }
    if (debug) { cout << concatinatedLine << endl;
    cout << countDistinct(concatinatedLine) << endl; }
    sum += countDistinct(concatinatedLine);
    concatinatedLine = "";

    myfile.close();
  }

  else cout << "Unable to open file" << endl;
  cout << "Sum of counts: " << sum << endl;
  return 0;
}

int countDistinct(string s) {
  unordered_map<char, int> m;
  for (int i = 0; i < s.length(); i++) {
    m[s[i]]++;
 }
 return m.size();
}
