#include <iostream>
#include <string>
#include <Containers/Heap/Heap.hpp>


Heap::Heap()
    : Container()
    , tab(NULL)
    , invalidIndex(-1)
{ }

Heap::~Heap()
{
    clear();
}

void Heap::clear()
{
    if(tab)
    {
        delete tab;
        tab = NULL;
    }

    size = 0;
    capacity = 0;
}

bool Heap::allocateCapacity(uint32_t newCapacity)
{
    if(newCapacity <= capacity)
    {
        return false;
    }

    if(tab)
    {
        int32_t* newTab = new int32_t[newCapacity];

        for(uint32_t it = 0; it < size; ++it)
        {
            newTab[it] = tab[it];
        }

        delete tab;
        tab = newTab;
    }
    else
    {
        tab = new int32_t[newCapacity];
    }

    capacity = newCapacity;
    return true;
}

void Heap::extendCapacityIfNeeded()
{
    if(isEmpty())
    {
        allocateCapacity(2);
    }
    else if(size + 1 > capacity)
    {
        allocateCapacity(2 * capacity);
    }
}

uint32_t Heap::parentNodeId(uint32_t currentNode)
{
    return (currentNode - 1) / 2;
}

uint32_t Heap::leftSiblingNodeId(uint32_t currentNode)
{
    return currentNode * 2 + 1;
}

uint32_t Heap::rightSiblingNodeId(uint32_t currentNode)
{
    return currentNode * 2 + 2;
}

int32_t Heap::nodeValue(uint32_t nodeId)
{
    return tab[nodeId];
}

bool Heap::leftSiblingExists(uint32_t nodeId)
{
    return leftSiblingNodeId(nodeId) < size;
}

bool Heap::rightSiblingExists(uint32_t nodeId)
{
    return rightSiblingNodeId(nodeId) < size;
}

void Heap::fixHeapUp(uint32_t nodeId)
{
    uint32_t parentNode = parentNodeId(nodeId);
    int32_t valuePlaceHolder;

    while(nodeId > 0 && nodeValue(parentNode) < nodeValue(nodeId))
    {
        valuePlaceHolder = nodeValue(nodeId);
        tab[nodeId] = nodeValue(parentNode);
        tab[parentNode] = valuePlaceHolder;

        nodeId = parentNode;
        parentNode = parentNodeId(nodeId);
    }
}

void Heap::fixHeapDown(uint32_t nodeId)
{
    while(leftSiblingExists(nodeId))
    {
        if(rightSiblingExists(nodeId))
        {
            int32_t leftSiblingValue = nodeValue(leftSiblingNodeId(nodeId));
            int32_t rightSiblingValue = nodeValue(rightSiblingNodeId(nodeId));

            if(leftSiblingValue > rightSiblingValue)
            {
                tab[nodeId] = leftSiblingValue;
                nodeId = leftSiblingNodeId(nodeId);
            }
            else
            {
                tab[nodeId] = rightSiblingValue;
                nodeId = rightSiblingNodeId(nodeId);
            }
        }
        else
        {
            int32_t leftSiblingValue = nodeValue(leftSiblingNodeId(nodeId));

            tab[nodeId] = leftSiblingValue;
            nodeId = leftSiblingNodeId(nodeId);
        }
    }
}

void Heap::add(int32_t value)
{
    extendCapacityIfNeeded();

    uint32_t newNodeId = size++;
    tab[newNodeId] = value;

    fixHeapUp(newNodeId);
}

bool Heap::remove(uint32_t index)
{
    if(index >= size)
    {
        return false;
    }

    int32_t lastValueInHeap = nodeValue(size - 1);
    tab[index] = lastValueInHeap;

    fixHeapDown(index);
    size--;

    if(isEmpty())
    {
        clear();
    }

    return true;
}

bool Heap::search(int32_t value)
{
    for(uint32_t it = 0; it < size; ++it)
    {
        if(tab[it] == value)
        {
            return true;
        }
    }

    return false;
}

uint32_t Heap::getIndex(int32_t value)
{
    for(uint32_t it = 0; it < size; ++it)
    {
        if(tab[it] == value)
        {
            return it;
        }
    }

    return invalidIndex;
}

void Heap::display()
{
    if(isEmpty())
    {
        std::cout << "Kopiec jest pusty." << std::endl;
    }
    else
    {
        std::cout << "Rozmiar kopca: " << size << "/" << capacity << std::endl << std::endl;

        std::cout << "Forma tablicowa: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tab[it] << " ";
        }

        std::cout << std::endl;
        std::cout << std::endl << "Forma drzewiasta: " << std::endl;
        displayTree("", "", 0);
    }
}

void Heap::displayTree(std::string branchBody, std::string branchEnd, uint32_t nodeIndex)
{
    // I have used available solution from internet: https://eduinf.waw.pl/inf/alg/001_search/0113.php

    std::string branch;
    std::string childRightBranchSymbol,
                childLeftBranchSymbol,
                childParentBranchExtensionSymbol;

    childRightBranchSymbol = childLeftBranchSymbol = childParentBranchExtensionSymbol = "   ";
    childRightBranchSymbol              = "r--";
    childLeftBranchSymbol               = "L--";
    childParentBranchExtensionSymbol[0] = '|';

    if(nodeIndex < size)
    {
        branch = branchBody;
        if(branchEnd == childRightBranchSymbol)
        {
            branch[branch.length() - 3] = ' ';
        }
        displayTree(branch + childParentBranchExtensionSymbol, childRightBranchSymbol, rightSiblingNodeId(nodeIndex));

        branch = branch.substr(0, branchBody.length() - 3);
        std::cout << branch << branchEnd << "(" << tab[nodeIndex] << ")" << std::endl;

        branch = branchBody;
        if(branchEnd == childLeftBranchSymbol)
        {
            branch[branch.length() - 3] = ' ';
        }
        displayTree(branch + childParentBranchExtensionSymbol, childLeftBranchSymbol, leftSiblingNodeId(nodeIndex));
    }
}
