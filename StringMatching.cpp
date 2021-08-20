#include <bits/stdc++.h>
using namespace std;

vector<int> zArray(const string& s) {  // substring starting at x
    int n = s.size();
    vector<int> zArr(n);
    zArr[0] = -1;
    for (int i = 1, l, r; i < n; i++) {
        if (i <= r)
            zArr[i] = min(r - i + 1, zArr[i - l]);
        while (i + zArr[i] < n && s[zArr[i]] == s[zArr[i] + i])
            zArr[i]++;
        if (zArr[i] + i - 1 > r)
            l = i, r = zArr[i] + i - 1;
    }
    return zArr;
}

vector<int> lpsArray(const string& s) {  // substring ending at x
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[j] != s[i])
            j = lps[j - 1];
        if (s[j] == s[i])
            j++;
        lps[i] = j;
    }
    return lps;
}

int32_t main() {
}