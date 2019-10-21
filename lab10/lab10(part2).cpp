//BROWNIE TK

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
#define fore(i, m, n) for (int i = m; i <= n; i++)
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
const int N = 1e6 + 5005;
int parent[N];
int size[N];
int value[N];
int n, m, c;
void make(lli v)
{
    parent[v] = v;
    size[v] = 1;
}
lli find(lli v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void merge(lli a, lli b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int index(int i, int j)
{
    return i * m + j;
}
int main()
{
    kira;
    cin >> n >> m >> c;
    int a[n + 2][m + 2];
    memset(a, -1, sizeof(a));
    fore(i, 1, n) fore(j, 1, m)
    {
        cin >> a[i][j];
        make(index(i, j));
    }
    fore(i, 1, n)
    {
        fore(j, 1, m)
        {
            if (a[i][j] == a[i - 1][j])
                merge(index(i, j), index(i - 1, j));
        }
    }
    fore(i, 1, n)
    {
        fore(j, 1, m)
        {
            if (a[i][j - 1] == a[i][j])
                merge(index(i, j - 1), index(i, j));
        }
    }
    lli maxi = -1, color = -1;
    fore(i, 1, n)
    {
        fore(j, 1, m)
        {
            lli x = find(index(i, j));
            if (size[x] > maxi)
            {
                maxi = size[x];
                color = a[i][j];
            }
        }
    }
    p2(maxi, color);
    return 0;
}
