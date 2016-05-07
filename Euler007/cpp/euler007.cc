#include <iostream>
#include <vector>

using namespace std;

std::vector<uint32_t> primes;

bool is_prime(uint32_t number) {
  for(auto& prime : primes) {
    if (prime * prime > number) return true;
    if (number % prime == 0) return false;
  }
  return true;
}

uint32_t find_nth_prime(uint32_t n) {
  auto count = primes.size();
  if (count >= n)
    return primes[n - 1];

  for (auto number = primes[count - 1] + 2; primes.size() < n; number += 2)
    if (is_prime(number))
      primes.push_back(number);

  return primes[n - 1];
}

int main() {
  uint32_t t, n;
  cin >> t;
  primes.reserve(10000);
  primes.push_back(2);
  primes.push_back(3);
  while(t--) {
    cin >> n;
    cout << find_nth_prime(n) << endl;
  }
}
