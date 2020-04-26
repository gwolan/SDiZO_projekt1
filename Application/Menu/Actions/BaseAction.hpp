#pragma once

#include <string>
#include <memory>


class BaseAction
{
    public:
    BaseAction(const std::string& actionName);
    ~BaseAction() = default;

    virtual void run() = 0;
    std::string getActionName();


    protected:
    std::string name;
};
