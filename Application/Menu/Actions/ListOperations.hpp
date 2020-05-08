#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Containers/List/List.hpp>
#include <Miscellanous/Timer.hpp>


class ListOperations : public BaseAction
{
    public:
    ListOperations(const std::string& actionName);
    ~ListOperations() = default;

    void run();


    private:
    bool handleMenuSelection(std::string choice);
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
