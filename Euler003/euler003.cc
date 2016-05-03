#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 1. 소인수 분해를 응용.
 * 2. 가장 작은 소수인 2부터 시작하여 나누어 떨어지지 않을 때까지 나눈다.
 * 3. 2로 더 이상 나눠지지 않는다면 3, 5, 7 등 숫자를 증가시키며 같은 작업을 반복.
 * 4. 2를 제외하면 짝수는 소수에 존재하지 않기 때문에
 *   숫자의 증가량은 2씩 증가 시킨다.
 * 5. 나누어 떨어지는 인수는 항상 쌍으로 존재하기 때문에
 *   인수의 제곱이 n보다 커지면 루프를 종료한다.
 * 6. 나누고 난 뒤 마지막에 남은 n 또한 소수 인수이기 때문에 return하기 전에
 *   가장 큰 소수 인자값과 비교하여 더 큰 값을 return한다.
 */

using namespace std;

uint64_t find_largest_prime_factor(uint64_t n) {
  uint64_t largest = 0;
  for(uint64_t factor = 2; factor * factor <= n; factor += 2) {
    while (n % factor == 0) {
      largest = max(largest, factor);
      n /= factor;
    }
    if (factor == 2)
      factor--;
  }
  return max(largest, n);
}

int main() {
  uint32_t t;
  cin >> t;
  while(t--) {
    uint64_t n;
    cin >> n;
    cout << find_largest_prime_factor(n) << endl;
  }
  return 0;
}
