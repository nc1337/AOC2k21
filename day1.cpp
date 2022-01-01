#include <bits/stdc++.h>

using namespace std;

int main() {
  int cnt = 0;
  int depth;
  // int prev = -1;
  vector<int> depths;
  while (cin >> depth) {
    // Part 1
    // if(depth > prev && prev != -1) {
    //     cnt++;
    // }
    // prev = depth;
    depths.push_back(depth);
  }

  for (int i = 3; i < depths.size(); i++) {
    if (depths[i] > depths[i - 3]) {
      cnt++;
    }
  }

  cout << cnt << endl; // 1709 : 1761
}
