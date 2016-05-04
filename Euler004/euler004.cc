#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string& number) {
  string reverse_number(number);
  reverse(reverse_number.begin(), reverse_number.end());
  return (number == reverse_number);
}

uint32_t find_largest_palindrome_product(uint32_t n) {
  uint32_t largest = 101101;
  for (uint32_t i = 999; i > 100; --i) {
    for (uint32_t j = 999; j > 100; --j) {
      auto product = i * j;
      if (product > n || largest >= product)
        continue;
      if (is_palindrome(to_string(product)))
        largest = product;
    }
  }
  return largest;
}

int main() {
  uint32_t t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << find_largest_palindrome_product(n) << endl;
  }
  return 0;
}
