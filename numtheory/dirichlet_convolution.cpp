template<class T>
vector<T> dirichlet_convolution(vector<T> a, vector<T> b) {
  assert(size(a) == size(b));
  vector<T> c(size(a));
  for(int i = 1; i < ssize(a); i++)
    for(int j = 1; i * j < ssize(a); j++)
      c[i * j] += a[i] * b[j];
  return c;
}
