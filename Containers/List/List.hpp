#pragma once
#include <Containers/Container.hpp>
#include <Containers/List/Utils/ListNode.hpp>


class List : public Container
{
    public:
    List();
    ~List();

    void clear();
    void display();
    void add(int32_t value, uint32_t index);
    bool remove(int32_t value);
    bool search(int32_t value);


    private:
    void removeNode(ListNode* removedNode);

    ListNode* head;
    ListNode* tail;
};
