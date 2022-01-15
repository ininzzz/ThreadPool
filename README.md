## ThreadPool

- C++11实现的线程池
- 参考自[progschj/ThreadPool](https://github.com/progschj/ThreadPool)

| 函数                         | 功能                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| ThreadPool(int = maxn);      | 创建一个拥有n个线程的线程池，最大值为std::thread::hardware_concurrency(); |
| ~ThreadPool()                | 不再允许向任务队列中添加任务，并让线程跑完任务队列中的其余任务，最后结束所有线程 |
| void run()                   | 唤醒线程池中睡眠的线程并分配任务队列中的任务                 |
| void clear()                 | 清空所有任务队列中的任务并结束所有线程                       |
| void append(F &&, Args&&...) | 向任务队列中添加任务                                         |

```cpp
void foo(int a) {
    std::cout << a << std::endl;
}

int main() {
    ThreadPool tp(8);
    tp.run();
    for (int i = 0;i < 32;i++) {
        tp.append(foo, i);
    }
    tp.clear();
    std::cout << "-----\n";
    for (int i = 0;i < 32;i++) {
        tp.append(foo, i);
    }
    tp.run();
    tp.clear();
    return 0;
}
```

