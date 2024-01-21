//#include "poly/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"

template<class Mint>
struct FPS : vector<Mint> {

  static function<vector<Mint>(vector<Mint>, vector<Mint>)> conv;

  FPS(vector<Mint> v) { *this = v; }

  using vector<Mint>::vector;
  FPS& operator+=(FPS b) {
    if (ssize(*this) < ssize(b)) this -> resize(ssize(b), 0);
    for(int i = 0; i < ssize(b); i++)
      (*this)[i] += b[i];
    return *this;
  }

  FPS& operator-=(FPS b) {
    if (ssize(*this) < ssize(b)) this -> resize(ssize(b), 0);
    for(int i = 0; i < ssize(b); i++)
      (*this)[i] -= b[i];
    return *this;
  }

  FPS& operator*=(FPS b) {
    auto c = conv(*this, b);
    this -> resize(ssize(*this) + ssize(b) - 1);
    copy(c.begin(), c.end(), this -> begin());
    return *this;
  }

  FPS& operator*=(Mint b) {
    for(int i = 0; i < ssize(*this); i++)
      (*this)[i] *= b;
    return *this;
  }

  FPS& operator/=(Mint b) {
    b = Mint(1) / b;
    for(int i = 0; i < ssize(*this); i++)
      (*this)[i] *= b;
    return *this;
  }

  FPS shrink() {
    FPS F = *this;
    int size = ssize(F);
    while(size and F[size - 1] == 0) size -= 1;
    F.resize(size);
    return F;
  }

  FPS integral() {
    vector<Mint> Inv(ssize(*this) + 1);
    Inv[1] = 1;
    for(int i = 2; i < ssize(Inv); i++)
      Inv[i] = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod() % i];
    FPS Q(ssize(*this) + 1, 0);
    for(int i = 0; i < ssize(*this); i++)
      Q[i + 1] = (*this)[i] * Inv[i + 1];
    return Q;
  }

  FPS derivative() {
    assert(!this -> empty());
    FPS Q(ssize(*this) - 1);
    for(int i = 1; i < ssize(*this); i++)
      Q[i - 1] = (*this)[i] * i;
    return Q;
  }

  Mint eval(Mint x) {
    Mint base = 1, res = 0;
    for(int i = 0; i < ssize(*this); i++, base *= x)
      res += (*this)[i] * base;
    return res;
  }

  FPS inv(int k) { // 1 / FPS (mod x^k)
    assert(!this -> empty() and (*this)[0] != 0);
    FPS Q(1, 1 / (*this)[0]);
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      FPS P = (*this);
      P.resize(1 << i, 0);
      Q = Q * (FPS(1, 2) - P * Q);
      Q.resize(1 << i, 0);
    }
    Q.resize(k);
    return Q;
  }

  array<FPS, 2> div(FPS G) {
    FPS F = this -> shrink();
    G = G.shrink();
    assert(!G.empty());
    if (ssize(G) > ssize(F))
      return {{{}, F}};
    int n = ssize(F) - ssize(G) + 1;
    auto FR = F, GR = G;
    R::reverse(FR);
    R::reverse(GR);
    FPS Q = FR * GR.inv(n);
    Q.resize(n);
    R::reverse(Q);
    return {Q, (F - G * Q).shrink()};
  }

  FPS log(int k) {
    assert(!this -> empty() and (*this)[0] == 1);
    FPS Q = *this;
    Q = (Q.derivative() * Q.inv(k));
    Q.resize(k - 1);
    return Q.integral();
  }

  FPS exp(int k) {
    assert(!this -> empty() and (*this)[0] == 0);
    FPS Q(1, 1);
    for(int i = 1; (1 << (i - 1)) < k; i++) {
      FPS P = (*this);
      P.resize(1 << i, 0);
      Q = Q * (FPS(1, 1) + P - Q.log(1 << i));
      Q.resize(1 << i, 0);
    }
    Q.resize(k);
    return Q;
  }

  FPS pow(ll idx, int k) {
    if (idx == 0) {
      FPS res(k, 0);
      res[0] = 1;
      return res;
    }
    for(int i = 0; i < ssize(*this) and i * idx < k; i++) {
      if ((*this)[i] != 0) {
        Mint Inv = 1 / (*this)[i];
        FPS Q(ssize(*this) - i);
        for(int j = i; j < ssize(*this); j++)
          Q[j - i] = (*this)[j] * Inv;
        Q = (Q.log(k) * idx).exp(k);
        FPS Q2(k, 0);
        Mint Pow = (*this)[i].pow(idx);
        for(int j = 0; j + i * idx < k; j++)
          Q2[j + i * idx] = Q[j] * Pow;
        return Q2;
      }
    } 
    return FPS(k, 0);
  }

  vector<Mint> multieval(vector<Mint> xs) {
    int n = ssize(xs);
    vector<FPS> data(2 * n);
    for(int i = 0; i < n; i++)
      data[n + i] = {-xs[i], 1};
    for(int i = n - 1; i > 0; i--)
      data[i] = data[i << 1] * data[i << 1 | 1];
    data[1] = (this -> div(data[1]))[1];
    for(int i = 1; i < n; i++) {
      data[i << 1] = data[i].div(data[i << 1])[1];
      data[i << 1 | 1] = data[i].div(data[i << 1 | 1])[1];
    }
    vector<Mint> res(n);
    for(int i = 0; i < n; i++)
      res[i] = data[n + i][0];
    return res;
  }

  static vector<Mint> interpolate(vector<Mint> xs, vector<Mint> ys) {
    assert(ssize(xs) == ssize(ys));
    int n = ssize(xs);
    vector<FPS> data(2 * n), res(2 * n);
    for(int i = 0; i < n; i++)
      data[n + i] = {-xs[i], 1};
    for(int i = n - 1; i > 0; i--)
      data[i] = data[i << 1] * data[i << 1 | 1];
    res[1] = data[1].derivative().div(data[1])[1];
    for(int i = 1; i < n; i++) {
      res[i << 1] = res[i].div(data[i << 1])[1];
      res[i << 1 | 1] = res[i].div(data[i << 1 | 1])[1];
    }
    for(int i = 0; i < n; i++)
      res[n + i][0] = ys[i] / res[n + i][0];
    for(int i = n - 1; i > 0; i--)
      res[i] = res[i << 1] * data[i << 1 | 1] + res[i << 1 | 1] * data[i << 1];
    return res[1];
  }

  friend FPS operator+(FPS a, FPS b) { return a += b; }
  friend FPS operator-(FPS a, FPS b) { return a -= b; }
  friend FPS operator*(FPS a, FPS b) { return a *= b; }
  friend FPS operator*(FPS a, Mint b) { return a *= b; }
  friend FPS operator/(FPS a, Mint b) { return a /= b; }
};

NTT ntt;
using fps = FPS<mint>;
template<>
function<vector<mint>(vector<mint>, vector<mint>)> fps::conv = ntt.conv;

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int n, m; cin >> n >> m;
  fps f(n), g(m);
  for(mint &x : f)
    cin >> x;
  for(mint &x : g)
    cin >> x;

  auto [q, r] = f.div(g);
  cout << ssize(q) << ' ' << ssize(r) << '\n';
  cout << q << '\n';
  cout << r << '\n';

  return 0;
}
