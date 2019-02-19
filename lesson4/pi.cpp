#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <omp.h>

float random_number() {
  float v = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
  int s = (rand() % 2 == 0) ? 1 : -1;
  return s * v;
}

int main() {
  int N = 10000000;
  int cnt = 0;
  double r = 1.0;
  double x, y;
  srand(std::time(NULL));
#pragma omp parallel for private(x, y) reduction(+:cnt)
  for (int i = 0; i < N; ++i) {
    x = random_number();
    y = random_number();
    cnt += int(x * x + y * y < r * r);
  }

  printf("circle points = %d\n", cnt);
  double pi = 4.0 * cnt / N;
  printf("pi = %f\n", pi);
  return 0;
}
