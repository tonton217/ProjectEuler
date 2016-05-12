#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

uint32_t find_largest_product(const vector< vector<uint32_t> >& grid) {
  uint32_t largest = 0;
  for (size_t i = 0; i < 17; ++i) {
    for (size_t j = 0; j < 20; ++j) {
      auto product1 = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
      auto product2 = grid[j][i] * grid[j][i + 1] * grid[j][i + 2] * grid[j][i + 3];
      if (j < 17) {
        auto product3 = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
        auto product4 = grid[i][j + 3] * grid[i + 1][j + 2] * grid[i + 2][j + 1] * grid[i + 3][j];
        largest = max(largest, max(product3, product4));
      }
      largest = max(largest, max(product1, product2));
    }
  }
  return largest;
}

int main() {
  vector< vector<uint32_t> > grid(20, vector<uint32_t>(20));
  for (size_t i = 0, rows = grid.size(); i < rows; ++i)
    for (size_t j = 0, columns = grid[i].size(); j < columns; ++j)
      cin >> grid[i][j];
  cout << find_largest_product(grid) << endl;
  return 0;
}
