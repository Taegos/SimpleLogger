#pragma once
#include <iostream>

class SimpleLogger
{
public:
    SimpleLogger(bool enabled = true) : enabled{ enabled } {}

    template<typename T>
    void out(T);

    template<typename T, typename ...Args>
    void out(T, Args...);

    template<typename T>
    void outnl(T);

    template<typename T, typename ...Args>
    void outnl(T, Args...);

private:
    const bool enabled;
};

template<>
void SimpleLogger::out(float f) {
    if (!enabled) return;
    std::cout << f;
}

template<typename T>
void SimpleLogger::out(T t) {
    if (!enabled) return;
    std::cout << t;
}

template<typename T, typename ...Args>
void SimpleLogger::out(T t, Args... args) {
    out(t);
    out(args...);
}

template<typename T>
void SimpleLogger::outnl(T t) {
    out(t, '\n');
}

template<typename T, typename ...Args>
void SimpleLogger::outnl(T t, Args... args) {
    out(t, args..., '\n');
}