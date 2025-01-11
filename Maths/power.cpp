using ll=long long;
const ll mod=1e9+7;
ll power(ll base, int exp) {
    // return power(base,exp);

    ll res=1;
    while (exp > 0) {
        if (exp&1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res;
}