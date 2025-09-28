#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonSubstring(const string& s1, const string& s2) {
    int n = s1.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int maxLen = 0;
    int endIndex = 0; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i; 
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << "DP Lookup Table:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return s1.substr(endIndex - maxLen, maxLen);
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (str1.size() != str2.size()) {
        cout << "Strings must be of the same length for this assignment!" << endl;
        return 1;
    }

    string result = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << result << endl;

    return 0;
}