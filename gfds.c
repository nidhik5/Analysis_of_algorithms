#include <stdio.h>
#include <string.h>

#define d 10


int main()
{
    int m, n, t = 0, p = 0, s, h = 1, q = 13;
    char txt[30], pat[30];

    printf("Enter text string: ");
    scanf("%s", txt);

    printf("Enter Pattern string: ");
    scanf("%s", pat);

    m = strlen(txt);
    n = strlen(pat);

    for (int i = 0; i < n - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < n; i++) {
        t = (d * t + txt[i]) % q;
        p = (d * p + pat[i]) % q;
    }

    for (s = 0; s <= m - n; s++) {
        if (t == p) {
            int i;
            for (i = 0; i < n; i++) {
                if (txt[s + i] != pat[i]) {
                    break;
                }
            }

            if (i == n) {
                printf("Shift at %d\n", s);
            }
        }

        if (s < m - n) {
            t = (d * (t - txt[s] * h) + txt[s + n]) % q;
            if (t < 0) {
                t += q;
            }
        }
    }

    return 0;
}

