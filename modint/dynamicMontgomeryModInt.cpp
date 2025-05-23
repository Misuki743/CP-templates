//reference: https://github.com/NyaanNyaan/library/blob/master/modint/montgomery-modint.hpp#L10
//note: mod should be an odd prime less than 2^30.

template<uint32_t ver>
struct MontgomeryModInt {
  using mint = MontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static u32 mod, n2, r;

  static constexpr u32 get_r() {
    u32 res = 1, base = mod;
    for(i32 i = 0; i < 31; i++)
      res *= base, base *= base;
    return -res;
  }

  static constexpr u32 get_mod() {
    return mod;
  }

  static void set_mod(u32 _mod) {
    mod = _mod;
    n2 = -u64(mod) % mod;
    r = get_r();
  }

  u32 a;

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * r) * mod) >> 32;
  }

  static u32 transform(const u64 &b) {
    return reduce(u64(b) * n2);
  }

  MontgomeryModInt() : a(0) {}
  MontgomeryModInt(const int64_t &b) 
    : a(transform(b % mod + mod)) {}

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

  u32 get() const {
    u32 res = reduce(a);
    return res >= mod ? res - mod : res;
  }

  mint& operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint& operator/=(const mint &b) {
    a = reduce(u64(a) * b.inverse().a);
    return *this;
  }

  mint operator-() { return mint() - mint(*this); }
  bool operator==(mint b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(mint b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }

  friend mint operator+(mint c, mint d) { return c += d; }
  friend mint operator-(mint c, mint d) { return c -= d; }
  friend mint operator*(mint c, mint d) { return c *= d; }
  friend mint operator/(mint c, mint d) { return c /= d; }

  friend ostream& operator<<(ostream& os, const mint& b) {
    return os << b.get();
  }
  friend istream& operator>>(istream& is, mint& b) {
    int64_t val;
    is >> val;
    b = mint(val);
    return is;
  }
};

using mint = MontgomeryModInt<0>;
template<> uint32_t mint::mod = 0;
template<> uint32_t mint::n2 = 0;
template<> uint32_t mint::r = 0;
