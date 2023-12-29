## Installation Guide

1. Run the following to install the required libraries
```bash
sudo apt-get install libcurl4-openssl-dev libgtest-dev
```
2. For the first time install to allow CMake to make the makefiles for your build system, run `build.sh`.
3. On subsequent building and running, just run `run.sh`. 
4. Tests can be run with `test.sh`.