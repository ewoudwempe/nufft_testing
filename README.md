Requires fftw to be installed and in the compiler search path. Can be built (on mac) with 
```
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=$PWD/homebrew.cmake -B build -G Ninja && ninja -C build
```

# Sample (my laptop):
```

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|      225,384,541.60 |                4.44 |    1.2% |     13.52 | `FINUFFT 3d`
|      221,929,925.00 |                4.51 |    2.0% |     13.41 | `FINUFFT With plan`
|      294,113,152.67 |                3.40 |    1.5% |     17.59 | `FINUFFT With plan & FFTW_MEASURE`
|       43,830,191.80 |               22.82 |    0.3% |      2.63 | `Ducco 1e-4 32 threads`
|       38,593,638.83 |               25.91 |    0.4% |      2.31 | `Ducco 1e-4 32 threads float`
|       43,988,375.00 |               22.73 |    0.3% |      2.64 | `Ducco 1e-4 16 threads`
|       38,441,465.33 |               26.01 |    0.4% |      2.31 | `Ducco 1e-4 16 threads float`
|       43,836,458.20 |               22.81 |    0.4% |      2.63 | `Ducco 1e-4 8 threads`
|       38,524,333.33 |               25.96 |    0.2% |      2.31 | `Ducco 1e-4 8 threads float`
|       39,947,680.50 |               25.03 |    3.2% |      2.62 | `Ducco 1e-4 6 threads`
|       30,629,800.00 |               32.65 |    0.5% |      1.86 | `Ducco 1e-4 6 threads float`
|       52,492,694.50 |               19.05 |    0.2% |      3.15 | `Ducco 1e-4 4 threads`
|       40,499,750.00 |               24.69 |    0.2% |      2.43 | `Ducco 1e-4 4 threads float`
|       43,762,158.20 |               22.85 |    0.2% |      2.63 | `Ducco 1e-4 8 fourier output`
32 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.06773s
|
+- nu2u proper          : 96.46% (0.0653s)
|  |
|  +- spreading            : 70.03% (0.0458s)
|  +- FFT                  : 15.00% (0.0098s)
|  +- zeroing grid         : 12.75% (0.0083s)
|  +- grid correction      :  2.20% (0.0014s)
|  +- allocating grid      :  0.02% (0.0000s)
|  
+- building index       :  3.30% (0.0022s)
+- correction factors   :  0.08% (0.0001s)
+- parameter calculation:  0.01% (0.0000s)
+- <unaccounted>        :  0.15% (0.0001s)
16 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.06083s
|
+- nu2u proper          : 96.35% (0.0586s)
|  |
|  +- spreading            : 76.04% (0.0446s)
|  +- FFT                  : 16.35% (0.0096s)
|  +- zeroing grid         :  5.17% (0.0030s)
|  +- grid correction      :  2.44% (0.0014s)
|  +- allocating grid      :  0.00% (0.0000s)
|  
+- building index       :  3.41% (0.0021s)
+- correction factors   :  0.07% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
+- <unaccounted>        :  0.16% (0.0001s)
8 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.06255s
|
+- nu2u proper          : 96.22% (0.0602s)
|  |
|  +- spreading            : 76.71% (0.0462s)
|  +- FFT                  : 15.84% (0.0095s)
|  +- zeroing grid         :  5.08% (0.0031s)
|  +- grid correction      :  2.36% (0.0014s)
|  +- allocating grid      :  0.01% (0.0000s)
|  
+- building index       :  3.58% (0.0022s)
+- correction factors   :  0.06% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
+- <unaccounted>        :  0.13% (0.0001s)
4 threads verbose 
Nu2u:
  nthreads=4, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.07497s
|
+- nu2u proper          : 96.00% (0.0720s)
|  |
|  +- spreading            : 78.53% (0.0565s)
|  +- FFT                  : 15.24% (0.0110s)
|  +- zeroing grid         :  3.92% (0.0028s)
|  +- grid correction      :  2.30% (0.0017s)
|  +- allocating grid      :  0.00% (0.0000s)
|  
+- building index       :  3.83% (0.0029s)
+- correction factors   :  0.04% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
+- <unaccounted>        :  0.13% (0.0001s)
```
# Sample (dardel cluster)
```
Warning, results might be unstable:
* CPU frequency scaling enabled: CPU 0 between 1,500.0 and 2,250.0 MHz

Recommendations
* Use 'pyperf system tune' before benchmarking. See https://github.com/psf/pyperf

|               ns/op |                op/s |    err% |          ins/op |          cyc/op |    IPC |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|----------------:|-------:|---------------:|--------:|----------:|:----------
|      206,122,584.17 |                4.85 |    1.4% |  218,549,693.40 |  512,901,426.50 |  0.426 |  26,987,868.80 |    0.1% |     12.37 | `FINUFFT 3d`
|      223,238,714.00 |                4.48 |    1.2% |  237,817,837.83 |  625,744,072.40 |  0.380 |  28,594,510.00 |    0.1% |     13.39 | `FINUFFT With plan`
|      173,781,052.50 |                5.75 |    2.4% |  216,461,015.50 |  521,121,835.00 |  0.415 |  27,928,326.33 |    0.2% |     10.32 | `FINUFFT With plan & FFTW_MEASURE`
|       80,530,501.33 |               12.42 |    0.8% |  582,561,271.50 |  230,804,008.17 |  2.524 |  18,546,873.83 |    0.7% |      4.81 | `Ducco 1e-6 8 threads`
|       28,576,612.67 |               34.99 |    5.5% |  111,212,456.17 |   67,068,312.83 |  1.658 |   3,589,762.80 |    0.5% |      1.77 | :wavy_dash: `Ducco 1e-4 32 threads` (Unstable with ~5.5 iters. Increase `minEpochIterations` to e.g. 55)
|       41,127,675.80 |               24.31 |    0.2% |  180,491,044.80 |  108,140,203.17 |  1.669 |   6,969,893.80 |    0.4% |      2.47 | `Ducco 1e-4 16 threads`
|       69,182,510.60 |               14.45 |    0.3% |  359,627,966.00 |  202,611,525.33 |  1.775 |  13,755,763.50 |    0.4% |      4.14 | `Ducco 1e-4 8 threads`
|       68,845,992.00 |               14.53 |    0.2% |  364,397,699.83 |  204,265,575.17 |  1.784 |  13,989,759.83 |    0.4% |      4.13 | `Ducco 1e-4 fourier output`
|       87,570,858.40 |               11.42 |    0.3% |  478,560,315.33 |  259,971,547.50 |  1.841 |  18,156,555.33 |    0.4% |      5.26 | `Ducco 1e-4 6 threads`
|       87,630,835.67 |               11.41 |    0.3% |  481,837,531.80 |  261,165,641.00 |  1.845 |  18,377,360.60 |    0.4% |      5.25 | `Ducco 1e-4 4 threads`
32 threads verbose
Nu2u:
  nthreads=32, grid=(128x128x128), oversampled grid=(162x162x162), supp=12, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 6.335270404815674e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.04319s
|
+- nu2u proper          : 89.86% (0.0388s)
|  |
|  +- spreading            : 78.62% (0.0305s)
|  +- FFT                  : 11.12% (0.0043s)
|  +- zeroing grid         :  6.30% (0.0024s)
|  +- grid correction      :  3.91% (0.0015s)
|  +- allocating grid      :  0.05% (0.0000s)
|  
+- building index       :  8.67% (0.0037s)
+- correction factors   :  1.14% (0.0005s)
+- parameter calculation:  0.03% (0.0000s)
+- <unaccounted>        :  0.30% (0.0001s)
16 threads verbose
Nu2u:
  nthreads=16, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.05184s
|
+- nu2u proper          : 89.59% (0.0464s)
|  |
|  +- spreading            : 77.52% (0.0360s)
|  +- FFT                  : 14.45% (0.0067s)
|  +- zeroing grid         :  5.03% (0.0023s)
|  +- grid correction      :  2.97% (0.0014s)
|  +- allocating grid      :  0.02% (0.0000s)
|  
+- building index       : 10.15% (0.0053s)
+- correction factors   :  0.09% (0.0000s)
+- parameter calculation:  0.03% (0.0000s)
+- <unaccounted>        :  0.15% (0.0001s)
8 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.07848s
|
+- nu2u proper          : 86.93% (0.0682s)
|  |
|  +- spreading            : 78.24% (0.0534s)
|  +- FFT                  : 15.27% (0.0104s)
|  +- zeroing grid         :  4.28% (0.0029s)
|  +- grid correction      :  2.18% (0.0015s)
|  +- allocating grid      :  0.03% (0.0000s)
|  
+- building index       : 12.90% (0.0101s)
+- correction factors   :  0.05% (0.0000s)
+- parameter calculation:  0.02% (0.0000s)
+- <unaccounted>        :  0.10% (0.0001s)
4 threads verbose 
Nu2u:
  nthreads=4, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.1364s
|
+- nu2u proper          : 85.28% (0.1163s)
|  |
|  +- spreading            : 77.42% (0.0901s)
|  +- FFT                  : 16.57% (0.0193s)
|  +- zeroing grid         :  3.93% (0.0046s)
|  +- grid correction      :  2.07% (0.0024s)
|  +- allocating grid      :  0.02% (0.0000s)
|  
+- building index       : 14.62% (0.0199s)
+- correction factors   :  0.03% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
```
