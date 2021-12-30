#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  vector<string> values;
  while (cin >> s) {
    values.push_back(s);
  }

  // Part 1
  // int len = values[0].length();
  // string gamma = "", epsilon = "";
  // for (int i = 0; i < len; i++) {
  //   int cnt = 0;
  //   for (const auto &val : values) {
  //     cnt += val[i] == '0' ? 1 : 0;
  //   }
  //   gamma += ((2 * cnt) > values.size()) ? "0" : "1";
  //   epsilon += ((2 * cnt) > values.size()) ? "1" : "0";
  // }
  // cout << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2);
  //
  string oxygen = "", co2 = "";
  int len = values[0].length();

  vector<string> oxygenLeft = values;
  vector<string> co2Left = values;

  for (int i = 0; i < len; i++) {
    int cnt = 0;
    for (const auto &val : oxygenLeft)
      cnt += val[i] == '0' ? 1 : -1;

    char mostCommonBit = cnt > 0 ? '0' : '1';
    auto it = oxygenLeft.begin();
    // Erasing the ones having the mostCommonBit
    while (it != oxygenLeft.end()) {
      if ((*it)[i] != mostCommonBit) {
        oxygenLeft.erase(it);
      } else {
        ++it;
      }
    }
  }

  for (int i = 0; i < len; i++) {
    int cnt = 0;
    for (const auto &val : co2Left)
      cnt += val[i] == '0' ? 1 : -1;

    char leastCommonBit = cnt > 0 ? '1' : '0';
    auto it = co2Left.begin();
    // Erasing the ones having the leastCommonBit
    while (it != co2Left.end()) {
      if ((*it)[i] != leastCommonBit) {
        co2Left.erase(it);
      } else {
        ++it;
      }
    }
  }
  cout << stoi(oxygenLeft[0], 0, 2) * stoi(co2Left[0], 0, 2) << endl;
}
