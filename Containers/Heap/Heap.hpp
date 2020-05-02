#pragma once

#include <Containers/Container.hpp>


class Heap : public Container
{
    public:
    Heap();
    ~Heap();

    void clear();
    void display();
    void add(int32_t value);
    bool remove(uint32_t index);
    bool search(int32_t value);
    uint32_t getIndex(int32_t value);
    bool allocateCapacity(uint32_t newCapacity);


    private:
    uint32_t parentNodeId(uint32_t currentNode);
    uint32_t leftSiblingNodeId(uint32_t currentNode);
    uint32_t rightSiblingNodeId(uint32_t currentNode);
    int32_t nodeValue(uint32_t nodeId);
    void displayTree(std::string branchBody, std::string branchEnd, uint32_t nodeIndex);
    void extendCapacityIfNeeded();
    void fixHeapUp(uint32_t nodeId);
    void fixHeapDown(uint32_t nodeId);
    bool leftSiblingExists(uint32_t nodeId);
    bool rightSiblingExists(uint32_t nodeId);

    uint32_t capacity;
    int32_t* tab;
    const int32_t invalidIndex;
};
