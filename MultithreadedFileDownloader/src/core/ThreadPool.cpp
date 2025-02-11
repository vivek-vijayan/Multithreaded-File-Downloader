#include "ThreadPool.h"
#include <iostream>

ThreadPool::ThreadPool(int numThreads)
    : numThreads(numThreads), stop(false) {
    for (int i = 0; i < numThreads; ++i) {
        workers.push_back(std::thread(&ThreadPool::worker, this));
    }
}

ThreadPool::~ThreadPool() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all();
    
    for (auto& worker : workers) {
        worker.join();
    }
}

void ThreadPool::enqueueJob(const std::function<void()>& job) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        jobQueue.push(job);
    }
    cv.notify_one();
}

void ThreadPool::worker() {
    while (true) {
        std::function<void()> job;
        
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]{ return stop || !jobQueue.empty(); });
            
            if (stop && jobQueue.empty()) return;
            
            job = jobQueue.front();
            jobQueue.pop();
        }
        
        job();
    }
}