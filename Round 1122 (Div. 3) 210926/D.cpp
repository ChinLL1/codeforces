#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

const long long INF = 9223372036854775807;
const long long MOD = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define WATCH(key, val)                                                        \
  printf("Watched %s ->  %s \n", key, std::to_string(val).c_str());
#define WATCH_CONTAINER(key, val)                                              \
  printf("Watched %s : ", key);                                                \
  for (auto e : val)                                                           \
    printf(" %s", std::to_string(e).c_str());                                  \
  printf("\n");
#define WATCH_MAP(map)                                                         \
  printf("Watching Map\n");                                                    \
  for (auto e : map)                                                           \
    printf("%s -> %s\n", std::to_string(e.first).c_str(),                      \
           std::to_string(e.second).c_str());                                  \
  printf("\n");
#else
#define WATCH(key, val)                                                        \
  do {                                                                         \
  } while (false);
#define WATCH_CONTAINER(key, val)                                              \
  do {                                                                         \
  } while (false);
#define WATCH_MAP(map)                                                         \
  do {                                                                         \
  } while (false);
#endif

#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:247474112")
#endif

#define REP(n) for (int t = 0; t < n; t++)
#define FOR(i, n) for (i = 0; i < n; i++)
#define FFOR(i, j, n) for (i = j; j < n; j++)
#define FOR_S(i, n, k) for (i = 0; i < n; i += k)
#define RFOR(i, n) for (i = n - 1; i >= 0; i--)
#define RFOR_S(i, n, k) for (i = n - 1; i >= 0; i -= k)
#define MAX_OF(x, y) ((x > y) ? x : y)
#define MIN_OF(x, y) ((x > y) ? y : x)
#define MIN_IN(A) *(std::min_element(A.begin(), A.end()));
#define MAX_IN(A) *(std::max_element(A.begin(), A.end()));
#define MAX_AT(A) (std::max_element(A.begin(), A.end()) - A.begin());
#define MIN_AT(A) (std::min_element(A.begin(), A.end()) - A.begin());
#define TESTCASE                                                               \
  int testcase;                                                                \
  std::cin >> testcase;                                                        \
  while (testcase--)
#define GCD(a, b) std::__gcd(a, b);
#define LCM(a, b) (a) * ((b) / std::__gcd(a, b));
#define SORT(A) std::sort(A.begin(), A.end());
#define RSORT(A) std::sort(A.rbegin(), A.rend());
#define REVERSE(A) std::reverse(A.begin(), A.end());
#define ANY(container, result, condition)                                      \
  result = false;                                                              \
  for (const auto &e : container)                                              \
    if (condition(e)) {                                                        \
      result = true;                                                           \
      break;                                                                   \
    }
#define ALL(container, result, condition)                                      \
  result = true;                                                               \
  for (const auto &e : container)                                              \
    if (!condition(e)) {                                                       \
      result = false;                                                          \
      break;                                                                   \
    }
#ifdef INTERACTIVE_MODE
#define iprint(...)                                                            \
  printf(__VA_ARGS__);                                                         \
  fflush(stdout);
#else
#define iprint(...) printf(__VA_ARGS__);
#endif

#define LL long long
#define ll LL
#define L long
#define ULL unsigned long long
#define I int
#define D double
#define UI unsigned int
#define VEC(i) std::vector<i>
#define MAP(a, b) std::map<a, b>
#define UMAP(a, b) std::unordered_map<a, b>
#define SET(a) std::set<a>
#define USET(a) std::unordered_set<a>
#define MSET(a) std::multiset<a>
#define STR std::string
#define PAIR(a, b) std::pair<a, b>
#define PAIRI std::pair<int, int>
#define READ_INT(var) scanf("%d", &var)
#define READ_STR(var) std::cin >> var
#define READ_LONG(var) scanf("%lld", &var)
#define WRITE_INT(var) printf("%d", var)
#define WRITE_LONG(var) printf("%lld", var)
#define WRITE_STR(var) std::cout << var
#define WRITE_VEC_LL(val)                                                      \
  for (auto e : val)                                                           \
    printf("%lld ", e);
#define WRITE_VEC_I(val)                                                       \
  for (auto e : val)                                                           \
    printf("%d ", e);

#define pb push_back
#define eb emplace_back

LL power(LL x, ULL y) {
  // returns  x^y % p
  LL res = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LL t;
  cin >> t;

  while (t--) {
    LL n;
    cin >> n;
    LL x;
    
    vector<LL> V;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        V.push_back(x - i);        // push their value - position since this is a constant regardless of how much they change.
    }
    sort(V.begin(), V.end()); // cause dont matter where they sit, we wanna find longest sequence of +1s. that is the ans
    // next remove the duplicated kids
    int j = 0; // Tracks the position of the last unique element
    
    for (int i = 1; i < V.size(); ++i) {
        if (V[i] != V[j]) {
            j++;
            V[j] = V[i];
        }
    }

    int ans = 0, cur = 1;
    for (int i = 1; i < n; ++i) {
        if (V[i] == V[i-1] + 1) cur++;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);

    cout << ans << endl;

  }    
}