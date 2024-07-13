template<class T, size_t N>
array<T, N>& operator+=(array<T, N> &a, const array<T, N> &b) {
  for(size_t i = 0; i < N; i++) 
    a[i] += b[i];
  return a;
}
template<class T, size_t N>
array<T, N>& operator-=(array<T, N> &a, const array<T, N> &b) {
  for(size_t i = 0; i < N; i++) 
    a[i] -= b[i];
  return a;
}
template<class T, size_t N>
array<T, N> operator+(array<T, N> a, array<T, N> b) { return a += b; }
template<class T, size_t N>
array<T, N> operator-(array<T, N> a, array<T, N> b) { return a -= b; }
