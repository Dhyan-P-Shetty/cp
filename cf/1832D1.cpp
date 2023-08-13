#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
	
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
	
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
		pr(t); pr(ts...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void pr(const T& x) { 
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; 
		pr("}");
	}
	
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
	}
	
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}

using namespace output;

bool can(ll mi, vi &b, ll kill) {
	bool c = false;
	for (auto x: b) {
		if (x < mi) {
			return false;
		}
		kill -= (x - mi);
		if (kill <= 0) c = true;
	}
	return c;
}

void solve() {
    int n, q;
	cin >> n >> q;
	vi a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0;i < q;i++) {
		int k;
		cin >> k;
		int mn = INT_MAX;
		if (k <= n) {
			for (int j = 0;j < n;j++) {
				mn = min(mn, a[j] + ((j < k) ? k - j : 0));
			}
		} else {
			int take = n - (k-n)%2;
			int kill = (k - take)/2;

			vi b(n);
			for (int j = 0;j < n;j++) {
				b[j] = a[j] + ((j < take) ? k - j : 0);
			}

			ll l = -1e18, r = 1e18;
			while (l < r) {
				ll mi = l + (r-l+1)/2;
				if (can(mi, b, kill)) {
					l = mi;
				} else {
					r = mi - 1;
				}
			}

			mn = l;
		}
		cout << mn << " ";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}