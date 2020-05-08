#include <iostream>
#include <Application/Menu/Actions/Measurements.hpp>
#include <Miscellanous/Dice.hpp>


Measurements::Measurements(const std::string& actionName)
    : BaseAction(actionName)
    , resultsFileName("results.txt")
    , resultsFile()
    , instancesSizes({ 1000, 2000, 5000, 8000, 12000, 16000, 20000 })
    , generationsCount(100)
    , exerciseIterations(50)
    , tableAddFrontResults()
    , tableAddRandomResults()
    , tableAddBackResults()
    , tableRemoveFrontResults()
    , tableRemoveRandomResults()
    , tableRemoveBackResults()
    , tableSearchResults()
    , listAddFrontResults()
    , listAddRandomResults()
    , listAddBackResults()
    , listRemoveFrontResults()
    , listRemoveRandomResults()
    , listRemoveBackResults()
    , listSearchResults()
    , heapAddResults()
    , heapRemoveResults()
    , heapSearchResults()
    , timer()
    , table()
    , list()
    , heap()
{ }

void Measurements::run()
{
    performMeasurementsForTable();
    performMeasurementsForList();
    performMeasurementsForHeap();
    printResultsToFile();
}

void Measurements::printResultsToFile()
{
    resultsFile.open(resultsFileName, std::ofstream::app);

    if(resultsFile.is_open())
    {
        resultsFile << "TABLICA" << std::endl;
        resultsFile << "Size" << "\t" << "Time" << "\t" << "Type" << "\t" << std::endl;
        printTableAddResults();
        printTableRemoveResults();
        printTableSearchResults();
        resultsFile << std::endl;

        resultsFile << "LISTA" << std::endl;
        resultsFile << "Size" << "\t" << "Time" << "\t" << "Type" << "\t" << std::endl;
        printListAddResults();
        printListRemoveResults();
        printListSearchResults();
        resultsFile << std::endl;

        resultsFile << "KOPIEC" << std::endl;
        resultsFile << "Size" << "\t" << "Time" << "\t" << "Type" << "\t" << std::endl;
        printHeapAddResults();
        printHeapRemoveResults();
        printHeapSearchResults();
        resultsFile << std::endl;


        resultsFile.close();
        std::cout << "Wyniki pomyślnie zapisano do pliku." << std::endl << std::endl;
    }
}

void Measurements::printTableAddResults()
{
    for(auto result : tableAddFrontResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addB" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : tableAddRandomResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addR" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : tableAddBackResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addE" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printTableRemoveResults()
{
    for(auto result : tableRemoveFrontResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remB" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : tableRemoveRandomResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remR" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : tableRemoveBackResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remE" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printTableSearchResults()
{
    for(auto result : tableSearchResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "srch" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printListAddResults()
{
    for(auto result : listAddFrontResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addB" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : listAddRandomResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addR" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : listAddBackResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "addE" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printListRemoveResults()
{
    for(auto result : listRemoveFrontResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remB" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : listRemoveRandomResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remR" << std::endl;
    }
    resultsFile << std::endl;

    for(auto result : listRemoveBackResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remE" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printListSearchResults()
{
    for(auto result : listSearchResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "srch" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printHeapAddResults()
{
    for(auto result : heapAddResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "add" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printHeapRemoveResults()
{
    for(auto result : heapRemoveResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "remv" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::printHeapSearchResults()
{
    for(auto result : heapSearchResults)
    {
        resultsFile << result.first << "\t" << result.second << "\t" << "srch" << std::endl;
    }
    resultsFile << std::endl;
}

void Measurements::generateRandomTable(uint32_t size)
{
    table.clear();
    Dice dice(-5000, 5000);

    for(uint32_t it = 0; it < size; ++it)
    {
        table.add(dice.rollSignedInt(), table.getSize());
    }
}

void Measurements::generateRandomList(uint32_t size)
{
    list.clear();
    Dice dice(-5000, 5000);

    for(uint32_t it = 0; it < size; ++it)
    {
        list.add(dice.rollSignedInt(), list.getSize());
    }
}

void Measurements::generateRandomHeap(uint32_t size)
{
    heap.clear();
    Dice dice(-5000, 5000);

    heap.allocateCapacity(size + (2 * exerciseIterations));
    for(uint32_t it = 0; it < size; ++it)
    {
        heap.add(dice.rollSignedInt());
    }
}

void Measurements::performMeasurementsForTable()
{
    std::cout << std::endl << "TABLICA" << std::endl;

    for(auto& instanceSize : instancesSizes)
    {
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - dodawanie" << std::endl;
        measureAddForTable(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - usuwanie" << std::endl;
        measureRemoveForTable(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - szukanie" << std::endl;
        measureSearchForTable(instanceSize);
    }
}

void Measurements::measureAddForTable(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);

    double addFrontTime = 0.0;
    double addRandomTime = 0.0;
    double addBackTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Table::add: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomTable(instanceSize);
        uint32_t partialExerciseIterations = (exerciseIterations / 3);
        double exerciseFrontTime = 0.0;
        double exerciseRandomTime = 0.0;
        double exerciseBackTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            table.add(valueDice.rollSignedInt(), 0);
            timer.stop();

            exerciseFrontTime += timer.getTime();
        }
        addFrontTime += exerciseFrontTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            Dice indexDice(0, table.getSize() - 1);

            timer.start();
            table.add(valueDice.rollSignedInt(), indexDice.rollUnsignedInt());
            timer.stop();

            exerciseRandomTime += timer.getTime();
        }
        addRandomTime += exerciseRandomTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            table.add(valueDice.rollSignedInt(), table.getSize() - 1);
            timer.stop();

            exerciseBackTime += timer.getTime();
        }
        addBackTime += exerciseBackTime / partialExerciseIterations;
    }

    tableAddFrontResults[instanceSize] = addFrontTime / generationsCount;
    tableAddRandomResults[instanceSize] = addRandomTime / generationsCount;
    tableAddBackResults[instanceSize] =  addBackTime / generationsCount;

    std::cout << std::endl;
}

void Measurements::measureRemoveForTable(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);

    double removeFrontTime = 0.0;
    double removeRandomTime = 0.0;
    double removeBackTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Table::remove: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomTable(instanceSize);
        uint32_t partialExerciseIterations = (exerciseIterations / 3);
        double exerciseFrontTime = 0.0;
        double exerciseRandomTime = 0.0;
        double exerciseBackTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            table.remove(0);
            timer.stop();

            exerciseFrontTime += timer.getTime();
        }
        removeFrontTime += exerciseFrontTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            Dice indexDice(0, table.getSize() - 1);

            timer.start();
            table.remove(indexDice.rollUnsignedInt());
            timer.stop();

            exerciseRandomTime += timer.getTime();
        }
        removeRandomTime += exerciseRandomTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            table.remove(table.getSize() - 1);
            timer.stop();

            exerciseBackTime += timer.getTime();
        }
        removeBackTime += exerciseBackTime / partialExerciseIterations;
    }

    tableRemoveFrontResults[instanceSize] = removeFrontTime / generationsCount;
    tableRemoveRandomResults[instanceSize] = removeRandomTime / generationsCount;
    tableRemoveBackResults[instanceSize] =  removeBackTime / generationsCount;

    std::cout << std::endl;
}

void Measurements::measureSearchForTable(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);
    double searchTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Table::search: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomTable(instanceSize);
        double exerciseSearchTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < exerciseIterations; ++exerciseIt)
        {
            timer.start();
            table.search(valueDice.rollSignedInt());
            timer.stop();

            exerciseSearchTime += timer.getTime();
        }
        searchTime += exerciseSearchTime / exerciseIterations;
    }

    tableSearchResults[instanceSize] = searchTime / generationsCount;
    std::cout << std::endl;
}

void Measurements::performMeasurementsForList()
{
    std::cout << std::endl << "LISTA" << std::endl;

    for(auto& instanceSize : instancesSizes)
    {
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - dodawanie" << std::endl;
        measureAddForList(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - usuwanie" << std::endl;
        measureRemoveForList(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - szukanie" << std::endl;
        measureSearchForList(instanceSize);
    }
}

void Measurements::measureAddForList(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);

    double addFrontTime = 0.0;
    double addRandomTime = 0.0;
    double addBackTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "List::add: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomTable(instanceSize);
        uint32_t partialExerciseIterations = (exerciseIterations / 3);
        double exerciseFrontTime = 0.0;
        double exerciseRandomTime = 0.0;
        double exerciseBackTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            list.add(valueDice.rollSignedInt(), 0);
            timer.stop();

            exerciseFrontTime += timer.getTime();
        }
        addFrontTime += exerciseFrontTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            Dice indexDice(0, list.getSize() - 1);

            timer.start();
            list.add(valueDice.rollSignedInt(), indexDice.rollUnsignedInt());
            timer.stop();

            exerciseRandomTime += timer.getTime();
        }
        addRandomTime += exerciseRandomTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            list.add(valueDice.rollSignedInt(), list.getSize() - 1);
            timer.stop();

            exerciseBackTime += timer.getTime();
        }
        addBackTime += exerciseBackTime / partialExerciseIterations;
    }

    listAddFrontResults[instanceSize] = addFrontTime / generationsCount;
    listAddRandomResults[instanceSize] = addRandomTime / generationsCount;
    listAddBackResults[instanceSize] =  addBackTime / generationsCount;

    std::cout << std::endl;
}

void Measurements::measureRemoveForList(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);

    double removeFrontTime = 0.0;
    double removeRandomTime = 0.0;
    double removeBackTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "List::remove: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomTable(instanceSize);
        uint32_t partialExerciseIterations = (exerciseIterations / 3);
        double exerciseFrontTime = 0.0;
        double exerciseRandomTime = 0.0;
        double exerciseBackTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            list.remove(0);
            timer.stop();

            exerciseFrontTime += timer.getTime();
        }
        removeFrontTime += exerciseFrontTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            Dice indexDice(0, list.getSize() - 1);
            int32_t removedValue = list.get(indexDice.rollUnsignedInt());

            timer.start();
            list.remove(removedValue);
            timer.stop();

            exerciseRandomTime += timer.getTime();
        }
        removeRandomTime += exerciseRandomTime / partialExerciseIterations;

        for(uint32_t exerciseIt = 0; exerciseIt < partialExerciseIterations; ++exerciseIt)
        {
            timer.start();
            list.remove(list.getSize() - 1);
            timer.stop();

            exerciseBackTime += timer.getTime();
        }
        removeBackTime += exerciseBackTime / partialExerciseIterations;
    }

    listRemoveFrontResults[instanceSize] = removeFrontTime / generationsCount;
    listRemoveRandomResults[instanceSize] = removeRandomTime / generationsCount;
    listRemoveBackResults[instanceSize] =  removeBackTime / generationsCount;

    std::cout << std::endl;
}

void Measurements::measureSearchForList(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);
    double searchTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "List::search: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomList(instanceSize);
        double exerciseSearchTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < exerciseIterations; ++exerciseIt)
        {
            timer.start();
            list.search(valueDice.rollSignedInt());
            timer.stop();

            exerciseSearchTime += timer.getTime();
        }
        searchTime += exerciseSearchTime / exerciseIterations;
    }

    listSearchResults[instanceSize] = searchTime / generationsCount;
    std::cout << std::endl;
}

void Measurements::performMeasurementsForHeap()
{
    std::cout << std::endl << "KOPIEC" << std::endl;

    for(auto& instanceSize : instancesSizes)
    {
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - dodawanie" << std::endl;
        measureAddForHeap(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - usuwanie" << std::endl;
        measureRemoveForHeap(instanceSize);
        std::cout << "Rozpoczecie pomiarow dla instancji " << instanceSize << " elementowej - szukanie" << std::endl;
        measureSearchForHeap(instanceSize);
    }
}

void Measurements::measureAddForHeap(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);
    double addTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Heap::add: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomHeap(instanceSize);
        double exerciseTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < exerciseIterations; ++exerciseIt)
        {
            timer.start();
            heap.add(valueDice.rollSignedInt());
            timer.stop();

            exerciseTime += timer.getTime();
        }
        addTime += exerciseTime / exerciseIterations;
    }

    heapAddResults[instanceSize] = addTime / generationsCount;
    std::cout << std::endl;
}

void Measurements::measureRemoveForHeap(uint32_t instanceSize)
{
    double removeTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Heap::remove: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomHeap(instanceSize);
        double exerciseTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < exerciseIterations; ++exerciseIt)
        {
            Dice indexDice(0, heap.getSize() - 1);

            timer.start();
            heap.remove(indexDice.rollUnsignedInt());
            timer.stop();

            exerciseTime += timer.getTime();
        }
        removeTime += exerciseTime / exerciseIterations;
    }

    heapRemoveResults[instanceSize] = removeTime / generationsCount;
    std::cout << std::endl;
}

void Measurements::measureSearchForHeap(uint32_t instanceSize)
{
    Dice valueDice(-5000, 5000);
    double searchTime = 0.0;

    for(uint32_t generationIt = 0; generationIt < generationsCount; ++generationIt)
    {
        std::cout << "Heap::search: Losuje generacje dla instancji " << instanceSize << " (" << generationIt + 1 << " z " << generationsCount << ")..." << std::endl;

        generateRandomList(instanceSize);
        double exerciseSearchTime = 0.0;

        for(uint32_t exerciseIt = 0; exerciseIt < exerciseIterations; ++exerciseIt)
        {
            timer.start();
            heap.search(valueDice.rollSignedInt());
            timer.stop();

            exerciseSearchTime += timer.getTime();
        }
        searchTime += exerciseSearchTime / exerciseIterations;
    }

    heapSearchResults[instanceSize] = searchTime / generationsCount;
    std::cout << std::endl;
}
