# Simple C++ Filehasher

A simple Windows C++ command-line tool for calculating file hashes.

# ⚠️ PLEASE NOTE
Some antivirus engines currently flag the latest FileHasher release as a potential threat. The previous version of FileHasher was not detected, while the current version receives several detections. I suspect this may be related to the changes in the build configuration, including static linking, which was introduced so that the pre-compiled binary can run without requiring users to install OpenSSL or the compiler runtime separately.
I am currently investigating the cause and working on a solution to reduce or eliminate these false positives: [Report](https://www.virustotal.com/gui/file/487072d553fe248177b8eb1832ab6f55782f8e5c8ba8982880aa0ccd548369c2/detection)

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


## For normal users:
Download the latest `Filehasher.exe` from the **Releases -> Assets** section of this repository. No additional software or compilation is required. The pre-compiled executable can be run directly on Windows. You can also add the directory containing FileHasher.exe to your system's PATH environment variable. This allows you to run FileHasher from any directory in your terminal.

## Build from Source
If you want to modify the source code or compile Filehasher yourself, you will need a C++ compiler and the required OpenSSL development files. The repository includes the OpenSSL files used by the current build setup.

## License
The Filehasher source code is licensed under the MIT license included in this repository. See [LICENSE](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/LICENSE) for the full license text. The OpenSSL files included in this repository are subject to their respective OpenSSL license terms. See [OpenSSL/LICENSE.txt](https://github.com/J-4O4/Simple-Cpp-Filehasher/blob/main/OpenSSL/LICENSE.txt).
