#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <shellapi.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

// src libs
#include "curl_handler.h"
#include "string_ops.h"

#pragma comment(lib, "Ws2_32.lib")

#define BUFFER_SIZE 2048

struct Client_credentials {
    char* client_id;
    char* client_secret;
    char* scope;
    char* host;
};

int extract_client_credentials(const char* credentials_path, Client_credentials &credentials) {

    std::ifstream file(credentials_path);
    if (!file.is_open()) return -1;

    std::string line;

    while (std::getline(file, line)) {
        // remove Windows CR if present
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        line = trim(line);
        if (line.empty()) continue;

        size_t eq = line.find('=');
        if (eq == std::string::npos) continue;

        std::string key = trim(line.substr(0, eq));
        std::string value = trim(line.substr(eq + 1));

        value = strip_quotes(value);

        if (key == "client_id") {
            credentials.client_id = _strdup(value.c_str());
        }
        else if (key == "client_secret") {
            credentials.client_secret = _strdup(value.c_str());
        }
        else if (key == "scope") {
            credentials.scope = _strdup(value.c_str());
        }
        else if (key == "host") {
            credentials.host = _strdup(value.c_str());
        }
    }

    return 0;
}

char* build_body(Client_credentials client_credentials) {

    char* body = (char*)malloc(BUFFER_SIZE);
    body[0] = '\0';

    strcat(body, "grant_type=client_credentials&client_id=");
    strcat(body, client_credentials.client_id);
    strcat(body, "&client_secret=");
    strcat(body, client_credentials.client_secret);
    strcat(body, "&scope=");
    strcat(body, client_credentials.scope);

    return body;
} 

int extract_access_token(char* token_response) {
    
    if (!token_response) {
        return -1;  
    }

    const char* key = "\"access_token\":\"";
    char* start = strstr(token_response, key);
    if (!start) {
        return -1;
    }

    start += strlen(key);  // move to start of token

    char* end = strchr(start, '"');
    if (!end) {
        return -1;
    }

    size_t len = end - start;

    // Move token to beginning of buffer
    memmove(token_response, start, len);
    token_response[len] = '\0';

    return 0;  // success
}

int get_access_token(const char* credentials_path, char* token_buffer) {

    Client_credentials client_credentials;

    if (extract_client_credentials(credentials_path, client_credentials)) {
        std::cout << "[access_token.h] Failed to extract client credentials with path: " << credentials_path << std::endl;
        return -1;
    }

    std::string url = std::string(client_credentials.host) + "/ws/oauth/token";
    char* body = build_body(client_credentials);

    curl_post_request(url.c_str(), body, token_buffer);

    if (extract_access_token(token_buffer)) {
        std::cout << "[access_token.h] 'access_token' not found in response" << std::endl;
        return -1;
    }

    return 0;
}