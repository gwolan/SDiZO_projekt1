#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Containers/List/List.hpp>
#include <Miscellanous/Timer.hpp>


// This Action lets user play around with List container implementation
// Each methods name describe what can be done with the List


class ListOperations : public BaseAction
{
    public:
    ListOperations(const std::string& actionName);
    ~ListOperations() = default;

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
    List list;
};
