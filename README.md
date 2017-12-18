# Athena

Copyright (c) 2017-2018 The Athena Project.

Portions Copyright (c) 2017-2018 The CryptAthlos developers.

Portions Copyright (c) 2014-2017 The Monero Project.

Portions Copyright (c) 2012-2013 The Cryptonote developers.

This is the reference code for [CryptAthlos](https://cryptathlos.io) cryptocurrency protocol.

## Development resources

- Web: [cryptathlos.io](https://cryptathlos.io)
- Forum: [forum.cryptathlos.io](https://forum.cryptathlos.io)
- Mail: [cryptathlos@gmail.com](mailto:cryptathlos@gmail.com)
- GitHub: [https://github.com/cryptathlos/athena](https://github.com/cryptathlos/athena)

## Building Athena

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, and Boost 1.55.

You may download them from:

* http://gcc.gnu.org/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run `make`. The resulting executables can be found in `build/release/src`.

## Compiling Athena from source

### Dependencies

The following table summarizes the tools and libraries required to build. A
few of the libraries are also included in this repository (marked as
"Vendored"). By default, the build uses the library installed on the system,
and ignores the vendored sources. However, if no library is found installed on
the system, then the vendored source will be built and used. The vendored
sources are also used for statically-linked builds because distribution
packages often include only shared library binaries (`.so`) but not static
library archives (`.a`).

| Dep            | Min. version  | Vendored | Debian/Ubuntu pkg  | Arch pkg       | Optional | Purpose        |
| -------------- | ------------- | ---------| ------------------ | -------------- | -------- | -------------- |
| GCC            | 4.7.3         | NO       | `build-essential`  | `base-devel`   | NO       |                |
| CMake          | 3.0.0         | NO       | `cmake`            | `cmake`        | NO       |                |
| pkg-config     | any           | NO       | `pkg-config`       | `base-devel`   | NO       |                |
| Boost          | 1.55          | NO       | `libboost-all-dev` | `boost`        | NO       | C++ libraries  |
| OpenSSL        | basically any | NO       | `libssl-dev`       | `openssl`      | NO       | sha256 sum     |
| libzmq         | 3.0.0         | NO       | `libzmq3-dev`      | `zeromq`       | NO       | ZeroMQ library |
| libunbound     | 1.4.16        | YES      | `libunbound-dev`   | `unbound`      | NO       | DNS resolver   |
| libminiupnpc   | 2.0           | YES      | `libminiupnpc-dev` | `miniupnpc`    | YES      | NAT punching   |
| libunwind      | any           | NO       | `libunwind8-dev`   | `libunwind`    | YES      | Stack traces   |
| liblzma        | any           | NO       | `liblzma-dev`      | `xz`           | YES      | For libunwind  |
| libreadline    | 6.3.0         | NO       | `libreadline6-dev` | `readline`     | YES      | Input editing  |
| ldns           | 1.6.17        | NO       | `libldns-dev`      | `ldns`         | YES      | SSL toolkit    |
| expat          | 1.1           | NO       | `libexpat1-dev`    | `expat`        | YES      | XML parsing    |
| GTest          | 1.5           | YES      | `libgtest-dev`^    | `gtest`        | YES      | Test suite     |
| Doxygen        | any           | NO       | `doxygen`          | `doxygen`      | YES      | Documentation  |
| Graphviz       | any           | NO       | `graphviz`         | `graphviz`     | YES      | Documentation  |

[^] On Debian/Ubuntu `libgtest-dev` only includes sources and headers. You must
build the library binary manually. This can be done with the following command:

```
$ sudo apt-get install libgtest-dev && cd /usr/src/gtest && sudo cmake . && sudo make && sudo mv libg* /usr/lib/
```

### Build instructions

Athena uses the CMake build system and a top-level [Makefile](Makefile) that
invokes cmake commands as needed.

#### On Linux and OS X

* Install the dependencies
* Change to the root of the source code directory and build:

```
$ cd athena
$ make
```
* The resulting executables can be found in:
```
~/athena/build/release/src
```

* Add
```
PATH="$PATH:$HOME/athena/build/release/bin"
```
to
```
$ nano .profile
```

Run Athena with:
```
$ athenad --detach
```
**Advanced Build Options:**

* Parallel build:
```
$ make -j<number of threads>
```

* Debug build:
```
$ make build-debug
```

* Test suite or Test with debug:
```
$ make test-release
```

```
$ make test-debug
```

* Building with Clang: it may be possible to use Clang instead of GCC, but this may not work everywhere. To build, run `export CC=clang CXX=clang++` before running `make`.