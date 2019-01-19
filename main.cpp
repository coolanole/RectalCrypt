#include <iostream>
#include <string>
#include <stdexcept>
#include <stdio.h>

#include <cpr/cpr.h>

std::string execute(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

int main(int argc, char **argv) {
    std::string output = execute("arp -a");
    auto response = cpr::Post(cpr::Url{"http://localhost:3000"},
                              cpr::Parameters{{"arp", output}});

    std::cout << response.status_code << std::endl;
    std::cout << output << std::endl;
}