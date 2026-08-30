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

## Requirements
To build FileHasher from source, you need:

- A C++ compiler, such as MinGW-w64
- OpenSSL installed on your system (Install it [here](https://slproweb.com/products/Win32OpenSSL.html))
- A Windows x64 system

FileHasher uses the OpenSSL EVP API for calculating file hashes.

## License
The Filehasher source code is licensed under the MIT license included in this repository. See [LICENSE](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/LICENSE) for the full license text. 
