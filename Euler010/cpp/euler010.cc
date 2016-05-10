#include <iostream>
#include <vector>

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
