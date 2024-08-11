#include <bits/stdc++.h>

int minimumDays(int S, int N, int M) {
    int total = 0, req = S * M;
    int cn = 0;
    for (int i = 1; i <= S; i++) {
        if (i % 7 != 0)
            total += N - M, cn++;
        else
            total -= M;

        req -= M;

        if (total >= req)
            break;
        if (total < 0)
            return -1;
    }
    return cn;
}