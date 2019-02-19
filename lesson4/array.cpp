#include<cstdio>
#include <cstdlib>

int main() {
  int n = 1000;
  int m = 2000;

  int A[n][m];

#pragma omp parallel for
  for (int j=0; j < m; j++) {
    for (int i=0; i < n; i++) {
      A[i][j] = rand() * i * j;
    }
  }

  return 0;
}
