#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   int main() {
int n_cases, n, balance, diff;
char s1[300001], s2[300001], *c1, *c2; bool any_same, any_different; scanf("%d", &n_cases);
while (n_cases--) {
     scanf("%d", &n); scanf("%s\n%s", s1, s2); c1 = s1;
c2 = s2;
any_same = false; any_different = false; balance = 0;
diff = 0;
while (*c1) {
any_same = any_same || *c1 == *c2; any_different = any_different || *c1 != *c2; if (any_same && any_different) break; balance += *c2 == '1' ? 1 : -1;
diff += *c1 - *c2;
if (balance == 0) {
any_same = false; any_different = false;
} c1++; c2++;
}
printf(((any_same && any_different) || diff != 0) ? "NO\n" : "YES\n");
               }

    return 0;}
