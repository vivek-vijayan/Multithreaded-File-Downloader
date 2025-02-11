#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <string>
#include "ThreadPool.h"

class Downloader {
public:
    Downloader(const std::string& url, int numThreads);
    void start();
    void pause();
    void resume();
    void stop();

private:
    std::string fileURL;
    int threads;
    ThreadPool* threadPool;
    void downloadChunk(int start, int end, int chunkId);
};

#endif