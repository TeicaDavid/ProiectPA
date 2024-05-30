#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y, int z) {
    if (x < y && x < z) return x;
    if (y < x && y < z) return y;
    return z;
}

int minEditDistance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int l = strlen(s2);

    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((l + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= l; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    int result = dp[m][l];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    const char *fragment_cod = "fnuc(myFuncion";
    const char *cod_corect = "func(myFunction)";

    int numar_minim_operatii = minEditDistance(fragment_cod, cod_corect);
    printf("Numărul minim de operații necesare: %d\n", numar_minim_operatii);

    return 0;
}
