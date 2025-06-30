// https://cp-algorithms.com/string/prefix-function.html
vector<int> prefixArray(const string& pat){
    int m = pat.size();
    vector<int> lps(m, 0);

    for (int i = 1; i < m; i++) {
        int j = lps[i - 1]; // Length of the previous longest prefix suffix
        while (j > 0 && pat[j] != pat[i]) {
            j = lps[j - 1]; // trying to find a valid shorter prefix suffix
        }
        if (pat[i] == pat[j]) {
            j++; // If characters match, increment the length of the current longest prefix suffix
        }
        lps[i] = j; // Store the length of the longest prefix suffix for the current index
    }
    return lps;
}
void kmpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = prefixArray(pattern); // Get the LPS array for the pattern
    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        else {
            if (j != 0) { // Use LPS to avoid unnecessary comparisons
                j = lps[j - 1]; 
            }
            else {
                i++;
            }
        }
        if (j == m) {
            // Found a match, print the starting index
            cout << "Pattern found at index " << i - j << endl;
            if(j != 0) j = lps[j - 1]; // Use LPS to skip unnecessary comparisons
        }
    }
}

vector<int> buildLpsArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m);
    lps[0]=0; // In lps array we don't consider whole string as prefix
    int i = 1;    // We start from the second character in the pattern
    int len = 0;  // length of the previous longest prefix suffix
    // It also works as the last character to match to find lps

    while (i < m) {
        // Checking if previous lps is of k can current character continue it to make a lps of k+1.
        if (pattern[i] == pattern[len]) {
            lps[i] = len+1;
            len++; i++;
        } 
        // If not then check for lower values of lps. Use the previously computed lps values.
        else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}