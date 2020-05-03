#pragma once

#include <memory>
#include <fstream>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Containers/Table/Table.hpp>
#include <Miscellanous/Timer.hpp>


class TableOperations : public BaseAction
{
    public:
    TableOperations(const std::string& actionName);
    ~TableOperations() = default;

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
    Table table;
};
