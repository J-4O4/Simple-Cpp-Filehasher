# Simple C++ Filehasher

A simple Windows C++ command-line tool for calculating file hashes. 

## Features
- Calculate file hashes from the command line
- Supports MD5, SHA-1 and SHA-256 hashes
- Uses OpenSSL's EVP API for hash calculation

## Usage

```text
Filehasher.exe -f <filepath> -<hashtype>
```

If you need help with supported flags:

```text
Filehasher.exe -h
```

### Examples:

**Hash a file in the same directory:**
`Filehasher.exe -f test.exe -sha256`

**Run Filehasher from another directory using its full path:**
`path/to/Filehasher.exe -f path/test.exe -md5`

**Run FileHasher from another directory:**
`C:\Tools\Filehasher\Filehasher.exe -f "C:\Users\User\Desktop\test.exe" -sha1`

## Installation

The Filehasher is built for Windows x64 systems.

To run the pre-compiled version, download the repository as a ZIP file and extract it. Please download the entire repository rather than only the .exe file, as the required runtime files are included in the repository.

If you want to run Filehasher from anywhere in your terminal, you can add the extracted folder containing Filehasher.exe to your system's PATH environment variable.

Filehasher uses the OpenSSL EVP API for calculating file hashes. If you want to build Filehasher from source, you will need a C++ compiler and any [OpenSSL](https://slproweb.com/products/Win32OpenSSL.html) 3.x installed.

## License

The Filehasher source code is licensed under the MIT license included in this repository. See [LICENSE](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/LICENSE) for the full license text. 

### Third-Party Software

Filehasher uses OpenSSL's libcrypto library for hash calculations.

OpenSSL is licensed under the Apache License 2.0.
See [LICENSE-OpenSSL]([LICENSE-OpenSSL](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/LICENSE-OpenSSL.txt))
