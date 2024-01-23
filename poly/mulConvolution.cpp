//#include "../numtheory/primitiveRoot.cpp"
//#include "../numtheory/fastFactorize.cpp"
//#include "../poly/NTTmint.cpp"
//#include "../modint/MontgomeryModInt.cpp"

struct mulConvolution {
  const int P, root;
  vector<int> powR, logR;

  mulConvolution(int _P) : P(_P), root(primitiveRoot(_P)), powR(P - 1), logR(P, -1) {
    for(int i = 0, tmp = 1; i < P - 1; i++, tmp = (ll)tmp * root % P)
      powR[i] = tmp, logR[tmp] = i;
  }

  template<class Mint>
  vector<Mint> transform(vector<Mint> &f) {
    assert(ssize(f) == P);
    vector<Mint> g(P - 1);
    for(int i = 1; i < P; i++)
      g[logR[i]] = f[i];
    return g;
  }

  template<class Mint>
  vector<Mint> invTransform(vector<Mint> &f) {
    assert(ssize(f) == P - 1);
    vector<Mint> g(P);
    for(int i = 0; i < P - 1; i++)
      g[powR[i]] = f[i];
    return g;
  }

  template<class Mint>
  vector<Mint> mulConv(vector<Mint> a, vector<Mint> b, vector<Mint>(*conv)(vector<Mint>, vector<Mint>)) {
    a = transform(a), b = transform(b);
    a = conv(a, b);
    for(int i = P - 1; i < 2 * P - 3; i++)
      a[i - (P - 1)] += a[i];
    a.resize(P - 1);
    a = invTransform(a);
    return a;
  }
};
