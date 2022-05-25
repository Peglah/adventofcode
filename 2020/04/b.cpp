#include <iostream>
#include <fstream>
using namespace std;

bool debug = false;

string file = "input";

int fileLines(string fileName);
int emptyLines(string fileName);
string purgeLine(string line, string erase);

bool checkValidation(string pp);

int main () {
  int lines = fileLines(file);
  cout << "Lines: " << lines << endl;
  cout << "Passports: " << emptyLines(file) << endl;

  string pps[emptyLines(file)]; // PassPortS
  int valid = 0;
  int invalid = 0;

  // Read input file and store in pps array
  ifstream myfile (file);
  if (myfile.is_open()) {
  string line;
  int ppp = 0; // PassPort Position
    string concatinatedLine;
    while (getline (myfile,line) ) {
      concatinatedLine += line + " ";
      if (line.length() == 0) {
        pps[ppp] = concatinatedLine;
        ppp++;
        concatinatedLine = "";
      }
    }
    pps[ppp] = concatinatedLine;
  }
  else cout << "Unable to open file" << endl;

  // Check for validation
  for ( int i = 0; i < emptyLines(file); i++ ) {
//    cout << "Idx " << i << " = " << pps[i] << endl;
    if (checkValidation(pps[i])) {
      valid++;
    } else invalid++;
  }

  cout << "Valid passports: " << valid << endl;
  cout << "Invalid passports: " << invalid << endl;
  return 0;
}

int fileLines(string fileName) {
  int count = 0;
  string line;

  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      count++;
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return count;
}

int emptyLines(string fileName) {
  int count = 0;
  string line;

  ifstream myfile (fileName);
  if (myfile.is_open()) {
    while ( getline (myfile,line) ) {
      if (line.length() == 0) {
        count++;
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  return count + 1;
}

string purgeLine(string line, string erase) {
  if (line.find(erase) != string::npos) {
    line.erase(line.find("cid:"), 4);
  }
  return line;
}

bool checkValidation(string pp) {
  // byr
  if (pp.find("byr:") != -1) {
    int byr = stoi(pp.substr(pp.find("byr:")+4, 4));
    if (byr < 1920 || byr > 2002) {
      if (debug) { cout << "byr out of range" << endl; }
      return false;
    }
  } else {
    if (debug) { cout << "byr missing" << endl; }
    return false;
  }

  // iyr
  if (pp.find("iyr:") != -1) {
    int iyr = stoi(pp.substr(pp.find("iyr:")+4, 4));
    if (iyr < 2010 || iyr > 2020) {
      if (debug) { cout << "iyr out of range" << endl; }
      return false;
    }
  } else {
    if (debug) { cout << "iyr missing" << endl; }
    return false;
  }

  // eyr
  if (pp.find("eyr:") != -1) {
    int eyr = stoi(pp.substr(pp.find("eyr:")+4, 4));
    if (eyr < 2020 || eyr > 2030) {
      if (debug) { cout << "eyr out of range" << endl; }
      return false;
    }
  } else {
    if (debug) { cout << "eyr missing" << endl; }
    return false;
  }

  // hgt
  if (pp.find("hgt:") != -1) {
    string unit;
    string temp = pp;

    temp = temp.erase(0, temp.find("hgt:")+4);
    temp = temp.substr(0, temp.find(" "));

    if (temp.find("cm") != string::npos) {
      unit = "cm";
    } else if (temp.find("in") != string::npos) {
      unit = "in";
    } else return false;

    int hgt = stoi(temp);

    if (unit == "cm" && (hgt < 150 || hgt > 193)) {
      if (debug) { cout << "hgt cm out of range" << endl; }
      return false;
    } else if (unit == "in" && (hgt < 59 || hgt > 76)) {
      if (debug) { cout << "hgt in out of range" << endl; }
      return false;
    }

  } else {
    if (debug) { cout << "hgt missing" << endl; }
    return false;
  }

  // hcl
  if (pp.find("hcl:#") != -1) {
    string hcl = pp;
    hcl.erase(0, hcl.find("#")+1);
    hcl = hcl.substr(0, hcl.find(" "));

    if (hcl.length() == 6) {
      char validHex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
      for ( int i = 0; i < hcl.length(); i++ ) {
        bool hexIsValid = false;
        for ( int j = 0; j < 16; j++ ) {
          if (hcl[i] == validHex[j]) {
            hexIsValid = true;
          }
        }
        if (!hexIsValid) {
          if (debug) { cout << "hcl is invalid" << endl; }
          return false;
        }
      }
    } else {
      if (debug) { cout << "hcl is not 6" << endl; }
      return false;
    }
  } else {
    if (debug) { cout << "hcl missing" << endl; }
    return false;
  }

  // ecl
  if (pp.find("ecl:") != -1) {
    string ecl = pp;
    ecl.erase(0, ecl.find("ecl:")+4);
    ecl = ecl.substr(0, ecl.find(" "));

    string validEcl[7] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
    bool colorIsValid = false;
    for ( int i = 0; i < 7; i++ ) {
      if (ecl == validEcl[i]) {
        colorIsValid = true;
      }
    }
    if (!colorIsValid) {
      if (debug) { cout << "ecl is invalid" << endl; }
      return false;
    }
  } else {
    if (debug) { cout << "ecl missing" << endl; }
    return false;
  }

  // pid
  if (pp.find("pid:") != -1) {
    string pid = pp;
    pid.erase(0, pid.find("pid:")+4);
    pid = pid.substr(0, pid.find(" "));

    if (pid.length() == 9) {
      char validDig[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
      for ( int i = 0; i < pid.length(); i++ ) {
        bool digIsValid = false;
        for ( int j = 0; j < 10; j++ ) {
          if (pid[i] == validDig[j]) {
            digIsValid = true;
          }
        }
        if (!digIsValid) {
          if (debug) { cout << "pid is invalid" << endl; }
          return false;
        }
      }
    } else {
      if (debug) { cout << "hcl is not 9" << endl; }
      return false;
    }


  } else {
    if (debug) { cout << "pid missing" << endl; }
    return false;
  }
  return true;
}
