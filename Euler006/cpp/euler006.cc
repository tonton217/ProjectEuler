#include <iostream>

/*
 * 1. 1 + 2 + ... + (n - 1) + n = n * (n + 1) / 2
 * 2. 1^2 + 2^2 + ... + (n - 1)^2 + n^2 = n * (n + 1) * (2 * n + 1) / 6
 * 3. (n * (n + 1) / 2)^2 - n * (n + 1) * (2 * n + 1) / 6
 *   = n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
 */

using namespace std;

uint64_t calc_sum_of_squares(uint64_t n) {
  return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
}

int main() {
  uint32_t t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << calc_sum_of_squares(n) << endl;
  }
  return 0;
}
