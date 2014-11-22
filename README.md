# Description

Benchmark a custom modPow function against the one from Java

## Benchmarked on

* Dual core Intel Core2 Duo P8400 @ 2267Mhz
* 3.17.1-1-ARCH x86\_64
* gmp 6.0.0
* gcc 4.9.2
* OpenJDK Runtime Environment (IcedTea 2.5.3) (Arch Linux build 7.u71\_2.5.3-3-x86\_64)

## Test parameters

(in `test.c` and Java source)

```
base: 1234567890987654321
exponent: 1234567890987654321
modulus: 1234567890
rounds: 1000000
result: 934566831
```


# C/GMP

## Dependencies

* C Compiler
* libgmp
* make

## Execute

```sh
$ make test
$ ./test
```

## Results

100000 executions per second


# Java

## Dependencies

* Maven
* Microbenchmark framework (Downloaded by maven)

## Execute

```sh
$ mvn package
$ java -jar target/benchmarks.jar net.weissschuh.dhbw.math.ModPowBenchmark.test
```

## Results

164060 executions per second
