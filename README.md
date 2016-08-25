# 2D/3D Lattice Boltzmann - Discrete Element Method (lbmdem)
> Cambridge Berkeley - Geomechanics

[![Build status](https://api.travis-ci.org/cb-geo/lbmdem.svg)](https://api.travis-ci.org/cb-geo/lbmdem.svg)

## Install dependencies

* Docker image for CB-Geo LBM-DEM code [https://hub.docker.com/r/cbgeo/lbmdem](https://hub.docker.com/r/cbgeo/lbmdem)

* Instructions for running lbmdem docker container: [https://github.com/cb-geo/docker-lbmdem/blob/master/README.md](https://github.com/cb-geo/docker-lbmdem/blob/master/README.md).

## Compile & Run

0. Run `aclocal -I ./m4 && autoconf && automake --add-missing` or `autoreconf -fi`, if `configure` script is missing.

1. Run `./configure`

2. `make clean && make -jN` (where N is the number of cores)

3. Run lbmdem `./lbmdem`

## Run  test cases

0. Run `aclocal -I ./m4 && autoconf && automake --add-missing` or `autoreconf -fi`, if `configure` script is missing.

1. Run `./configure`

2. `make clean && make check -jN` (where N is the number of cores)

3. Run lbmdemtest `./lbmdemtest`

