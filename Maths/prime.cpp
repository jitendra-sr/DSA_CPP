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


// Check for factors of the form 6k ± 1
// This is because all primes greater than 3 can be expressed in this form.
bool isPrime(int n) {
    if (n<=1) return false;
    if (n<=3) return true;
    if (n % 2==0||n % 3==0) return false;

    for (int i=5; i*i<=n; i+=6) { 
        if (n%i ==0||n%(i+2) == 0)
            return false;
    }
    return true;
}