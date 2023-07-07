#include <array>
#include <complex.h>
#include <complex>
#include <finufft.h>
#include <iostream>
#include <nanobench.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
#if 0
  int M = 1e7; // number of nonuniform points
  vector<double> x(M);
  vector<complex<double>> c(M);
  complex<double> I = complex<double>(0.0, 1.0); // the imaginary unit
  for (int j = 0; j < M; ++j) {
    x[j] = M_PI *
           (2 * ((double)rand() / RAND_MAX) - 1); // uniform random in [-pi,pi)
    c[j] = 2 * ((double)rand() / RAND_MAX) - 1 +
           I * (2 * ((double)rand() / RAND_MAX) - 1);
  }
  int N = 1e6; // number of output modes
  vector<complex<double>> F(N);
  int ier = finufft1d1(M, &x[0], &c[0], +1, 1e-9, N, &F[0], NULL);
#endif

  int M = 5e5; // number of nonuniform points
  vector<double> x(M), y(M), z(M);
  vector<complex<double>> c(M);
  for (int j = 0; j < M; ++j) {
    x[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    y[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    z[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    c[j] = 2 * ((double)rand() / RAND_MAX) - 1 +
           I * (2 * ((double)rand() / RAND_MAX) - 1);
  }
  int N1 = 128, N2 = 128, N3 = 128;
  vector<complex<double>> F(N1 * N2 * N3);
  auto bench = ankerl::nanobench::Bench().minEpochIterations(100);
  bench.run("compare_exchange_strong", [&] {
    int ier = finufft3d1(M, &x[0], &y[0], &z[0], &c[0], +1, 1e-3, N1, N2, N3,
                         &F[0], NULL);
    ankerl::nanobench::doNotOptimizeAway(ier);
    ankerl::nanobench::doNotOptimizeAway(F[0]);
  });
  std::array<int64_t, 3> nmodes{128, 128, 128};
  finufft_plan plan;
  int res = finufft_makeplan(1, 3, nmodes.data(), 1, 1, 1e-6, &plan, nullptr);
  bench.run("With plan", [&] {
    finufft_setpts(plan, M, x.data(), y.data(), z.data(), 0, nullptr, nullptr,
                   nullptr);
    finufft_execute(plan, c.data(), F.data());
  });
}
