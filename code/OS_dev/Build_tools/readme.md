# toolchain
32 bit ELF build toolchain


1. `sudo apt update`
2. `sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo`
3. `sudo apt install nasm qemu-system-x86`
4. `git clone https://github.com/Kinar-Usha/toolchain.git`
5. `cd toolchain`
6. `make` the compilations should take about 20 minutes.

## ERROR handling
if you get this error ->
`configure: error: Building GCC requires GMP 4.2+, MPFR 2.4.0+ and MPC 0.8.0+.
Try the --with-gmp, --with-mpfr and/or --with-mpc options to specify
their locations. Source code for these libraries can be found at
their respective hosting sites as well as at
ftp://gcc.gnu.org/pub/gcc/infrastructure/. See also
http://gcc.gnu.org/install/prerequisites.html for additional info. If
you obtained GMP, MPFR and/or MPC from a vendor distribution package,
make sure that you have installed both the libraries and the header
files. They may be located in separate packages.`


solution 
1. `cd ~/toolchain/toolchain/gcc-11.2.0`
2.  `.contrib/download_prerequisites`

3. after the pre-requisites are downloaded 
 1. `cd ~/toolchain`
 2. `make clean-toolchain`
 3. `make`
