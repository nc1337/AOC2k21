#include <bits/stdc++.h>

using namespace std;

bool isWinner(vector<vector<int>> &grid) {
  for (int i = 0; i < 5; i++) {
    int row_count = 5;
    int col_count = 5;
    for (int j = 0; j < 5; j++) {
      row_count += grid[i][j];
      col_count += grid[j][i];
    }
    if (row_count == 0 || col_count == 0)
      return true;
  }
  return false;
}

void mark(vector<vector<int>> &grid, int num) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (grid[i][j] == num) {
        grid[i][j] = -1;
      }
    }
  }
}

int unmarkedSum(vector<vector<int>> &grid) {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (grid[i][j] != -1) {
        sum += grid[i][j];
      }
    }
  }
  return sum;
}

int main() {
  string s;
  cin >> s;
  vector<int> numbers;
  size_t pos;
  while ((pos = s.find(",")) != string::npos) {
    numbers.push_back(stoi(s.substr(0, pos), 0, 10));
    s.erase(0, pos + 1);
  }

  // Inputting the grids
  vector<vector<vector<int>>> grids;
  int cnt = 0;
  int n;
  vector<vector<int>> grid(5, vector<int>(5));
  while (cin >> n) {
    cnt++;
    grid[(cnt - 1) / 5][(cnt - 1) % 5] = n;
    if (cnt == 25) {
      cnt = 0;
      grids.push_back(grid);
    }
  }
  for (const auto &num : numbers) {
    for (int i = 0; i < grids.size(); ++i) {
      mark(grids[i], num);
    }

    for (int i = 0; i < grids.size(); ++i) {
      if (isWinner(grids[i])) {
        // cout << num << endl;
        // cout << i + 1 << " : " << grids.size() << endl;
        if (grids.size() != 1) {
          grids.erase(grids.begin() + i);
        } else {
          // cout << num << endl;
          cout << unmarkedSum(grids[i]) * num << "\n";
          return 0;
        }
      }
    }
  }
}
