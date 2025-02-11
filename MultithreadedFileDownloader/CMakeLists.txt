cmake_minimum_required(VERSION 3.10)
project(MultithreadedFileDownloader)

set(CMAKE_CXX_STANDARD 17)

# Set output directories for the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define the executable
add_executable(downloader
    src/main.cpp
    src/core/Downloader.cpp
    src/core/ThreadPool.cpp
    src/network/HTTPClient.cpp
    src/utils/Logger.cpp
    src/utils/FileManager.cpp
)

# Include directories
target_include_directories(downloader PRIVATE src)