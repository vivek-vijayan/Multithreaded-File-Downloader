#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {
public:
    static void saveChunkToFile(const std::string& fileName, int startByte, const char* data, int dataSize);
    static void mergeChunks(const std::string& fileName, int totalChunks);
};

#endif