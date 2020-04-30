#pragma once

#include <Containers/Container.hpp>


class Table : public Container
{
    public:
    Table();
    ~Table();

    void clear();
    void display();
    void add(int32_t value, uint32_t index);
    bool remove(uint32_t index);
    bool search(int32_t value);


    private:
    void reassignTable(int32_t* newTab);

    int32_t* tab;
};
