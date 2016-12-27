// ==================================================
// Problem  :   1236 - Pairs Forming LCM
// Run time :   0.380 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

typedef     long long       LL;

vector<int> primes;

void sieve()
{
    const int RT = 1e7 + 3;

    bitset<RT> status;
    int rt = sqrt(RT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < RT; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < RT; i+=2)
        if(!status[i])
            primes.push_back(i);
}

int main()
{
    //freopen("in", "r", stdin);

    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        LL n;
        scanf("%lld", &n);

        int sz = primes.size();
        LL ans = 1;

        for(int i = 0; i < sz && LL(primes[i])*primes[i] <= n; ++i) {
            if(n % primes[i] == 0) {
                int pw = 0;

                while(n % primes[i] == 0) ++pw, n /= primes[i];

                ans *= (pw << 1) | 1;   // similar as, ans *= 2 * pw + 1
            }
        }

        if(n != 1) ans *= 3;

        ans = (ans >> 1) + 1;           // similar as, ans = ans / 2 + 1

        printf("Case %d: %lld\n", tc, ans);
    }

    return 0;
}
