template<uint32_t ver>
struct simpleMint {
  using mint = simpleMint;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static u32 mod;

  static constexpr u32 get_mod() { return mod; }
  static void set_mod(u32 _mod) { mod = _mod; }

  simpleMint() : a(0) {}
  simpleMint(const int64_t &b) : a((b % mod + mod) % mod) {}

  u32 a;

  mint pow(u64 k) const {
    mint res(1), base(*this);
    while(k) {
      if (k & 1)
        res *= base;
      base *= base, k >>= 1;
    }
    return res;
  }

  mint inverse() const { return (*this).pow(mod - 2); }
  u32 get() const { return a; }

  mint& norm() {
    a = (a >= mod ? a - mod : a < 0 ? a + mod : a);
    return *this;
  }

  mint& operator+=(mint b) {
    a += b.a;
    return (*this).norm();
  }
  mint& operator-=(mint b) {
    a -= b.a;
    return (*this).norm();
  }
  mint& operator*=(mint b) {
    a = (u64(a) * b.a) % mod;
    return *this;
  }
  mint& operator/=(mint b) {
    a = (u64(a) * b.inverse().a) % mod;
    return *this;
  }

  mint operator-() { return mint() - mint(*this); }
  bool operator==(mint b) { return a == b.a; }
  bool operator!=(mint b) { return a != b.a; }
  
  friend mint operator+(mint c, mint d) { return c += d; }
  friend mint operator-(mint c, mint d) { return c -= d; }
  friend mint operator*(mint c, mint d) { return c *= d; }
  friend mint operator/(mint c, mint d) { return c /= d; }

  friend ostream& operator<<(ostream& os, const mint& b) {
    return os << b.a;
  }
  friend istream& operator>>(istream& is, mint& b) {
    int64_t val;
    is >> val;
    b = mint(val);
    return is;
  }
};

template<> uint32_t simpleMint<0>::mod = 2;
using mint = simpleMint<0>;
