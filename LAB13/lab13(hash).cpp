#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order
using namespace std;

/*STD fucntions*/
lli power(lli x, lli y, lli p)
{
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        //y must be even now
        y = y >> 1; //y=y/2
        x = (x * x) % p;
    }
    return res;
}
lli modi(lli a, lli m)
{
    // fermat little thm where m is prime
    return power(a, m - 2, m);
}
/*CODE BEGINS*/
const int tk = 1e7 + 19;
static bool ht[tk][4];
lli p[4];
int main()
{
    kira;
    p[0] = 53;
    p[1] = 389;
    p[2] = 769;
    p[3] = 1543;
    lli n;
    cin >> n;
    string s, t, temp;
    lli pro[105][4];
    forz(i, 105) forz(j, 4) pro[i][j] = 1;
    forz(j, 4)
    {
        for (int i = 1; i <= 100; i++)
        {
            pro[i][j] = (pro[i - 1][j] * p[j]) % tk;
        }
    }
    vector<string> v;
    forz(i, n)
    {
        cin >> s;
        v.pb(s);
        lli ss = lli(s.si);
        forz(j, 4)
        {
            lli h = 0;
            forz(k, ss)
            {
                if ('a' <= s[k] && s[k] <= 'z')
                    h = (h + (lli(s[k] - 'a' + 1) * pro[k][j]) % tk) % tk;
                else
                    h = (h + (lli(s[k] - 'A' + 27) * pro[k][j]) % tk) % tk;
            }
            ht[h][j] = true;
        }
    }
    forz(i, n)
    {
        temp = v[i];
        reverse(all(v[i]));
        t = v[i];
        if (temp == t)
            continue;
        lli st = t.si;
        int f = 1;
        forz(j, 4)
        {
            lli h = 0;
            forz(k, st)
            {
                if ('a' <= t[k] && t[k] <= 'z')
                    h = (h + (lli(t[k] - 'a' + 1) * pro[k][j]) % tk) % tk;
                else
                    h = (h + (lli(t[k] - 'A' + 27) * pro[k][j]) % tk) % tk;
            }
            if (ht[h][j] == false)
                f = 0;
        }
        if (f == 1)
        {
            p1("YES");
            return 0;
        }
    }
    p1("NO");
    return 0;
}
