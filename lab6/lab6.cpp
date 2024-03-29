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
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
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
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{
    return a * b / gcd(a, b);
}
lli modi(lli a, lli m)
{
    // fermat little thm where m is prime
    return power(a, m - 2, m);
}
/*CODE BEGINS*/

int main()
{
    kira;
    lli n, q;
    cin >> n >> q;
    lli que[q][3];
    lli id[q];
    lli val[q] = {0};
    lli temp, flag = 0, maxuid;
    forz(i, q)
    {
        cin >> que[i][0];
        if (que[i][0] == 1)
        {
            cin >> que[i][1] >> que[i][2];
            id[i] = que[i][1];
        }
    }
    sort(id, id + q);
    forz(i, q)
    {
        if (que[i][0] == 1)
        {
            temp = lb(id, id + q, que[i][1]) - id;
            val[temp] += que[i][2];

            if (flag == 0)
            {
                flag = 1;
                maxuid = temp;
            }
            else if (val[temp] > val[maxuid])
            {
                maxuid = temp;
            }
        }
        else
        {
            if (flag == 0)
                cout << "No data available" << endl;
            else
                cout << id[maxuid] << endl;
        }
    }
    return 0;
}
