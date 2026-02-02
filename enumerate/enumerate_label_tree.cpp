//#include "tree/prufer_recover.cpp"
//#include "enumerate/enumerate_bit.cpp"
//#include "enumerate/enumerate_twelvefold.cpp"

template<typename F>
requires invocable<F, vector<vector<int>>>
void enumerate_label_tree(int n, F f) {
  assert(n > 0);
  if (n == 1) {
    f(vector<vector<int>>(1));
  } else {
    enumerate_cartesian_power(n, n - 2, [n, f](vector<int> a) {
      f(adjacency_list<false>(n, prufer_recover(a), 0));
    });
  }
}
