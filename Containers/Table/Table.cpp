#include <iostream>
#include <Containers/Table/Table.hpp>


Table::Table()
    : Container()
    , tab(NULL)
{ }

Table::~Table()
{
    clear();
}

void Table::alignOutOfRangeIndexToTableSize(uint32_t& index)
{
    if(index > size)
    {
        index = size;
    }
}

void Table::reassignTable(int32_t* newTab)
{
    if(tab)
    {
        delete tab;
    }

    tab = newTab;
}

void Table::clear()
{
    reassignTable(NULL);
    size = 0;
}

void Table::add(int32_t value, uint32_t index)
{
    alignOutOfRangeIndexToTableSize(index);

    size++;
    int32_t* newTab = new int32_t[size];

    for(uint32_t it = 0; it < index; ++it)
    {
        newTab[it] = tab[it];
    }

    newTab[index] = value;

    for(uint32_t it = index + 1; it < size; ++it)
    {
        newTab[it] = tab[it - 1];
    }

    reassignTable(newTab);
}

bool Table::remove(uint32_t index)
{
    if(index >= size)
    {
        return false;
    }


    size--;
    if(isEmpty())
    {
        reassignTable(NULL);
    }
    else
    {
        int32_t* newTab = new int32_t[size];

        for(uint32_t it = 0; it < index; ++it)
        {
            newTab[it] = tab[it];
        }

        for(uint32_t it = index + 1; it <= size; ++it)
        {
            newTab[it - 1] = tab[it];
        }

        reassignTable(newTab);
    }

    return true;
}

bool Table::search(int32_t value)
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

void Table::display()
{
    if(isEmpty())
    {
        std::cout << "Tablica jest pusta." << std::endl;
    }
    else
    {
        std::cout << "Rozmiar tablicy: " << size << std::endl;

        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tab[it] << " ";
        }

        std::cout << std::endl;
    }
}
