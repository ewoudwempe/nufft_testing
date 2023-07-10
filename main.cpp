#include <array>
#include <complex>
#include <ducc0/nufft/nufft.h>
#include <fftw3.h>
#include <finufft.h>
#include <iostream>
#include <nanobench.h>
#include <vector>

using namespace std;
using namespace std::complex_literals;

int main() {
  // Set up data
  size_t M = 5e5; // number of nonuniform points
  vector<double> x(M), y(M), z(M);
  vector<complex<double>> c(M);
  for (size_t j = 0; j < M; ++j) {
    x[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    y[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    z[j] = M_PI * (2 * ((double)rand() / RAND_MAX) - 1);
    c[j] = 2 * ((double)rand() / RAND_MAX) - 1 +
           1i * (2 * ((double)rand() / RAND_MAX) - 1);
  }
  size_t N1 = 128, N2 = 128, N3 = 128;
  vector<complex<double>> F(N1 * N2 * N3);

  // Bench FINUFFT
  auto bench = ankerl::nanobench::Bench().warmup(1).minEpochIterations(5);
  bench.run("FINUFFT 3d", [&] {
    int ier = finufft3d1(M, &x[0], &y[0], &z[0], &c[0], +1, 1e-3, N1, N2, N3,
                         &F[0], NULL);
    ankerl::nanobench::doNotOptimizeAway(ier);
    ankerl::nanobench::doNotOptimizeAway(F[0]);
  });
  std::array<int64_t, 3> nmodes{128, 128, 128};
  finufft_plan plan;
  finufft_opts options;
  finufft_default_opts(&options);
  int res = finufft_makeplan(1, 3, nmodes.data(), 1, 1, 1e-6, &plan, &options);
  bench.run("FINUFFT With plan", [&] {
    finufft_setpts(plan, M, x.data(), y.data(), z.data(), 0, nullptr, nullptr,
                   nullptr);
    finufft_execute(plan, c.data(), F.data());
  });
  options.fftw = FFTW_MEASURE;
  int res2 = finufft_makeplan(1, 3, nmodes.data(), 1, 1, 1e-6, &plan, &options);
  bench.run("FINUFFT With plan & FFTW_MEASURE", [&] {
    finufft_setpts(plan, M, x.data(), y.data(), z.data(), 0, nullptr, nullptr,
                   nullptr);
    finufft_execute(plan, c.data(), F.data());
  });

  // Set up same data ducc0
  std::vector<double> coords(M * 3);
  for (size_t i = 0; i < M; i++) {
    coords[3 * i] = x[i] + M_PI;
    coords[3 * i + 1] = y[i] + M_PI;
    coords[3 * i + 2] = z[i] + M_PI;
  }
  auto coords_cm =
      ducc0::cmav<double, 2>(coords.data(), std::array<size_t, 2>{M, 3l});
  auto points_cm = ducc0::cmav<complex<double>, 1>(c.data(), {M});
  auto grid_cm = ducc0::vfmav<complex<double>>(
      F.data(), std::vector<size_t>{128ul, 128ul, 128ul});

  // Bench ducc0
  bench.run("Ducco 1e-6 8 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-6, 8, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, false);
  });
  bench.run("Ducco 1e-4 32 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 32, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, false);
  });
  bench.run("Ducco 1e-4 16 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 16, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, false);
  });
  bench.run("Ducco 1e-4 8 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 8, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, false);
  });
  bench.run("Ducco 1e-4 fourier output", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 8, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, true);
  });
  bench.run("Ducco 1e-4 6 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 6, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, true);
  });
  bench.run("Ducco 1e-4 4 threads", [&] {
    ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-4, 6, grid_cm, 0,
                                1.1, 2.6, 2 * M_PI, true);
  });

  std::cout << "32 threads verbose\n";
  ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-6, 32, grid_cm, 1,
                              1.1, 2.6, 2 * M_PI, false);
  std::cout << "16 threads verbose\n";
  ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-6, 16, grid_cm, 1,
                              1.1, 2.6, 2 * M_PI, false);
  std::cout << "8 threads verbose\n";
  ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-6, 8, grid_cm, 1,
                              1.1, 2.6, 2 * M_PI, false);
  std::cout << "4 threads verbose \n";
  ducc0::nu2u<double, double>(coords_cm, points_cm, true, 1e-6, 4, grid_cm, 1,
                              1.1, 2.6, 2 * M_PI, false);
}
