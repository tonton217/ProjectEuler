#include <iostream>

using namespace std;

uint64_t sum_of_1_to_n(uint64_t n) {
  return (n * (n + 1)) / 2;
}

uint64_t calc_sum_of_multiples_of_3_or_5(uint32_t n) {
  uint32_t multi3Count = (n - 1) / 3;
  uint64_t multi3Sum = 3 * sum_of_1_to_n(multi3Count);
  uint32_t multi5Count = (n - 1) / 5;
  uint64_t multi5Sum = 5 * sum_of_1_to_n(multi5Count);
  uint32_t multi15Count = (n - 1) / 15;
  uint64_t multi15Sum = 15 * sum_of_1_to_n(multi15Count);

  return multi3Sum + multi5Sum - multi15Sum;
}

int main() {
  uint32_t t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << calc_sum_of_multiples_of_3_or_5(n) << endl;
  }
  return 0;
}
