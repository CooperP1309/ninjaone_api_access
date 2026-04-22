#include <windows.h>
#include <string>

const char* get_credentials_path() {
    static std::string path;  // persists after function returns

    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);

    std::string full_path(buffer);

    size_t pos = full_path.find_last_of("\\/");
    if (pos != std::string::npos) {
        path = full_path.substr(0, pos) + "\\client_credentials.txt";
    } else {
        path = "client_credentials.txt";  // fallback
    }

    return path.c_str();
}