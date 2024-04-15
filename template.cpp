// AUTHOR->DEV KUDAWLA
//----------------------------------------------------
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order(it return an iterator input is a value), order_of_key(input is index)
typedef tree<long long, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // *A.lower_bound(K)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long int
#define vl vector<long long>
#define nline cout << "\n"
#define n_digit(n) (int)log10(n) + 1
#define msb(n) (int)(log2(n)) + 1
// it is 1 based
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define ternary(a, b, c) ((a) ? (b) : (c))
#define yesno(a) a ? cout << "Yes" : cout << "No"
#define sroot(a) sqrt((long double)a)
#define Max(a, b) max((ll)a, (ll)b)
#define Min(a, b) min((ll)a, (ll)b)
//----------------------------------------------------
template <class T1, class T2>
ostream &operator<<(std::ostream &os, pair<T1, T2> &st)
{
    cout << "{ " << st.first << " " << st.second << " }";
    return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        is >> v[i];
    return is;
}
template <class T>
istream &operator>>(istream &is, vector<vector<T>> &v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            is >> v[i][j];
    return is;
}
template <class T>
ostream &operator<<(std::ostream &os, vector<T> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        os << v[i] << ((i == n - 1) ? "\n" : " ");
    return os;
}
template <class T>
ostream &operator<<(std::ostream &os, vector<vector<T>> &v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            os << v[i][j] << " ";
        os << "\n";
    }
    return os;
}
template <class T>
ostream &operator<<(std::ostream &os, set<T> &st)
{
    cout << "---------------------------------\n";
    for (auto i : st)
        cout << i << " ";
    nline;
    cout << "---------------------------------\n";
    return os;
}
template <class T>
ostream &operator<<(std::ostream &os, multiset<T> &st)
{
    cout << "---------------------------------\n";
    for (auto i : st)
        cout << i << " ";
    nline;
    cout << "---------------------------------\n";
    return os;
}
template <class T1, class T2>
ostream &operator<<(std::ostream &os, map<T1, T2> &st)
{
    cout << "-------------------------------\n";
    auto x = st.begin();
    while (x != st.end())
    {
        cout << x->first;
        cout << "  -> ";
        cout << x->second;
        nline;
        x++;
    }
    cout << "-------------------------------\n";
    return os;
}
template <class T>
vector<T> add(vector<T> v1, vector<T> v2)
{
    vector<T> v3 = v1;
    for (ll i = 0; i < v2.size(); i++)
        v3.push_back(v2[i]);
    return v3;
}
inline ll power2(ll n)
{
    ll answer = 0;
    if (n != 0)
        answer = msb(((ll)n) ^ ((ll)(n - 1))) - 1;
    return answer;
}
inline ll indexOf(ordered_multiset &st, ll value)
{
    return st.order_of_key(value);
}
inline ll valueAt(ordered_multiset &st, ll index)
{
    return *st.find_by_order(index);
}
inline ll indexOf(ordered_set &st, ll value)
{
    return st.order_of_key(value);
}
inline ll valueAt(ordered_set &st, ll index)
{
    return *st.find_by_order(index);
}
template <class T>
void Distinct(T &v, bool sorting = true)
{
    if (sorting)
        sort(begin(v), end(v));
    v.resize(unique(begin(v), end(v)) - begin(v));
}
//----------------------------------------------------
const ll N1 = 1000000007;
const ll N2 = 998244353;
//----------------------------------------------------
// MODULAR ARITHMETIC
inline ll expo(ll a, ll b, ll mod = LONG_LONG_MAX)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = ((__int128_t)res * a) % mod;
        a = ((__int128_t)a * a) % mod;
        b = b >> 1;
    }
    return res;
}
inline ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); } // FOR PRIME
inline ll mod_add(ll a, ll b, ll m = N1)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
inline ll mod_mul(ll a, ll b, ll m = N1)
{
    a = a % m;
    b = b % m;
    return (((__int128_t)(a * b) % m) + m) % m;
}
inline ll mod_sub(ll a, ll b, ll m = N1)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
inline ll mod_div(ll a, ll b, ll m = N1)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll ncr(ll n, ll r, bool mod_version = false, ll mod = N1)
{
    ll answer = 0;
    if (n >= r)
    {
        r = Min(r, n - r);
        if (mod_version == true)
        {
            ll a = 1;
            for (ll i = n; i >= n - r + 1; i--)
                a = mod_mul(a, i, mod);
            ll b = 1;
            for (ll i = 1; i <= r; i++)
                b = mod_mul(b, i, mod);
            b = mminvprime(b, mod);
            a = mod_mul(a, b, mod);
            answer = a;
        }
        else
        {
            ll a = 1;
            ll b = 1;
            for (ll i = n; i >= n - r + 1; i--)
            {
                a *= i;
                b *= (n - i + 1);
                ll g = __gcd(a, b);
                a /= g, b /= g;
            }
            answer = a / b;
        }
    }
    return answer;
}
ll factorial(ll n, bool mod_version = false, ll mod = N1)
{
    ll answer = 1;
    if (mod_version == true)
    {
        for (int i = 2; i <= n; i++)
            answer = mod_mul(answer, i, mod);
    }
    else
    {
        for (int i = 2; i <= n; i++)
            answer *= i;
    }
    return answer;
}
bool is_prime(ll a)
{
    if (a == 1)
        return false;
    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
//----------------------------------------------------
map<ll, ll> prime_factors(ll n, bool debug = false)
{
    map<ll, ll> answer;
    ll a = n;
    for (ll i = 2; i * i <= a; i++)
        while (a % i == 0)
            answer[i]++, a /= i;
    if (a > 1)
        answer[a]++;
    if (debug)
    {
        for (auto i : answer)
            cout << i.first << " -> " << i.second << "\n";
    }
    return answer;
}
//----------------------------------------------------
const int n_sieve = (20000008); // O(Nlog(log(N)))
vector<bool> prime_sieve(n_sieve + 1, true);
void initialise_sieve(vector<bool> &prime_sieve)
{
    prime_sieve[0] = false;
    prime_sieve[1] = false;
    for (ll i = 2; i * i < n_sieve; i++)
        if (prime_sieve[i] == true)
            for (ll j = 2; j * i < n_sieve; j++)
                prime_sieve[j * i] = false;
}
//----------------------------------------------------
// #define LOCAL_COMPILER
#ifdef LOCAL_COMPILER
#define dbg(x)            \
    cerr << #x << " -> "; \
    cout << x << "\n";
#endif
#ifndef LOCAL_COMPILER
#define dbg(x)
#endif
//----------------------------------------------------
// CODE STARTS HERE
//----------------------------------------------------
void solve(bool testCases = true)
{
    ll T = 1; //->TEST CASES
    if (testCases)
        cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        ll a=expo(10,n,N1);
        cout<< a;
        // vl v(n);
        // cin >> v;
        // Distinct(v);
        nline;
    }
    //--------------------------------------------
    //  CODE ENDS HERE
}
//----------------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //------------------------------------------------
    // initialise_sieve(prime_sieve);
    //------------------------------------------------

#ifdef LOCAL_COMPILER
    std::cout << std::fixed << std::setprecision(25);
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    solve(false);

#ifdef LOCAL_COMPILER
    auto stop = std::chrono::high_resolution_clock::now();
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;
#endif
    //------------------------------------------------
    return 0;
}
//----------------------------------------------------