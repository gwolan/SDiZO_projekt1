#include <Containers/Container.hpp>


Container::Container()
    : size(0)
    , npos(-1)
{ }

bool Container::isEmpty()
{
    return size == 0;
}

uint32_t Container::getSize()
{
    return size;
}
