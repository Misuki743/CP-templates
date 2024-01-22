bool isPrime(ull n) {
  if (n <= 1 or n % 6 % 4 != 1) return n == 2 or n == 3;
  for(unsigned __int128 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % n == 0) continue;
    ull d = (n - 1) >> countr_zero(n - 1);
    unsigned __int128 b = 1;
    while(d) {
      if (d & 1) b = b * a % n;
      a = a * a % n, d >>= 1;
    }
    if (b == 1) continue;
    for(int i = 0; i < countr_zero(n - 1) and b != n - 1; i++)
      b = b * b % n;
    if (b != n - 1)
      return false;
  }

  return true;
}
