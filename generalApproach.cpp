/**
 * template name: generalApproach
 * author: Misuki
 * last update: 2023/04/22
 * note: these may be useful when I have completely no idea on a problem D:
 *
 * draw a graph, observe the process
 *
 * try to model the problem in the most general way
 *
 * find invariant
 *
 * find equivalent condition
 *
 * observe a lower/upper bound, and try to achieve that bound
 *
 * observe optimal structure (consider brute force small case to see the structure may be a good choice)
 *
 * invent subtask
 *
 * extreme principle
 *
 * think what is important in the problem model
 *
 * think reversely
 *
 * brute force small cases
 *
 * think of trivial solution than try to optimize(especially for dp, atleast see the transition and try to optimize)
 *
 * Problem Specific technique:
 * 
 * expectation: linearity of expectation to decompose problem into easier ones
 *
 * game theory: start from the end state, bruteforce patterns, and observe the transition
 *
 * counting: try to find one to one bijection to get an object that is easier to count
 *
 *           sum of x * f(x) = sum of f(> x) over x (cool trick!)
 *
 *           double counting principle
 *
 *           group the objects by some characteristic and count for each group
 *
 * sorting(?): adjacent swap(i, i + 1) -> inversion
 *
 *             permutation swap(i, j) -> # of cycle
 *
 *             take then insert -> LIS
 *
 * interactive: # of query may be a hint
 *
 *              try to fix some element may be useful
 *
 * "consider all pair" problems: divide and conquer, iterate R and maintain for all L
 */
