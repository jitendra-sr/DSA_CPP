// 204. Count Primes
// https://leetcode.com/problems/count-primes/description/

class Solution {
public:
    int countPrimes(int n) { // excluding n
        vector<bool> seive(n,true);
        seive[0]=seive[1]=false;
        for(int i=2;i*i<n;i++){
            if(seive[i]) {
                for(int j=i*i;j<n;j+=i) seive[j]=false;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++) if(seive[i]) cnt++;
        return cnt;
    }
};
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int limit = static_cast<int>(sqrt(n));
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}