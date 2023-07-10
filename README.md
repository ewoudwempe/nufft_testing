Requires fftw to be installed and in the compiler search path. Can be built (on mac) with 
```
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=$PWD/homebrew.cmake -B build -G Ninja && ninja -C build
```

# Sample (my laptop):
```
|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|      224,389,125.00 |                4.46 |    1.1% |      7.74 | `FINUFFT 3d`
|      221,164,069.67 |                4.52 |    1.5% |      7.53 | `FINUFFT With plan`
|      278,953,166.67 |                3.58 |    1.0% |      9.46 | `FINUFFT With plan & FFTW_MEASURE`
|       66,403,916.67 |               15.06 |    2.0% |      2.29 | `Ducco 1e-6 8 threads`
|       46,920,552.00 |               21.31 |    1.4% |      1.60 | `Ducco 1e-4 8 threads`
|       47,314,402.67 |               21.14 |    1.1% |      1.62 | `Ducco 1e-4 fourier output`
|       44,776,416.67 |               22.33 |    2.6% |      1.52 | `Ducco 1e-4 6 threads`
|       43,345,888.67 |               23.07 |    0.9% |      1.48 | `Ducco 1e-4 4 threads`
8 threads verbose
Nu2u:
  nthreads=8, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.06562s
|
+- nu2u proper          : 96.23% (0.0631s)
|  |
|  +- spreading            : 76.31% (0.0482s)
|  +- FFT                  : 16.37% (0.0103s)
|  +- zeroing grid         :  4.84% (0.0031s)
|  +- grid correction      :  2.49% (0.0016s)
|  +- allocating grid      :  0.00% (0.0000s)
|  
+- building index       :  3.52% (0.0023s)
+- correction factors   :  0.09% (0.0001s)
+- parameter calculation:  0.01% (0.0000s)
+- <unaccounted>        :  0.14% (0.0001s)
4 threads verbose 
Nu2u:
  nthreads=4, grid=(128x128x128), oversampled grid=(180x180x180), supp=10, eps=1.000000000000000e-06
  npoints=500000
  memory overhead: 1.862645149230957e-03GB (index) + 8.690357208251953e-02GB (oversampled grid)

Total wall clock time for nu2u: 0.07597s
|
+- nu2u proper          : 96.33% (0.0732s)
|  |
|  +- spreading            : 77.88% (0.0570s)
|  +- FFT                  : 15.81% (0.0116s)
|  +- zeroing grid         :  4.03% (0.0030s)
|  +- grid correction      :  2.27% (0.0017s)
|  +- allocating grid      :  0.00% (0.0000s)
|  
+- building index       :  3.55% (0.0027s)
+- correction factors   :  0.04% (0.0000s)
+- parameter calculation:  0.01% (0.0000s)
```
