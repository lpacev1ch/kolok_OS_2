#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <mutex>

class Singleton {
public:
    static Singleton& getInstance() {
        std::call_once(initFlag, []() {
            instance = new Singleton();
        });
        return *instance;
    }

    void displayMessage() {
        std::cout << "Singleton instance: " << this << std::endl;
    }

private:
    Singleton() {}
    ~Singleton() {}

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
    static std::once_flag initFlag;
};

#endif // SINGLETON_H
