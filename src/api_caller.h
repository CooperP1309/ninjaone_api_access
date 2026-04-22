#include <windows.h>
#include <string>

// src libs
#include "curl_handler.h"
#include "file_ops.h"

const char* build_auth_header(char* access_token) {
    
    std::string auth_header;

    auth_header.append("Authorization: Bearer ");
    auth_header.append(access_token);

    return auth_header.c_str();
}

int call_api(const char* endpoint, char* access_token, char* result_buffer) {

    
    
    
    const char* auth_header = build_auth_header(access_token);



    std::cout << "[api_caller.h] Endpoint: " << endpoint << std::endl;
    std::cout << "[api_caller.h] Auth Header: " << auth_header << std::endl;


    return 0;
}