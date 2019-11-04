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
const int N=1e6+5;
lli parent[N],size[N];
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
struct edge
{
    lli u, v, weight;
    bool operator<(edge const &other)
    {
        return weight > other.weight;
    }
};
int main()
{
    kira;
    lli n,m,u,v,w;
    cin>>n>>m;
    for(int i=1;i<=n;i++)make(i);
    vector<edge> edges,vk;
    forz(i,m)
    {
        cin>>u>>v>>w;
        edges.pb({u,v,w});
    }
    lli cost = 1;
    sort(all(edges));
    for (edge e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            cost =(cost*e.weight)%mod;
            vk.pb(e);
            merge(e.u, e.v);
        }
    }
    cout<<cost;
    return 0;
}