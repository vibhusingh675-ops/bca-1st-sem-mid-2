#include <stdlib.h>
#include <string.h>

int expandAroundCenter(char* s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(s, i, i, n);
        int len2 = expandAroundCenter(s, i, i + 1, n);
        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;
}
