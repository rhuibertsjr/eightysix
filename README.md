# Project "EightySix"
Eightysix is a partial 8086 assembler / simulator. The 8086 was a 16-bit microprocessor
designed by Intel and gave rise to the well known x86 architecture. The philosophy driving
this project is performance-oriented, a term coined by the software engineer Casey Muratori.
He has an entire course dedicated to this principle:

- [Perfomance-Aware Programming](https://www.computerenhance.com/p/table-of-contents) by Casey Muratori.

## 1. Getting started
Download the `.zip` from this page, or run this command inside the desired directory.

```bash
$ git clone https://github.com/rhuibertsjr/eightysix
$ cd eightysix
```

### 1.1 Building
Building the **Eightysix** codebase can be done in a terminal which is equipped with the
ability to call either MSVC (Windows 10+) or GNU GCC on a GNU / Linux machine. On a Windows
machine call the following script:

```bash
$ build.bat 
```

Or on a GNU / Linux machine:

```bash
$ ./scripts/build.sh 
```

> **Note**: Visual Studio 2020 (Community) Edition is needed for the use of the MSVC
> build. Then `vcvarsall.bat x64` has to be called in your terminal to setupt the right
> enviroment variables.

### 1.2 Running 
Running the **Eightysix** codebase can be done by running `eightysix.exe` (or `eightysix),
or by the following scripts:

```bash
$ start.bat 
```

Or on a GNU / Linux machine:

```bash
$ ./scripts/start.sh 
```

This will give you the following prompt:
```
$ start.bat 
  (EightyOne) Usage: '%s [DEST FILE] [SOURCE FILE]
    - Make sure you have provided a destination and source file
    - Please enter a valid file name (do not use any letter outside the ASCII standard).
```
Where the user provides its own *destination* and the source files (mostly refered to as
listings) are inside the `data/listings/` folder.