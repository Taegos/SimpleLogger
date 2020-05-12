#pragma once
#include <iostream>

#define nl '\n'

class SimpleLogger
{
public:
    SimpleLogger(bool enabled = true) : enabled{ enabled } {}

    template<typename T>
    void operator()(T);

    template<typename T, typename ...Args>
    void operator()(T, Args...);

private:
    const bool enabled;
};

template<typename T>
void SimpleLogger::operator()(T t) {
    if (!enabled) return;
    std::cout << t;
}

template<typename T, typename ...Args>
void SimpleLogger::operator()(T t, Args... args) {
    if (!enabled) return;
    std::cout << t;
    (*this)(args...);
}