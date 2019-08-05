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

struct node
{
    int x,y;
    node* next;
};

node* head=NULL;

void Addfirst(int x,int y)
{
    node* nn=new node;
    nn->x=x;
    nn->y=y;
    nn->next=head;
    head=nn;
}

int delfirst()
{
    if(head==NULL)return -1;
    node* nn=head;
    head=head->next;
    delete nn;
    return 0;
}

int del(int x,int y)
{
    node* curr=head;
    node* prev=NULL;
    int a,b;
    while(curr!=NULL)
    {
        a=curr->x;
        b=curr->y;
        if(a==x&&b==y)
        {
            if(curr==head)
            {
                head=head->next;
            }
            else
            {
                prev->next=curr->next;
            }
            delete curr;
            return 0;
        }
        prev=curr;
        curr=curr->next;
    }
    return -1;
}

void search(ldb d)
{
    node* curr=head;
    int flag=0;
    int a,b;
    while(curr!=NULL)
    {
        a=curr->x;
        b=curr->y;
        if(a*a+b*b<=d*d)
        {
            flag=1;
            cout<<"("<<a<<","<<b<<")"<<" ";
        }
        curr=curr->next;
    }
    if(flag==0)cout<<-1;
    cout<<endl;
    return;
}

void search(int x,int y)
{
    node* curr=head;
    int a,b;
    while(curr!=NULL)
    {
        a=curr->x;
        b=curr->y;
        if(a==x&&b==y)
        {
            cout<<"True"<<endl;
            return;
        }
        curr=curr->next;
    }
    cout<<"False"<<endl;
}

int length()
{
    node* curr=head;
    int count=0;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    return count;
}

int main()
{
    kira;
    int t;
    cin>>t;
    while(t--)
    {
        int q,x,y;
        cin>>q;
        if(q==1)
        {
            cin>>x>>y;
            Addfirst(x,y);
        }
        else if(q==2)
        {
            cout<<delfirst()<<endl;
        }
        else if(q==3)
        {
            cin>>x>>y;
            cout<<del(x,y)<<endl;
        }
        else if(q==4)
        {
            ldb d;
            cin>>d;
            search(d);
        }
        else if(q==5)
        {
            cin>>x>>y;
            search(x,y);
        }
        else if(q==6)
        {
            cout<<length()<<endl;
        }
    }
    return 0;
}





