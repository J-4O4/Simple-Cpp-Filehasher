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


## Pre compiled version:
Download the latest `Filehasher.exe` from the **Releases -> Assets** section of this repository. No additional software or compilation is required. The pre-compiled executable can be run directly on Windows. You can also add the directory containing FileHasher.exe to your system's PATH environment variable. This allows you to run FileHasher from any directory in your terminal.

## Build from Source
If you want to modify the source code or compile Filehasher yourself, you will need a C++ compiler and the required OpenSSL development files. The repository includes the OpenSSL files used by the current build setup.

## License
The Filehasher source code is licensed under the MIT license included in this repository. See [LICENSE](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/LICENSE) for the full license text. The OpenSSL files included in this repository are subject to their respective OpenSSL license terms. See [OpenSSL/LICENSE.txt](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/OpenSSL/LICENSE.txt).
