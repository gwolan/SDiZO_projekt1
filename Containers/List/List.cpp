#include <iostream>
#include <Containers/List/List.hpp>


List::List()
    : Container()
    , head(NULL)
    , tail(NULL)
    , invalidIndex(-1)
{ }

List::~List()
{
    clear();
}

void List::clear()
{
    if(head && tail)
    {
        for(uint32_t it = 0; it < size; ++it)
        {
            if(head != tail)
            {
                head = head->next;

                delete head->prev;
                head->prev = NULL;
            }
            else
            {
                delete head;
            }
        }

        head = NULL;
        tail = NULL;
        size = 0;
    }
}

void List::add(int32_t value, uint32_t index)
{
    alignOutOfRangeIndexToSize(index);

    if(head && tail)
    {
        ListNode* tmp = head;

        for(uint32_t it = 0; it < index; ++it)
        {
            tmp = tmp->next;
        }

        ListNode* newNode = new ListNode();
        newNode->value = value;
        newNode->prev = tmp->prev;
        newNode->next = tmp;

        tmp->prev->next = newNode;
        tmp->prev = newNode;

        if(index == size)
        {
            tail = tail->next;
        }
        else if(tmp == head)
        {
            head = head->prev;
        }
    }
    else
    {
        ListNode* newNode = new ListNode();
        newNode->value = value;
        newNode->prev = newNode;
        newNode->next = newNode;

        head = newNode;
        tail = newNode;
    }

    size++;
}

bool List::remove(int32_t value)
{
    if(head && tail)
    {
        ListNode* tmp = head;

        for(uint32_t it = 0; it < size; ++it)
        {
            if(tmp->value == value)
            {
                removeNode(tmp);

                size--;
                if(isEmpty())
                {
                    head = NULL;
                    tail = NULL;
                }

                return true;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }

    return false;
}

void List::removeNode(ListNode* removedNode)
{
    removedNode->prev->next = removedNode->next;
    removedNode->next->prev = removedNode->prev;

    if(removedNode == tail)
    {
        tail = tail->prev;
    }
    else if(removedNode == head)
    {
        head = head->next;
    }

    delete removedNode;
}

bool List::search(int32_t value)
{
    if(head && tail)
    {
        ListNode* tmp = head;

        for(uint32_t it = 0; it < size; ++it)
        {
            if(tmp->value == value)
            {
                return true;
            }

            tmp = tmp->next;
        }
    }

    return false;
}

int32_t List::get(uint32_t index)
{
    if(head && tail)
    {
        alignOutOfRangeIndexToSize(index);
        if(index == size)
        {
            index--;
        }

        ListNode* tmp = head;
        for(uint32_t it = 0; it < index; ++it)
        {
            tmp = tmp->next;
        }

        return tmp->value;
    }

    return invalidIndex;
}

void List::display()
{
    if(isEmpty())
    {
        std::cout << "Lista jest pusta." << std::endl;
    }
    else
    {
        std::cout << "Rozmiar listy: " << size << std::endl;

        ListNode* tmp = head;
        std::cout << std::endl << "Lista w przod: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;

        tmp = tail;
        std::cout << std::endl << "Lista w tyl: " << std::endl;
        for(uint32_t it = 0; it < size; ++it)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        std::cout << std::endl << std::endl;
    }
}
