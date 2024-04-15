// //AUTHOR-> KAUSHIK
// //---------------------------
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //includes containers or group of templates as set, multimap, map,tree etc
// #include <ext/pb_ds/tree_policy.hpp> //includes tree_order_statistics_node update
// using namespace std;
// using namespace __gnu_pbds; //for GNU based Policy based data structures
// typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; //find_by_order(it return an iterator)-finding kth smallest element, order_of_key(k)-no of ements strictly less than k in log(n), o_set.erase(o_set.find(k));
// //<insert KEY, null_type for set and mapped_type for map, for comparsion, type of tree used Red black tree takes log(n) for insertion & deletion, contains operations as update the node and number of nodes;
// typedef tree<long long, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // for multiset use multiset<int,greater<int>>::iterator itr, multiset<int,greater<int>>ms1(random order and not unique), multiset<int>ms2(ms1.begin(),ms1.end()) - sorted order and not unique), ms1.erase(k)-removes all elements=k, ms1.erase(ms1.find(k))-only one k removes, lower&upeer bound are different in ms1 & ms2
// #pragma GCC optimize("Ofast")
// //#pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #define ll long long int
// #define vl vector<long long>
// #define nline cout << "\n"
// #define pll pair<ll, ll>
// #define all(x) x.begin(), x.end()
// #define ternary(a,b,c) ((a) ? (b) : (C))
// #define yesno(a) a ? cout << "YES" : cout << "NO"
// #define sqroot(a) sqrt((long double)a)
// #define n_digit(n) (int)log10(n) + 1
// #define msb(n) (int)(log2(n)) + 1
// #define Max(a,b) max((ll)a, (ll)b)
// #define Min(a, b) min((ll)a, (ll)b)
// #define rep(i, a, b) for (auto i = a; i < b; i++)
// #define sz(x) static_cast<long long>((x).size())
// #define sortv(v) sort(v.begin(),v.end())

// //--------------------------------------------------------

// template <class T1,class T2>
// ostream &operator<<(std::ostream &os, pair<T1, T2> &st)
// {
//     cout << "{ " << st.find << " " << st.second << " }";
//     return os;
// }

// template <class T>
// istream &operator>>(istream &is, vector<T> &v)
// {
//     int n=v.size();
//     for(int i=0;i<n;i++){
//         is >> v[i];
//     }
//     return is;
// }

// template <class T>
// istream &operator>>(istream &is, vector<vector<T>> &v)
// {
//     int n=v.size();
//     int m=v[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             is >> v[i][j];
//         }
//     }
//     return is;
// }
// template <class T>
// ostream &operator<<(ostream &os, set<T> &st)
// {
//     for(auto i: st){
//         cout << st << " ";
//     }
//     nline;
//     return os;
// }
// template <class T>
// ostream &operator<<(ostream &os, multiset<T> &st)
// {
//     for(auto i: st){
//         cout << st << " ";
//     }
//     nline;
//     return os;
// }
// template <class T1, class T2>
// ostream &operator<<(ostream &os, map<T1, T2> &st)
// {
//     auto x=st.begin();
//     while(x != st.end()){
//         cout << x->first << " -> " << x->second;
//         nline;
//         x++;
//     }
//     return os;
// }
// template <class T>
// vector<T> add(vector<T> v1, vector<T> v2)
// {
//     vector<T> v3 = v1;
//     for(ll i=0;i<v2.size();i++){
//         v3.push_back(v2[i]);
//     }
//     return v3;
// }
// inline ll power2(ll n){
//     ll ans=0;
//     if(n != 0)
//         ans = msb(((ll)n) ^ ((ll)(n-1))) - 1;
//     return ans;
// }
// inline ll orderOf(ordered_multiset &st, ll value) //or indexoof
// {
//     return st.order_of_key(value);
// }
// inline ll valueAt(ordered_multiset &st, ll index)
// {
//     return *st.find_by_order(index);
// }
// inline ll orderOf(ordered_set &st, ll value)
// {
//     return st.order_of_key(value);
// }
// inline ll valueAt(ordered_set &st, ll index)
// {
//     return *st.find_by_order(index);
// }
// template <class T>
// void Distinct(T &v, bool sorting = true)
// {
//     if (sorting)
//         sortv(v);
//     v.resize(unique(begin(v), end(v)) - begin(v));
// }
// //------------------------------
// const ll mod = 1000000007; // assume -mod <= x < 2*mod
// const ll N2 = 998244353;
// //------------------------------
// inline ll expo(ll a, ll b, ll mod = LONG_LONG_MAX)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = (res*1ll* a) % mod;
//         a = (a*1ll* a) % mod;
//         b = b >> 1;
//     }
//     return res;
// }
// inline ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); } // FOR PRIME
// inline ll mod_add(ll a, ll b, ll m = mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// inline ll mod_mul(ll a, ll b, ll m = mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// inline ll mod_sub(ll a, ll b, ll m = mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// inline ll mod_div(ll a, ll b, ll m = mod)
// {
//     a = a % m;
//     b = b % m;
//     return (mod_mul(a, mminvprime(b, m), m) + m) % m;
// }
// ll ncr(ll n, ll r, bool mod_version = false, ll mod=mod){
//     ll ans=0;
//     if(n >=r){
//         r = min(n, n-r);
//         if(mod_version == true){
//             ll a = 1;
//             for(ll i = n; i>=n-r+1; i--){
//                 a=mod_mul(a, i, mod);
//             }
//             ll b = 1;
//             for(ll i = 1; i <=r; i++){
//                 b=mod_mul(b, i, mod);
//             }
//             b=mminvprime(b, mod);
//             a=mod_mul(a, b, mod);
//             ans = a;
//         }
//         else{
//             ll a = 1;
//             ll b = 1;
//             for(ll i=n; i >=n -r +1;i--){
//                 a *= 1;
//                 b *= (n - i + 1);
//                 ll g = __gcd(a, b);
//                 a /= g;
//                 b /= g;
//             }
//             ans = a/b;
//         }
//     }
//     return ans;
// }
// bool is_prime(ll a)
// {
//     if (a == 1)
//         return false;
//     for (ll i = 2; i * i <= a; i++)
//     {
//         if (a % i == 0)
//             return false;
//     }
//     return true;
// }
// //----------------------------------------------------
// map<ll, ll> prime_factors(ll n, bool debug = false)
// {
//     map<ll, ll> answer;
//     ll a = n;
//     for (ll i = 2; i * i <= a; i++)
//         while (a % i == 0)
//             answer[i]++, a /= i;
//     if (a > 1)
//         answer[a]++;
//     if (debug)
//     {
//         for (auto i : answer)
//             cout << i.first << " -> " << i.second << "\n";
//     }
//     return answer;
// }
// int lcs(string A,string B, string C,int n1,int n2,int n3){
//     // int dp[n1+1][n2+1][n3+1];
//     // memset(dp,0,sizeof(dp));
//     int dp[n1][n2];
//     memset(dp,0,sizeof(dp));
//     int ans=0;
//     for(int i=1;i<n1;i++){
//         for(int j=1;j<n2;j++){
//             if(A[i-1]==B[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }else{
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     return dp[n1][n2];
// }

// //----------------------------------------------------------------
// #define LOCAL_COMPILER
// #ifdef LOCAL_COMPILER
// #define dbg(x)            \
//     cerr << #x << " -> "; \
//     cout << x << "\n";
// #endif
// #ifndef LOCAL_COMPILER
// #define dbg(x)
// #endif
// //----------------------------------------------------------------
// // CODE STARTS HERE
// //----------------------------------------------------------------

// // class Solution{
// // public:
//         // int minvalue(stirng s,int k){
            
//         // }
// // };


// void solve(bool testCases = true){
//     ll T=1;
//     // if(testCases) cin >> T;
//     while(T--){
//         // string s;
//         // int k;
//         // cin>>s>>k;
//         // Solution ob;
//         // cout<<ob.minvalue(s,k);
//         ll n;
//         cin>>n;
//         vl v(n);
//         cin>>v;
//         sortv(v);
//         int dp[n+1];
//         dp[0]=1;
//         ll ans=0;
//         ll tans=0;
//         ll tno=0;
//         for(ll i=0;i<n;i++){
//             tno=0;
//             for(ll j=0;j<=i;j++){
//                 tans=0;
//                 if(v[i]>=tno){
//                     tans=tno;
//                     tans=v[i]-tno;
//                 }else{
//                     tans=tno;
//                 }
//                 ans+=tans;
//                 tno+=v[i];
//             }
           
//         }


//         nline;
//     }
//     //--------------------------------------------
//     //  CODE ENDS HERE
// }

// //----------------------------------------------------
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     //------------------------------------------------
//     // initialise_sieve(prime_sieve);
//     //------------------------------------------------
// #ifdef LOCAL_COMPILER
//     std::cout << std::fixed << std::setprecision(25);
//     std::cerr << std::fixed << std::setprecision(10);
//     auto start = std::chrono::high_resolution_clock::now();
// #endif

//     solve(false);
//     // solve(true);


// #ifdef LOCAL_COMPILER
//     auto stop = std::chrono::high_resolution_clock::now();
//     long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
//     std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;
// #endif
//     //------------------------------------------------
//     return 0;
// }
// //----------------------------------------------------



#include<iostream>
#include<cassert>
using namespace std;
int N;
int imos[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	int P=0;
	int K=0;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		if(P<A)imos[P]++,imos[A]--;
		P=A;
		K=max(K,A);
	}
	for(int i=0;i<K;i++)imos[i+1]+=imos[i];
	for(int k=1;k<=K;k++)
	{
		long long ans=0;
		for(int i=0;i<=K;i+=k)ans+=imos[i];
		cout<<ans<<(k==K?"\n":" ");
	}
}