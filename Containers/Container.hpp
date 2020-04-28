#pragma once

#include <cstdint>


class Container
{
    public:
    Container();
    ~Container() = default;

    bool isEmpty();
    uint32_t getSize();
    virtual void clear() = 0;
    virtual void display() = 0;

    protected:
    uint32_t size;
    const int32_t npos;
};
