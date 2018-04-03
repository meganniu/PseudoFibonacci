# Pseudo Fibonacci

Given the two initial terms of the sequence, the program displays the next 10 terms. Each terms of the sequence are calculated with the formula for the Fibonacci sequence: Fn = Fn-1 + Fn-2

## Prerequisites

In order to run the unit tests in the `TestFibonacci` class, the libraries and headers for cppunit must be installed.

On Ubuntu 16.04, cppunit libraries and headers can be installed by typing the following into the terminal
```
sudo apt-get install libcppunit-dev
```
The procedure for the installation of cppunit is similar on other Linux operating systems.

## Compiling

The executable files can be compiled using the makefile included. To create both the `RunFibonacci`  and the `TestFibonacci` executables, navigate to the PseudoFibonacci folder and use

```
make all
```
To compile just the `PseudoFibonacci` class and create the `RunFibonacci` executable, use
```
make run
```
To compile the automated tests and create the `TestFibonacci` executable, use
```
make test
```
## Running the program

After compiling using `make all` or `make run`, run the program by using the following in terminal
```
./RunFibonacci
```
When prompted, type the first and second terms of the sequence. The program accepts integers and floating point numbers. For instance,
```
First Number: -1.45
Second Number: 3
```
is considered valid. The program will not accept the input of non-numerical characters (exlcuding the decimal point).

## Running the tests

After compiling the tests in `TestFibonacci.cpp` using `make all` or `make test`, run the tests using the following in terminal
```
./TestFibonacci
```

### Test Breakdown

1. `testPositives` tests that the output is correct when two positive rational numbers are entered.
2. `testNegatives` tests that the output is correct when two negative rational numbers are entered.
3. `testMixed` tests that the ouput is correct when a postive and a negative rational number are entered.
4. `testZeroes` tests that the output is correct when two zeroes are entered.
5. `testLength` tests that the length of the output is correct (i.e. 10 terms are calculated). It does not test for the correct values in the output.
6. `testIntegers` tests that the ouput is correct when two integers are entered.
7. `testDisplay` tests that the sequence is correctly displayed in terms of values and formatting.

**NOTE:**
In the `TestFibonacci` class, the `equal` method is used to compare the floating-point values to determine if the content of two containers are the same. Due to the inaccuracy of floating-point values, an error of `0.0000000000001` has been allowed. This is the smallest value of error, as determined through trial and error. (Although the process seems a tad shady and the acceptable error may need adjusting when comparing smaller values.)

## Documentation

Documentation for all the classes can be acessed using the makefile. For firefox, type

```
make openDocFirefox
```
For google chrome, type
```
make openDocChrome
```
If your preferred browser is not Firefox or Chrome, type
```
BROWSER html/index.html
```
and subsitute `BROWSER` for your preferred browser.

## Author

[Megan Niu](https://github.com/meganniu)

## Acknowledgments

The `main` function of `TestFibonacci.cpp` was adjusted from a cppunit tutorial found [here](yolinux.com/TUTORIALS/CppUnit.html).
2-clause BSD License: <http://www.yolinux.com/YoLinux-Terms.html>
