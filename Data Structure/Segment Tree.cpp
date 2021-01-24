#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
struct segment_tree{
 
	ll size;
	vector<ll> v;
 
	void init(int n) {
		size = 1;
		while(size < n)
			size *= 2;
		v.resize(2 * size);
	}
 
	void set(ll i, ll x) {
		set(i, x, 1, 1, size);
	}
 
	void set(ll i, ll x, ll cur, ll l, ll r) {
		if (l == r) {
			v[cur]=x;
			return;
		}
		ll mid = (l + r) / 2;
		if (i <= mid) 
			set(i, x, 2 * cur, l, mid);
		else 
			set(i, x, 2 * cur + 1, mid + 1, r);
		v[cur] = v[2 * cur] + v[2 * cur + 1];
	}  
 
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 1, size); 
	}
 
	ll sum(ll l, ll r, ll cur, ll lx, ll rx) {
		 if(lx > r || rx < l)	return 0;
		 if(lx >= l && rx <= r) return v[cur];
		 ll mid = (lx + rx) / 2;
		 ll s1 = sum(l, r, 2 * cur, lx, mid);
		 ll s2 = sum(l, r, 2 * cur + 1, mid + 1, rx);
		 return s1 + s2;
	}
 
}seg;
 
int main(){
 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, q, x, op;
	cin >> n >> q;
	seg.init(n);
	for(int i = 1; i <= n; i++) {
		cin >> x;
		seg.set(i, x);
	}
	while(q--) {
		cin >> op;
		if (op == 1) {
			int i, a;
			cin >> i >> a;
			seg.set(++i, a);
		}else {
			int l, r;
			cin >> l >> r;
			cout << seg.sum(l + 1, r) << "\n";
		}
	}
 
    return 0;
}
