#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

const string file = "input";

vector<bitset<12>> lines;
bitset<12> epsilon;
bitset<12> gamma;
int answer = 0;

int main () {
  ifstream myfile (file);
  if (myfile.is_open()) {
    string line;
    while (getline (myfile,line) ) {
      if (line.length() != 0) {
        lines.push_back(bitset<12>(line));
        //cout << line << " " << lines.back() << endl;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file" << endl;


  for (int i = 0; i < 12; i++) {
    int count = 0;
    for (int j = 0; j < lines.size() ; j++) {
      if (lines[j][i] == 1)
        count++;
    }
    if (count > lines.size()/2)
      gamma.set(i);

  }

  epsilon = gamma;
  gamma.flip();

  cout << "Gamma = " << gamma.to_string() << endl << "Epsilon = " << epsilon.to_string() << endl;

  answer = gamma.to_ulong() * epsilon.to_ulong();

  cout << endl << "Answer: " << answer << endl;
  return 0;
}
