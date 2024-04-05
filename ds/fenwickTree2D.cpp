//source: KACTL

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
template<class T>
struct FT {
	vector<T> s;
	FT(int n) : s(n) {}
	void update(int pos, T dif) { // a[pos] += dif
		for (; pos < ssize(s); pos |= pos + 1) s[pos] += dif;
	}
	T query(int pos) { // sum of values in [0, pos)
		T res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(T sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= ssize(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

/**
 * Author: Simon Lindholm
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate() before init()).
 * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
 * Status: stress-tested
 */
template<class T1, class T2>
struct FT2 {
	vector<vector<T1>> ys; vector<FT<T2>> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, T1 y) {
		for (; x < ssize(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vector<T1>& v : ys) ranges::sort(v), ft.emplace_back(ssize(v));
	}
	int ind(int x, T1 y) {
		return (int)(ranges::lower_bound(ys[x], y) - ys[x].begin()); }
	void update(int x, T1 y, T2 dif) {
		for (; x < ssize(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	T2 query(int x, T1 y) {
		T2 sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};
