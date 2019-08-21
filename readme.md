# basic-cunit-example

## About this repository

This repository aims to be an example for me (and for everyone who finds it usefull) of the different use cases the CUnit library offers. 

Disclaimer: this repository is intended to be used under Linux (it was tested in Ubuntu 18.04). 

### CUnit

### 


## Pre-requisites

First, you will need to install the CUnit libraries:

```bash
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
```

## Folder structure

+-- .
|  +-- bin
|  +-- doc
|  +-- inc
|  +-- lib
|  +-- src
|  +-- test
|  +-- makefile
|  +-- readme.md

## Compiling and executing tests

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

This program is just a dummy main function which calls some of the functions, it has no practical use, except being an empty shell to build future programs.

### Compiling with tests

In the projects root folder, run command:

```bash
make check
```

This will generate a bunch of different outputs:

* Console: the tests result and the code coverage will be shown in the console.
* /doc/tests.txt: tests result
* /doc/coverageReport/index.html: open this file with a web browser to navigate the coverage report

### Clean compiled files

Just run: 

```bash
make clean
```

## VS Code integration

If you are using Visual Studio Code to work on this example, you can integrate the coverage report very easily into the IDE using the Coverage Gutters extension. Install it and then go to File -> Preferences -> Settings -> Extensions -> coverage-gutters and configure the following:

* Coverage Report File Name: doc/**/index.html
* Lcovname: /doc/coverage.info
