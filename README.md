# Gasm
An Assembly Interpreter.

## What is Gasm

Gasm is an assembly interpreter. It can allocate a section of memory as virtual memory to make sure your operation safety. CPU port support will come soon. 

## Download

To get the sources from git, click [here](https://github.com/GurthPalarran/gasm). To get a binary snapshot, see [here](https://github.com/GurthPalarran/gasm/releases/tag/gasm-1.0).

## Build

First of all please make sure you have installed the following package:

```
sudo apt update && sudo apt install nasm
```

If you get source from git, please check out brunch "outasm".

```
git check outasm
```

Then

```
mkdir build
cmake ..
make
```

To run gasm:

```
./gasm
```

## Contact me:

gurthpalarran@outlook.com