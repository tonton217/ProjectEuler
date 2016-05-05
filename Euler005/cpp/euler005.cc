#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * 1. 두 수의 최소공배수를 구하기 위해 먼저 최소공약수를 찾는다.
 *  lcm(a, b) = a * b / gcd(a, b)
 * 2. 두 수의 최소공약수는 유클리드 호제법을 통하여 구한다.
 * 3. 유클리드 호제법
 *  - 1071과 1029의 최대공약수 구하기
 *   1071 = 1029 * 1 + 42
 *   1029 = 42 * 24 + 21
 *   42 = 21 * 2
 *   gcd = 21
 * 4. 1 ~ n까지의 최소공배수는 1과 2의 최소공배수를 구하고,
 *  그 최소공배수와 3의 최소공배수를 구하고
 *  그 최소공배수와 4의 최소공배수를 구하며
 *  n까지의 최소공배수를 구하면 된다.
 */

uint32_t find_gcd(uint32_t num1, uint32_t num2) {
  uint32_t bigger = max(num1, num2);
  uint32_t smaller = min(num1, num2);
  while (bigger % smaller != 0) {
    uint32_t temp = bigger % smaller;
    bigger = smaller;
    smaller = temp;
  }
  return smaller;
}

uint32_t find_lcm(uint32_t num1, uint32_t num2) {
  return num1 * num2 / find_gcd(num1, num2);
}

uint32_t find_smallest_multiple(uint32_t n) {
  int multiple = 1;
  for (uint32_t i = 2; i <= n; ++i) {
    multiple = find_lcm(multiple, i);
  }
  return multiple;
}

int main(void) {
  uint32_t t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    cout << find_smallest_multiple(n) << endl;
  }
}
