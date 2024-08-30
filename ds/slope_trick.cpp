template<class T>
struct slope_trick {
  max_heap<T> L;
  min_heap<T> R;
  T mn, tag;

  //(x - a)+
  void add_x_minus_a(T a) {
    if (!L.empty())
      mn += max((L.top() + tag) - a, T(0));
    L.push(a - tag);
    R.push(L.top());
    L.pop();
  }

  //(a - x)+
  void add_a_minus_x(T a) {
    if (!R.empty())
      mn += max(a - (R.top() + tag), T(0));
    R.push(a - tag);
    L.push(R.top());
    R.pop();
  }

  void add_abs(T a) {
    add_x_minus_a(a), add_a_minus_x(a);
  }

  void prefix_min() {
    min_heap<T> x;
    R.swap(x);
  }

  void suffix_min() {
    max_heap<T> x;
    L.swap(x);
  }

  void shift(T d) { tag += d; }

  T eval(T x) {
    T y = mn;
    {
      max_heap<T> tmp = L;
      while(!tmp.empty()) {
        y += max((tmp.top() + tag) - x, T(0));
        tmp.pop();
      }
    }
    {
      min_heap<T> tmp = R;
      while(!tmp.empty()) {
        y += max(x - (tmp.top() + tag), T(0));
        tmp.pop();
      }
    }
    return y;
  }

  T query_min() { return mn; }

  array<T, 2> argmin() {
    return {L.empty() ? numeric_limits<T>::min() : L.top() + tag,
            R.empty() ? numeric_limits<T>::max() : R.top() + tag};
  }
};
