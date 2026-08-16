# Simple C++ Filehasher

A simple Windows C++ command-line tool for calculating file hashes.

## Supported Hashes

- MD5
- SHA-1
- SHA-256

## Usage

```text
Filehasher.exe -f <filepath> -<hashtype>
```

If you need help with supported flags:

```text
Filehasher.exe -h
```

Examples:

**Hash a file in the same directory:**
`Filehasher.exe -f test.exe -sha256`

**Run Filehasher from another directory using its full path:**
`path/to/Filehasher.exe -f path/test.exe -md5`

## Set up

You can either run Filehasher directly from the directory where the executable is located, or add the directory containing Filehasher.exe to your system's PATH environment variable. Adding FileHasher to your PATH allows you to run it from any directory in your terminal.

## prerequisites

You do not need to install any additional software to use the pre-compiled version of Filehasher provided in this repository. However, Filehasher uses OpenSSL [(Download here)](https://slproweb.com/products/Win32OpenSSL.html) to calculate file hashes.
If you want to modify the source code and compile your own version, you will need to install OpenSSL. I recommend using a recent version of OpenSSL. FileHasher uses the newer EVP API for generating hashes, as the older hash APIs have been deprecated in recent OpenSSL versions.
