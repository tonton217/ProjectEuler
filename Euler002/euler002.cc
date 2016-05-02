#include <iostream>
#include <vector>

/*
 * 1. f(n + 2) = f(n + 1) + f(n)
 * 2. f(n + 6) = f(n + 5) + f(n + 4) = f(n + 4) + f(n + 3) + f(n + 4)
 *    = 2f(n + 4) + f(n + 3) = 2(f(n + 3) + f(n + 2)) + f(n + 3)
 *    = 3f(n + 3) + 2f(n + 2) = 3f(n + 3) + 2(f(n + 1) + f(n))
 *    = 3f(n + 3) + 2f(n + 1) + 2f(n)
 * 3. f(n + 3) = f(n + 2) + f(n + 1) = f(n + 1) + f(n) + f(n + 1)
 *    = 2f(n + 1) + f(n)
 * 4. 2f(n + 1) = f(n + 3) - f(n)
 * 5. f(n + 6) = 3f(n + 3) + f(n + 3) - f(n) + 2f(n) = 4f(n + 3) + f(n)
 * 6. Even fibonacci numbers:
 *    f(n + 2) = 4f(n + 1) + f(n), f(1) = 2, f(2) = 8
 */

using namespace std;

uint64_t calc_sum_of_even_fibonacci_numbers(uint64_t n) {
  uint64_t pre_even_f = 2, even_f = 8, sum = pre_even_f;
  do {
    sum += even_f;
    auto temp = even_f;
    even_f = 4 * even_f + pre_even_f;
    pre_even_f = temp;
  } while (even_f < n);
  return sum;
}

int main() {
  uint32_t t;
  cin >> t;
  while(t--) {
    uint64_t n;
    cin >> n;
    cout << calc_sum_of_even_fibonacci_numbers(n) << endl;
  }
  return 0;
}
