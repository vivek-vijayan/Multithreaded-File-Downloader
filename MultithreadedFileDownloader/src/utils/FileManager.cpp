#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveChunkToFile(const std::string& fileName, int startByte, const char* data, int dataSize) {
    std::ofstream outFile(fileName, std::ios::binary | std::ios::app);
    outFile.seekp(startByte);
    outFile.write(data, dataSize);
    outFile.close();
}

void FileManager::mergeChunks(const std::string& fileName, int totalChunks) {
    std::cout << "Merging " << totalChunks << " chunks into final file: " << fileName << "\n";
    // Logic to merge chunks (if needed)
}