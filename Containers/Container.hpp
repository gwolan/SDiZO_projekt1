#pragma once

#include <cstdint>


class Container
{
    public:
    Container();
    ~Container() = default;

    bool isEmpty();
    uint32_t getSize();
    void alignOutOfRangeIndexToSize(uint32_t& index);
    virtual void clear() = 0;
    virtual void display() = 0;

    protected:
    uint32_t size;
};
