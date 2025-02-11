#include "core/Downloader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <URL> [num_threads]\n";
        return 1;
    }

    std::string url = argv[1];
    int num_threads = (argc == 3) ? std::stoi(argv[2]) : 4; // Default to 4 threads if not provided

    Downloader downloader(url, num_threads);
    downloader.start();

    return 0;
}