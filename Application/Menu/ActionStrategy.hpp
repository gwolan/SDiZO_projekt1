#pragma once

#include <memory>
#include <Application/Menu/Actions/BaseAction.hpp>


class ActionStrategy
{
    public:
    ActionStrategy();

    void executeAction();
    bool selectAction(std::string choice);


    public:
    std::unique_ptr<BaseAction> selectedAction;
};
