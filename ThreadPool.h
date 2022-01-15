#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

const int maxn = std::thread::hardware_concurrency();

class ThreadPool {
public:
    ThreadPool(int = maxn);
    ~ThreadPool();
    void run();
    void clear();
    template<typename F, typename... Args>
    void append(F &&, Args&&...);
private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;

    std::mutex mut;
    std::condition_variable cond;
    bool stop;
};

#endif