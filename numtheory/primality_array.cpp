template<int32_t C>
bitset<C> primality_array() {
  bitset<C> is_prime;
  is_prime.set();
  for(int i : {0, 1})
    if (i < C)
      is_prime[i] = false;
  for(int i = 2; i < C; i++)
    if (is_prime[i])
      for(int j = 2 * i; j < C; j += i)
        is_prime[j] = false;
  return is_prime;
}
