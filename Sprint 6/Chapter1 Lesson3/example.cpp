#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

class Fibkind
{
public:
    static std::vector<int> cache;
    static int lengthSupUK(int n, int k)
    {
        seq(n);
        return std::count_if(cache.begin()+1, cache.begin() + n + 1,
            [k](int x) { return x >= k; });
    }
    static int comp(int n)
    {
        seq(n);
        return std::inner_product(cache.begin() + 1, cache.begin() + n, cache.begin() + 2, 0,
        std::plus<int>(),
        [](int a, int b) { return (a > b); });
    }
    static void seq(int n)
    {
      for(int i = cache.size(); i <= n; i++)
        cache.push_back( cache[ i - cache[i-1] ] + cache[ i - cache[i-2] ] );
    }
};
std::vector<int> Fibkind::cache = {0, 1, 1};

int main(){
    Fibkind fib;
    int n = 3332;
    int k = 973;
    std::cout << fib.lengthSupUK(n, k) << '\n';
    int m = 71749;
    std::cout << fib.comp(m);
}