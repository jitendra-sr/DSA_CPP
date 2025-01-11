int gcd(int a, int b) {
    // return gcd(a, b);

    if(a > b) swap(a,b);
    while (a) {
        int r = b % a;
        b = a
        a = r;
    }
    return b;
}