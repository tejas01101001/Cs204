// BROWNIE TK
 
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
 
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define osetlli tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

using namespace std;

bool compare(string a,string b)
{
  if(a.si<b.si)return true;
  if(a.si>b.si)return false;

  	for(int i=0;i<a.si;i++)
  	{
  		if(a[i]<b[i])return true;
  		else if(a[i]>b[i])return false;
  	}

  return false;
}

string sub(string a,string b)
{
	if(compare(a,b))swap(a,b);
	string res="";
	lli carry=0;
	lli n=a.si;
	lli m=b.si;
	lli d=n-m;
	for(int i=m-1;i>=0;i--)
	{
      lli x=a[i+d]-'0';
      lli y=b[i]-'0';
      lli ans=x-y-carry;
      if(ans<0)
      {
      	ans+=10;
      	carry=1;
      }
      else carry=0;

      res.pb(ans%10+'0');
	}
	for(int i=d-1;i>=0;i--)
	{
      if(a[i]=='0'&&carry>0)
      {
      	res.pb('9');
      	continue;
      }
	  lli ans=a[i]-'0'-carry;
	  if(i>0||ans>0)
	  	res.pb(ans+'0');

	  carry=0;
	}
	reverse(all(res));
    lli cnt=0;
    for(auto x:res)
    {
    	if(x=='0')cnt++;
    	else break;
    }
    if(cnt==res.si)res="0";
    else res=res.substr(cnt,res.si-cnt);

	return res;
}


int main()
{
 kira;
 int t;
 cin>>t;
 string a,b;
 while(t--)
 {
 	cin>>a;
 	cin>>b;
  cout<<sub(a,b)<<endl;
 }
 return 0;
}
