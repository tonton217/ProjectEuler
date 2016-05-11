#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

uint32_t char_to_digit(char ch) {
  return ch - '0';
}

uint32_t digit_to_char(uint32_t d) {
  return d + '0';
}

string calc_large_sum(const vector<string>& strings) {
  string result;
  result.reserve(60);
  uint32_t carry = 0;

  for (auto i = 49; i >= 0; --i) {
    auto sum = carry;
    for (auto& s : strings)
      sum += char_to_digit(s[i]);
    result.push_back(digit_to_char(sum % 10));
    carry = sum / 10;
  }

  while (carry) {
    result.push_back(digit_to_char(carry % 10));
    carry /= 10;
  }

  reverse(result.begin(), result.end());
  return result.substr(0, 10);
}

int main() {
  uint32_t n;
  cin >> n;
  vector<string> strings(n);
  for (uint32_t i = 0; i < n; ++i) {
    cin >> strings[i];
  }
  cout << calc_large_sum(strings) << endl;
  return 0;
}
