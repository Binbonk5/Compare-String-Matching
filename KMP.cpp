#include <iostream>
#include <vector>
using namespace std;


void computeLPSArray(string pat, vector<int> &lps) {
    int M = pat.length();
    int len = 0; 
    int i = 1;
    lps[0] = 0;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string txt, string pat) {
    int N = txt.length();
    int M = pat.length();

    vector<int> lps(M);
    computeLPSArray(pat, lps);

    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    KMPSearch(txt, pat);
    return 0;
}
