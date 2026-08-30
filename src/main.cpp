#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cstring>
#include <sys/stat.h>
#include <openssl/evp.h>

using namespace std;

bool file_exists(const string &filename){
    return filesystem::exists(filename);
}

void calculate_hash(const unsigned char* data, size_t length, char type[]) {
    string chosen_hash;
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if(strcmp(type, "-sha256") == 0){
        chosen_hash = "SHA-256";
        if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1) {
            EVP_MD_CTX_free(context);
            return;
        }
    }
    else if(strcmp(type, "-md5") == 0){
        chosen_hash = "MD5";
        if (EVP_DigestInit_ex(context, EVP_md5(), nullptr) != 1) {
            EVP_MD_CTX_free(context);
            return;
        }
    }
    else if(strcmp(type, "-sha1") == 0){
        chosen_hash = "SHA-1";
        if (EVP_DigestInit_ex(context, EVP_sha1(), nullptr) != 1) {
            EVP_MD_CTX_free(context);
            return;
        }
    }
    else{
        cout << "[*] Invalid hash, closing program...";
        EVP_MD_CTX_free(context);
        return;
    }

    if (context == nullptr) {
        cout << "[*] Failed to create hash context.";
        return;
    }

    if (EVP_DigestUpdate(context, data, length) != 1) {
        EVP_MD_CTX_free(context);
        return;
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_length = 0;

    if (EVP_DigestFinal_ex(context, hash, &hash_length) != 1) {
        EVP_MD_CTX_free(context);
        return;
    }

    EVP_MD_CTX_free(context);

    stringstream ss;
    for (unsigned int i = 0; i < hash_length; ++i) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }
    cout << "[*] " << chosen_hash << " hash: " << ss.str();
}

int main (int argc, char *argv[]){

    if(argc < 4 || argc > 4){
        cout << "[*] Missing Arguments: (-f <filepath>) or -<hashtype>\n";
        cout << "[*] Valid Syntax: Filehasher.exe -f <filepath> -<hashtype>\n";
        cout << "[*] supported hash types: md5, sha1, sha256\n";
        return 0;
    }
    
    // Checking if C strings are equal to each other
    else if(strcmp(argv[1], "-h") == 0){
        cout << "Flags: \n\n";
        cout << "-f : Specifies the path to the file you wish to hash\n";
        cout << "-sha256 : calculate the SHA-256 hash of a file\n";
        cout << "-md5 : calculate the MD5 hash of a file\n";
        cout << "-sha1 : calculate the SHA-1 hash of a file\n\n";
        cout << "[*] Valid Syntax: Filehasher.exe -f <filepath> -<hashtype>\n";
        return 0;
    }

    else if(strcmp(argv[1], "-f") == 0){
        string File = argv[2];
        string FileText;
        string Binary_data;

        // Making sure the file exists
        if(file_exists(File)){
            
            // Telling our ifstream to read it in binary mode
            ifstream ReadFile(File, ios::binary);
                
            // Calculating size in bytes of the binary
            ReadFile.seekg(0, ios::end);
            streamsize size = ReadFile.tellg();
            ReadFile.seekg(0, ios::beg); 

            // Pointer to a temporary space in memory containing the bytes
            vector<unsigned char> buffer(size);

            if (ReadFile.read(reinterpret_cast<char*>(buffer.data()), size)) {
                calculate_hash(buffer.data(), size, argv[3]);
                ReadFile.close();
            }
            else{
                cout << "Error reading the file data!" << endl;
            }
        }
        else{
            cout << "This file wasn't found!";
        }
    }

    return 0;
}