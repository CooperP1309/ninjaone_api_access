#include <iostream>
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <shellapi.h>

// src libs
#include "access_token.h"
#include "file_ops.h"

int main() {

    const char* credentials_path = get_credentials_path();

    char* access_token = (char*)malloc(BUFFER_SIZE);
    access_token[0] = '\n';

    if (get_access_token(credentials_path, access_token)) {
        return 0;
    }

    std::cout << "[MAIN] Access Token: " << access_token << std::endl;

    return 0;
}