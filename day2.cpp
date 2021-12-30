#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int hpos = 0, depth = 0, aim = 0;
  while (cin >> s) {
    int val;
    cin >> val;
    if (s[0] == 'f') {
      hpos += val;
      depth += aim * val;
    } else if (s[0] == 'd') {
      aim += val;
      // depth += val;
    } else {
      aim -= val;
      // depth -= val;
    }
  }
  cout << hpos * depth << "\n";
}
