# basic-cunit-example

## About this repository

This repository aims to be an example for me (and for everyone who finds it usefull) of the different use cases the CUnit library offers. 

Disclaimer: this repository is intended to be used under Linux (it was tested in Ubuntu 18.04). 

### CUnit

From the CUnit documentation, "CUnit is a lightweight system for writing, administering, and running unit tests in C.". You can find all relevant information in the home page of the project: http://cunit.sourceforge.net/

## Pre-requisites

* You will need to install the CUnit libraries:

    ```bash
    sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
    ```

* You will need to install lcov package:

    ```bash
    sudo apt-get install lcov
    ```

* You will need to have gcc installed

## Folder structure

```
+-- .
|  +-- bin
|    +-- <compiled files>
|  +-- doc
|    +-- <documentations files (coverage reports, unit tests results, etc)>
|  +-- inc
|    +-- <header files>
|  +-- src
|    +-- <source files>
|  +-- test
|    +-- <test files>
|  +-- makefile
|  +-- readme.md
```

## Compiling and executing tests

### Clean compiled files

Do this first: 

```bash
make clean
```

### Compiling with tests

In the projects root folder, run command:

```bash
make check
```

This will generate a bunch of different outputs:

* Console: the tests result and the code coverage will be shown in the console.
* /doc/tests.txt: tests result
* /doc/coverageReport/index.html: open this file with a web browser to navigate the coverage report

### Compiling without tests

In the projects root folder, run command:

```bash
make
```

This will generate file ./bin/main which can be run with the following commands:

```bash
cd bin
./main
```

This program is just a dummy main which calls some of the functions, it has no practical use except being an empty shell to build future programs.

## VS Code integration

If you are using Visual Studio Code to work on this example, you can integrate the coverage report very easily into the IDE using the Coverage Gutters extension. Install it and then go to File -> Preferences -> Settings -> Extensions -> coverage-gutters and configure the following:

* Coverage Report File Name: doc/**/index.html
* Lcovname: /doc/coverage.info
