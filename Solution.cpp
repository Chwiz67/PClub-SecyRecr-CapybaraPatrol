#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll binexp(ll a, ll p, ll m){
    a %= m;
    if(p == 0) return 1;
    if(p == 1) return a;
    ll res = binexp(a, p / 2, m);
    res = (res * res) % m;
    if(p % 2) res = (res * a) % m;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), p(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++){
            cin >> p[i];
        }
        vector<ll> b(n);
        for(ll i = 0; i < n; i++){
            b[i] = binexp(a[i], p[i], 9);
            if(b[i] == 0 && a[i] != 0){
                b[i] = 9;
            }
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            ans += b[i];
        }
        ans = 1 + (ans - 1) % 9;
        cout << ans << "\n";
    }
}