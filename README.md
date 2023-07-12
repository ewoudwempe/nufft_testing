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
|      197,880,456.00 |                5.05 |    0.6% |  217,901,963.50 |  556,676,074.40 |  0.391 |  26,804,637.67 |    0.1% |     11.90 | `FINUFFT 3d`
|      217,053,533.00 |                4.61 |    1.2% |  237,479,472.33 |  686,037,967.67 |  0.346 |  28,508,262.33 |    0.1% |     13.10 | `FINUFFT With plan`
|      182,291,613.83 |                5.49 |    0.9% |  212,051,136.33 |  606,609,030.00 |  0.350 |  26,951,057.60 |    0.1% |     10.96 | `FINUFFT With plan & FFTW_MEASURE`
|       30,652,621.20 |               32.62 |    1.1% |   43,370,731.60 |   56,349,593.60 |  0.770 |   2,783,816.60 |    0.6% |      1.85 | `Ducco 1e-4 32 threads`
|       23,126,182.40 |               43.24 |    0.9% |   45,454,210.67 |   36,355,304.83 |  1.250 |   2,874,777.67 |    0.6% |      1.39 | `Ducco 1e-4 32 threads float`
|       28,062,049.80 |               35.64 |    0.5% |   89,783,783.00 |   61,602,046.00 |  1.457 |   5,703,966.00 |    0.5% |      1.68 | `Ducco 1e-4 16 threads`
|       24,461,132.60 |               40.88 |    0.2% |   94,985,909.40 |   57,800,654.00 |  1.643 |   5,901,750.80 |    0.5% |      1.47 | `Ducco 1e-4 16 threads float`
|       38,049,807.40 |               26.28 |    0.3% |  180,686,363.40 |   95,224,163.83 |  1.897 |  11,415,654.60 |    0.5% |      2.28 | `Ducco 1e-4 8 threads`
|       36,013,203.60 |               27.77 |    0.2% |  184,567,803.20 |   93,448,693.83 |  1.975 |  11,373,860.40 |    0.5% |      2.16 | `Ducco 1e-4 8 threads float`
|       46,204,953.60 |               21.64 |    0.3% |  242,307,766.50 |  116,781,956.00 |  2.075 |  15,277,996.00 |    0.5% |      2.77 | `Ducco 1e-4 6 threads`
|       43,755,238.00 |               22.85 |    0.4% |  253,121,146.20 |  120,862,158.60 |  2.094 |  15,587,196.00 |    0.5% |      2.63 | `Ducco 1e-4 6 threads float`
|       59,475,115.80 |               16.81 |    0.2% |  354,763,380.50 |  162,042,707.67 |  2.189 |  22,196,754.17 |    0.5% |      3.57 | `Ducco 1e-4 4 threads`
|       59,157,025.17 |               16.90 |    0.2% |  382,848,719.50 |  175,843,370.83 |  2.177 |  23,595,635.67 |    0.5% |      3.55 | `Ducco 1e-4 4 threads float`
|       38,257,984.67 |               26.14 |    0.2% |  185,828,618.00 |   96,719,700.60 |  1.921 |  11,702,591.67 |    0.4% |      2.29 | `Ducco 1e-4 8 fourier output`
32 threads verbose
Nu2u:
  nthreads=32, grid=(128x128x128), oversampled grid=(162x162x162), supp=12, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 6.335270404815674e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.04277s
|
+- nu2u proper          : 95.06% (0.0407s)
|  |
|  +- spreading            : 77.31% (0.0314s)
|  +- FFT                  : 11.03% (0.0045s)
|  +- zeroing grid         :  8.40% (0.0034s)
|  +- grid correction      :  3.20% (0.0013s)
|  +- allocating grid      :  0.06% (0.0000s)
|  
+- building index       :  3.72% (0.0016s)
+- correction factors   :  0.85% (0.0004s)
+- parameter calculation:  0.03% (0.0000s)
+- <unaccounted>        :  0.33% (0.0001s)
16 threads verbose
Nu2u:
  nthreads=16, grid=(128x128x128), oversampled grid=(168x168x168), supp=11, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 7.065582275390625e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.04139s
|
+- nu2u proper          : 96.16% (0.0398s)
|  |
|  +- spreading            : 78.93% (0.0314s)
|  +- FFT                  : 10.68% (0.0042s)
|  +- zeroing grid         :  6.72% (0.0027s)
|  +- grid correction      :  3.62% (0.0014s)
|  +- allocating grid      :  0.05% (0.0000s)
|  
+- building index       :  3.48% (0.0014s)
+- correction factors   :  0.10% (0.0000s)
+- parameter calculation:  0.03% (0.0000s)
+- <unaccounted>        :  0.23% (0.0001s)
8 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.05809s
|
+- nu2u proper          : 96.31% (0.0559s)
|  |
|  +- spreading            : 77.14% (0.0432s)
|  +- FFT                  : 14.69% (0.0082s)
|  +- zeroing grid         :  5.26% (0.0029s)
|  +- grid correction      :  2.87% (0.0016s)
|  +- allocating grid      :  0.04% (0.0000s)
|  
+- building index       :  3.49% (0.0020s)
+- correction factors   :  0.06% (0.0000s)
+- parameter calculation:  0.02% (0.0000s)
+- <unaccounted>        :  0.13% (0.0001s)
4 threads verbose 
Nu2u:
  nthreads=4, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.09319s
|
+- nu2u proper          : 95.95% (0.0894s)
|  |
|  +- spreading            : 77.77% (0.0695s)
|  +- FFT                  : 14.53% (0.0130s)
|  +- zeroing grid         :  5.07% (0.0045s)
|  +- grid correction      :  2.59% (0.0023s)
|  +- allocating grid      :  0.04% (0.0000s)
|  
+- building index       :  3.92% (0.0037s)
+- correction factors   :  0.04% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
```
