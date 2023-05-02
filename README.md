# guppy

Guppy prints lines that contain a match for pattern using C++

## Usage

`guppy [OPTION]... PATTERN [FILE]...`

Search for PATTERN in each FILE.

Example: `guppy -i 'hello world' menu.h main.c`

## Build from source

App requires [make](https://www.gnu.org/software/make/) and [g++](https://gcc.gnu.org/) (with support for C++20) to build.

To build simply run `make`.
