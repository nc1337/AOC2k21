#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> points;
int MIN = INT_MAX;
int MAX = INT_MIN;
int mapping_size;

vector<vector<int>> mapping;

void input() {
  string line;
  while (cin >> line) {
    if (line[0] == '-')
      continue;
    size_t pos;
    while ((pos = line.find(",")) != string::npos) {
      int first = stoi(line.substr(0, pos), 0, 10);
      int second = stoi(line.substr(pos + 1), 0, 10);
      points.push_back(make_pair(first, second));
      line.erase(0, pos + 1);

      MIN = min(min(first, second), MIN);
      MAX = max(max(first, second), MAX);
    }
  }
  mapping_size = MAX - MIN + 1;
}

void markLines() {
  mapping.resize(mapping_size, vector<int>(mapping_size));
  for (int i = 0; i < points.size(); i += 2) {
    int x1 = points[i].first - MIN;
    int y1 = points[i].second - MIN;
    int x2 = points[i + 1].first - MIN;
    int y2 = points[i + 1].second - MIN;
    if (x1 == x2 || y1 == y2) {
      if (x1 == x2) {
        for (int j = min(y1, y2); j <= max(y1, y2); j++) {
          mapping[x1][j] += 1;
        }
      } else {
        for (int j = min(x1, x2); j <= max(x1, x2); j++) {
          mapping[j][y1] += 1;
        }
      }
    } else if (abs(y2 - y1) == abs(x2 - x1)) {
      // Diagonal lines;
      int dx = x2 > x1 ? 1 : -1;
      int dy = y2 > y1 ? 1 : -1;
      while (x1 != x2) {
        mapping[x1][y1] += 1;
        x1 += dx;
        y1 += dy;
      }
      mapping[x1][y1] += 1;
    }
  }
}

void printMap() {
  for (int i = 0; i < mapping_size; i++) {
    for (int j = 0; j < mapping_size; j++) {
      if (mapping[j][i] == 0)
        cout << ".";
      else
        cout << mapping[j][i];
    }
    cout << "\n";
  }
}

int countOverlap() {
  int cnt = 0;
  for (int i = 0; i < mapping_size; i++) {
    for (int j = 0; j < mapping_size; j++) {
      if (mapping[i][j] >= 2)
        cnt++;
    }
  }
  return cnt;
}

int main() {
  input();
  markLines();
  printMap();
  cout << countOverlap();
}
