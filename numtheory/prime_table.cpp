template<int32_t C>
class prime_table {
  static constexpr int32_t D = (C + 29) / 30 * 30;
  bitset<D / 2> table = {};

  public:

  vi prime;

  prime_table() : prime({2, 3, 5}) {
    table[3 / 2] = table[5 / 2] = true;
    for(int i = 0; i < D; i += 30) {
      table[(i + 01) / 2] = table[(i + 07) / 2] =
      table[(i + 11) / 2] = table[(i + 13) / 2] =
      table[(i + 17) / 2] = table[(i + 19) / 2] =
      table[(i + 23) / 2] = table[(i + 29) / 2] = true;
    }
    table[1 / 2] = false;

    const int32_t S = sqrtl(D) + 10;
    for(int i = 7, j = 4; i < S; i += j, j ^= 6) {
      if (table[i / 2]) {
        for(int k = ((i + 4) / 6 * 6 + 1) * i; k < D; k += 6 * i)
          table[k / 2] = false;
        for(int k = (i / 6 * 6 + 5) * i; k < D; k += 6 * i)
          table[k / 2] = false;
      }
    }

    prime.reserve(1.1 * D / log(D));
    for(int i = 0; i < D; i += 30) {
      if (table[(i + 01) / 2]) prime.emplace_back(i + 01);
      if (table[(i + 07) / 2]) prime.emplace_back(i + 07);
      if (table[(i + 11) / 2]) prime.emplace_back(i + 11);
      if (table[(i + 13) / 2]) prime.emplace_back(i + 13);
      if (table[(i + 17) / 2]) prime.emplace_back(i + 17);
      if (table[(i + 19) / 2]) prime.emplace_back(i + 19);
      if (table[(i + 23) / 2]) prime.emplace_back(i + 23);
      if (table[(i + 29) / 2]) prime.emplace_back(i + 29);
    }

    int n = ssize(prime) - 1;
    while(n >= 0 and prime[n] >= C) n--;
    prime.resize(n + 1);
  }

  bool is_prime(int x) { return x == 2 or ((x & 1) and table[x / 2]); }
  //make sure to not copy the array by using &x = prime_array()
  const vi& prime_array() { return prime; }
};
