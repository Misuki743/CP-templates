
template<typename F, typename INT>
requires invocable<F, INT>
void enumerate_subset(INT msk, F f) {
  for(INT x = msk; x > 0; x = (x - 1) & msk)
    f(x);
  f(0);
}
