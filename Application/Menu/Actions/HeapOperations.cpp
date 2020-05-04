#include <iostream>
#include <Application/Menu/Actions/HeapOperations.hpp>
#include <Application/Menu/IOhandler.hpp>
#include <Miscellanous/Dice.hpp>


HeapOperations::HeapOperations(const std::string& actionName)
    : BaseAction(actionName)
    , subMenuContent()
    , fileName()
    , dataFileContent()
    , dataFile()
    , timer()
    , heap()
{ }

void HeapOperations::run()
{
    IOhandler ioHandler(subMenuContent);

    while(ioHandler.getCurrentMenuSelection() != "0")
    {
        drawSubMenu();
        ioHandler.setMenuContent(subMenuContent);
        ioHandler.printMenu();
        ioHandler.readMenuSelection();

        handleMenuSelection(ioHandler.getCurrentMenuSelection());
    }
}

bool HeapOperations::handleMenuSelection(std::string choice)
{
    std::cout << std::endl;

    uint32_t selection = std::atoi(choice.c_str());

    switch(selection)
    {
        case 1:
        {
            readContainerFromFile();
        }
        break;

        case 2:
        {
            generateRandomContainer();
        }
        break;

        case 3:
        {
            addElementToContainer();
        }
        break;

        case 4:
        {
            removeElementFromContainer();
        }
        break;

        case 5:
        {
            searchElementInContainer();
        }
        break;

        case 6:
        {
            displayContainer();
        }
        break;

        case 0: break;

        default:
        {
            std::cout << "Wskazana opcja jest nieprawidłowa." << std::endl;
        }
    }

    std::cout << std::endl;
}

void HeapOperations::drawSubMenu()
{
    std::string title(           "Operacje na strukturze:\n");
    std::string optionOne(       "1. Wczytaj z pliku.\n");
    std::string optionTwo(       "2. Wygeneruj losowo.\n");
    std::string optionThree(     "3. Dodaj element.\n");
    std::string optionFour(      "4. Usun element.\n");
    std::string optionFive(      "5. Wyszukaj element.\n");
    std::string optionSix(       "6. Wyswietl.\n");
    std::string returnToMainMenu("0. Powrot do menu glownego.\n");
    std::string selection(       "Wybor: ");

    subMenuContent = std::string(title +
                                 optionOne +
                                 optionTwo +
                                 optionThree +
                                 optionFour +
                                 optionFive +
                                 optionSix +
                                 returnToMainMenu +
                                 selection);
}

void HeapOperations::readContainerFromFile()
{
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;

    dataFile.open(fileName);

    if(dataFile.is_open())
    {
        heap.clear();
        dataFile >> dataFileContent;
        uint32_t containerSize = std::atoi(dataFileContent.c_str());

        for(uint32_t it = 0; it < containerSize; ++it)
        {
            dataFile >> dataFileContent;
            heap.add(std::atoi(dataFileContent.c_str()));
        }
        dataFile.close();

        std::cout << "Struktura pomyslnie wczytana z pliku. Liczba elementow: " << heap.getSize() << std::endl << std::endl;
        heap.display();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Plik \"" << fileName << "\" nie istnieje!" << std::endl;
        std::cout << std::endl;
    }
}

void HeapOperations::generateRandomContainer()
{
    uint32_t requestedContainerSize;
    int32_t valuesLowerBound;
    int32_t valuesUpperBound;

    std::cout << "Podaj wielkosc: ";
    std::cin >> requestedContainerSize;
    std::cout << "Podaj dolny zakres wartosci: ";
    std::cin >> valuesLowerBound;
    std::cout << "Podaj gorny zakres wartosci: ";
    std::cin >> valuesUpperBound;


    heap.clear();
    Dice dice(valuesLowerBound, valuesUpperBound);
    for(uint32_t it = 0; it < requestedContainerSize; ++it)
    {
        heap.add(dice.rollSignedInt());
    }

    std::cout << std::endl;
    heap.display();
}

void HeapOperations::addElementToContainer()
{
    int32_t newValue;

    std::cout << "Podaj wartosc: ";
    std::cin >> newValue;

    timer.start();
    heap.add(newValue);
    timer.stop();

    std::cout << std::endl << "Operacja wykonana w czasie: " << timer.getTime() << " [s]" << std::endl;
    heap.display();
}

void HeapOperations::removeElementFromContainer()
{
    int32_t removedValue;
    int32_t index;

    std::cout << "Podaj wartosc: ";
    std::cin >> removedValue;

    index = heap.getIndex(removedValue);
    timer.start();
    if(heap.remove(index))
    {
        timer.stop();
        std::cout << std::endl << "Operacja wykonana w czasie: " << timer.getTime() << " [s]" << std::endl;
        heap.display();
    }
    else
    {
        std::cout << "Wskazana wartosc nie istnieje w strukturze." << std::endl;
    }
}

void HeapOperations::searchElementInContainer()
{
    int32_t searchedValue;

    std::cout << "Podaj wartosc: ";
    std::cin >> searchedValue;

    timer.start();
    bool result = heap.search(searchedValue);
    timer.stop();

    if(result)
    {
        std::cout << std::endl << "Podany element zostal znaleziony." << std::endl;
    }
    else
    {
        std::cout << std::endl << "Podany element nie istnieje w strukturze." << std::endl;
    }

    std::cout << "Operacja wykonana w czasie: " << timer.getTime() << " [s]" << std::endl << std::endl;
    heap.display();
}

void HeapOperations::displayContainer()
{
    heap.display();
}
