#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Containers/Table/Table.hpp>
#include <Containers/List/List.hpp>
#include <Containers/Heap/Heap.hpp>
#include <Miscellanous/Timer.hpp>


// This Action is an automated implementation to gather data of each container performance
// Collected data is stored in file


class Measurements : public BaseAction
{
    public:
    Measurements(const std::string& actionName);
    ~Measurements() = default;

    void run();


    private:
    void generateRandomTable(uint32_t size);
    void generateRandomList(uint32_t size);
    void generateRandomHeap(uint32_t size);
    void performMeasurementsForTable();
    void measureAddForTable(uint32_t instanceSize);
    void measureRemoveForTable(uint32_t instanceSize);
    void measureSearchForTable(uint32_t instanceSize);
    void performMeasurementsForList();
    void measureAddForList(uint32_t instanceSize);
    void measureRemoveForList(uint32_t instanceSize);
    void measureSearchForList(uint32_t instanceSize);
    void performMeasurementsForHeap();
    void measureAddForHeap(uint32_t instanceSize);
    void measureRemoveForHeap(uint32_t instanceSize);
    void measureSearchForHeap(uint32_t instanceSize);
    void printResultsToFile();
    void printTableAddResults();
    void printTableRemoveResults();
    void printTableSearchResults();
    void printListAddResults();
    void printListRemoveResults();
    void printListSearchResults();
    void printHeapAddResults();
    void printHeapRemoveResults();
    void printHeapSearchResults();

    std::string resultsFileName;
    std::ofstream resultsFile;
    std::vector<uint32_t> instancesSizes;
    uint32_t generationsCount;
    uint32_t exerciseIterations;

    std::map<uint32_t, double> tableAddFrontResults;
    std::map<uint32_t, double> tableAddRandomResults;
    std::map<uint32_t, double> tableAddBackResults;
    std::map<uint32_t, double> tableRemoveFrontResults;
    std::map<uint32_t, double> tableRemoveRandomResults;
    std::map<uint32_t, double> tableRemoveBackResults;
    std::map<uint32_t, double> tableSearchResults;

    std::map<uint32_t, double> listAddFrontResults;
    std::map<uint32_t, double> listAddRandomResults;
    std::map<uint32_t, double> listAddBackResults;
    std::map<uint32_t, double> listRemoveFrontResults;
    std::map<uint32_t, double> listRemoveRandomResults;
    std::map<uint32_t, double> listRemoveBackResults;
    std::map<uint32_t, double> listSearchResults;

    std::map<uint32_t, double> heapAddResults;
    std::map<uint32_t, double> heapRemoveResults;
    std::map<uint32_t, double> heapSearchResults;

    Timer timer;
    Table table;
    List list;
    Heap heap;
};
