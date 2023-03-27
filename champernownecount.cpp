#include <bits/stdc++.h>
main() {
  long n, k, i = 0, t = 0, z = 0;
  std::cin >> n >> k;
  for (; ++i <= n; z %= k, t += !z)
    z = z * pow(10, floor(log10(i)) + 1) + i;
  std::cout << t;
}