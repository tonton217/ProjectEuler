#include <iostream>
#include <vector>

using namespace std;

int32_t find_special_pythagorean_triplet(uint32_t n) {
  for (uint32_t a = n / 3; a >= 3; --a) {
    uint32_t b = (n - a) * (n - a) - (a * a) / (2 * (n - a));
    if (a > b) continue;
    uint32_t c = n - a - b;
    if ((a * a + b * b) == (c * c))
      return a * b * c;
  }
  return -1;
}

int main() {
  uint32_t t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << find_special_pythagorean_triplet(n) << endl;
  }
  return 0;
}
