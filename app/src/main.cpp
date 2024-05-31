#include <iostream>
#include <fstream>
#include <vector>
#include <getopt.h>
#include "app.hpp"
#include "crc16.h"

#define APP_VERSION "1.0"

uint16_t calculate_file_crc(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return crc16_ccitt(buffer.data(), buffer.size());
}

void print_help() {
    std::cout << "Usage: app [options]\n"
              << "Options:\n"
              << "  --file, -f <filename>   Calculate CRC16-CCITT of the specified file\n"
              << "  --help, -h              Show this help message\n"
              << "  --version, -v           Show version information\n";
}

int main(int argc, char* argv[]) {
    const char* const short_opts = "f:hv";
    const option long_opts[] = {
        {"file", required_argument, nullptr, 'f'},
        {"help", no_argument, nullptr, 'h'},
        {"version", no_argument, nullptr, 'v'},
        {nullptr, no_argument, nullptr, 0}
    };

    std::string filename;

    while (true) {
        const int opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt == -1) break;

        switch (opt) {
            case 'f':
                filename = optarg;
                break;
            case 'h':
                print_help();
                return 0;
            case 'v':
                std::cout << "App version " << APP_VERSION << "\n";
                return 0;
            case '?':
            default:
                print_help();
                return 1;
        }
    }

    if (filename.empty()) {
        print_help();
        return 1;
    }

    try {
        uint16_t crc = calculate_file_crc(filename);
        std::cout << "CRC16-CCITT of file " << filename << " is " << std::hex << crc << std::dec << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
