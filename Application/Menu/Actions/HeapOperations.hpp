#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Containers/Heap/Heap.hpp>
#include <Miscellanous/Timer.hpp>


// This Action lets user play around with Heap container implementation
// Each methods name describe what can be done with the Heap


class HeapOperations : public BaseAction
{
    public:
    HeapOperations(const std::string& actionName);
    ~HeapOperations() = default;

    void run();


    private:
    void handleMenuSelection(std::string choice);
    void drawSubMenu();
    void readContainerFromFile();
    void generateRandomContainer();
    void addElementToContainer();
    void removeElementFromContainer();
    void searchElementInContainer();
    void displayContainer();

    std::string subMenuContent;
    std::string fileName;
    std::string dataFileContent;
    std::ifstream dataFile;
    Timer timer;
    Heap heap;
};
