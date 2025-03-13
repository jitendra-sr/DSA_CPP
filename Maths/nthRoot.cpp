// #include<cmath>
// pow(base,exp) -> returns in double
// #include<iomanip>
// cout<<fixed<<setprecision(8)<<pow(2.7,3.9);

using ll = long long;
class Solution {
    bool isValid(ll base, int exp, int num) {
        ll res = 1;
        while (exp > 0) {
            if (exp & 1) {
                if (res > num / base) return false;
                res *= base;
            }
            if (exp > 1) {
                if (base > num / base) return false;
                base *= base;
            }
            exp >>= 1;
        }
        return res <= num;
    }
public:
    int nthRoot(int num, int n) {
        int l = 1, r = num, res = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, n, num)) {
                res = mid;
                l = mid + 1;
            } 
            else r = mid - 1;
        }
        return res;
    }
};
