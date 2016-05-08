#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

uint32_t find_largest_product(const string& number, uint32_t k) {
  uint32_t largest = 0;
  for (uint32_t i = 0, len = number.length() - k  + 1; i < len; ++i) {
    uint32_t product = 1;
    for (uint32_t j = i; j < i + k; ++j) {
      product *= number[j] - '0';
    }
    largest = max(largest, product);
  }
  return largest;
}

int main() {
  uint32_t t, k, n;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string number(n, '\0');
    cin >> number;
    cout << find_largest_product(number, k) << endl;
  }
  return 0;
}
