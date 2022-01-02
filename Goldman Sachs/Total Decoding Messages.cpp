/*
	PROBLEM STATEMENT: A message containing letters from A-Z is encoded to numbers using the following mapping:
		'A' -> 1
		'B' -> 2
		...
		'Z' -> 26
	Determine the total number of ways that message can be decoded, return the answer modulo 10^9 + 7.
	Input: str = "123"
	Output: 3
	Explanation: "123" can be decoded as "ABC"(123),
	"LC"(12 3) and "AW"(1 23).
*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef long double ld;
struct custom_hash;
#define ff first
#define I insert
#define ss second
#define maxN 300002
#define inf INT_MAX
#define ninf INT_MIN
#define pb push_back
#define popb pop_back
#define pf push_front
#define pi 3.14159265
#define ub upper_bound
#define lb lower_bound
#define popf pop_front
#define mod 1000000007
#define vi vector<int> 
#define mll map<ll, ll>
#define vll vector <ll>
const int dx4[]={-1,0,1,0};
const int dy4[]={0,1,0,-1};
#define vvi vector<vector<int> >
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
const int dx8[]={-1,-1,-1,0,1,1,1,0,-1};
const int dy8[]={-1,0,1,1,1,0,-1,-1,-1};
#define ust unordered_set<ll, custom_hash>
#define rep(i, a, b) for(ll i = a; i < ll(b); i++)
#define umll unordered_map<ll, ll, custom_hash>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
struct custom_hash { size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM =
chrono::steady_clock::now().time_since_epoch().count();x ^= FIXED_RANDOM;return x ^ (x >> 16);}};
ll power(ll x,ll n) {ll result=1; while(n) {if(n%2==1) result=result*x; n=n/2; x=x*x;} return result;}
ll gcd(ll a, ll b) {return b ? gcd(b, a%b) : a;} 
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
ll BS(ll a[],ll s,ll n,ll val) {ll mid,beg=s,end=n-1; while(beg<=end)
{mid=(beg+end)/2; if(val==a[mid]){break;} else if(val>a[mid]){beg=mid+1;}else{end=mid-1;}} return mid;}
inline ll mul(ll x,ll y,ll m){ll z=1LL*x*y;if (z>=m){z%=m;} return z;}
ll powmod(ll x,ll y,ll m){ll r=1;while(y){if(y&1){r=mul(r,x,m);}y>>=1;x=mul(x,x,m);}return r;}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"

//========================================XXXXXXXXXXXXXXXX=======================================

// METHOD-1: Recursion(BT); TLE
int solve1(string str) {
	if(str.length() <= 1 && str[0] != '0')
        return 1;

    int cnt = 0;
    if(str[0] != '0') cnt += (solve1(str.substr(1)) % MOD);
    if(str.length() >= 2 && str.substr(0,2) >= "10" && str.substr(0,2) <= "26")
        cnt += (solve1(str.substr(2)) % MOD);
    return cnt % MOD;
}

// METHOD-2: Dynamic Programming; AC
int solve2() {
	string str;
	cin >> str;

	int N = str.size();
	if(str[0] == '0') return 0;
	if(N == 1) return 1;

	vector<int> dp(N+1, 0);
	dp[0] = dp[1] = 1;

	rep(i, 2, N+1) {
		int v1 = str[i-1] - '0';
		int v2 = (str[i-2] - '0') * 10 + v1;
		if(v1 > 0)
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		if(v2 > 9 && v2 <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}
	return dp[N] % MOD;
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
  		freopen("input.txt", "r", stdin);
  		freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	cin >> t;
	while(t--) {
		int ways = solve2();
		cout << ways << '\n';
	}
	return 0;
}

#pragma GCC diagnostic pop