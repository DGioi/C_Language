#include <iostream>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}
int tromDo(long long m, int a[], int b[], int n) {
   int i, t;
   int k[n + 1][m + 1];
   for (i = 0; i <= n; i++) {
      for (t = 0; t <= m; t++) {
         if (i == 0 || t == 0)
         k[i][t] = 0;
         else if (b[i - 1] <= t)
            k[i][t] = max(a[i - 1] + k[i - 1][t - b[i - 1]], k[i - 1][t]);
         else
        k[i][t] = k[i - 1][t];
      }
   }
   return k[n][m];
}
int main() {
    freopen("DRSEM.txt","r",stdin);
    freopen("DRSEMout.txt","w",stdout);
    int n; long long m;
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cin >> b[i];
    }
   cout << tromDo(m, a, b, n);
   return 0;
}
