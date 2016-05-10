#include <iostream>
#include <vector>

/*
 * - Sieve of Eratosthenes
 * 1. n까지의 소수를 구하고자 할 때 적합
 * 2. n까지의 값을 체크할 수 있는 배열을 만들고, 2부터 배수를 지워가며 소수를 찾는 방법.
 *  ex) 10까지의 소수를 찾을 때
 *    2 3 4 5 6 7 8 9 10
 *    - 2는 소수. 2의 배수 제거
 *    3 5 7 9
 *    - 3은 소수. 3의 배수 제거
 *    5 7
 *    - 5와 7은 소수.
 * 3. 에라토스테네스의 체에서 루프를 줄일 수 있는 방법.
 *  - 소수 중 짝수는 2밖에 존재할 수 없음. 짝수를 제외한 숫자에서만 탐색
 *  - 배수를 찾는 것은 소수의 제곱이 n보다 작을 때까지만 찾으면 됨.
 *   120까지 소수를 찾을 때 11의 경우 2~10배까지 이미 이전에 이전에 계산을 했고,
 *   11 * 11은 121이기 때문에 계산할 필요가 없음.
 *  - 배수를 찾을 때 소수 * 소수부터 배수를 찾으면 됨.
 *   100까지 소수를 찾을 때 5의 배수를 제거하는 경우 이미 앞서 2, 3, 4배수는 제거되었으므로,
 *   5 * 5부터 배수를 제거해 나가면 됨. 여기서 짝수 배수는 짝수이므로 건너뛰고 배수를 체크하면 됨.
 */

using namespace std;

const uint32_t max_number = 100;

vector<uint32_t> find_primes() {
  bitset<max_number / 2> flags;
  vector<uint32_t> primes;
  primes.reserve(2000);
  for (uint32_t i = 3; i * i <= max_number; i += 2) {
    if (flags[(i - 1) / 2])
      continue;
    for (uint32_t j = i * i; j <= max_number; j += (i * 2))
      flags.set((j - 1) / 2);
  }
  primes.push_back(2);
  for (uint32_t i = 1; i < max_number / 2; ++i) {
    if (!flags[i])
      primes.push_back(i * 2 + 1);
  }
  return primes;
}

vector<uint64_t> get_sums_of_primes() {
  vector<uint64_t> sums(max_number);
  auto primes = find_primes();
  uint64_t sum = 0;
  size_t index = 0;
  for (uint32_t num = 1; num <= max_number; ++num) {
    auto prime = primes[index];
    if (prime <= num) {
      sum += prime;
      index++;
    }
    sums[num - 1] = sum;
  }
  return sums;
}

int main() {
  uint32_t t, n;
  cin >> t;
  auto sums = get_sums_of_primes();
  while (t--) {
    cin >> n;
    cout << sums[n - 1] << endl;
  }
}
