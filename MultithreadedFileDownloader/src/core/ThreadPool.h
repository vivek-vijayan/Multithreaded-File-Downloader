#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <functional>
#include <queue>
#include <condition_variable>
#include <mutex>

class ThreadPool {
public:
    ThreadPool(int numThreads);
    ~ThreadPool();
    void enqueueJob(const std::function<void()>& job);
    
private:
    void worker();

    int numThreads;
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> jobQueue;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop;
};

#endif