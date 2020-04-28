#include <Application/ApplicationFacade.hpp>


ApplicationFacade::ApplicationFacade(const std::string& menuContent)
    : ioHandler(menuContent)
    , actionStrategy()
{ }

void ApplicationFacade::printMenu()
{
    ioHandler.printMenu();
}

bool ApplicationFacade::readMenuSelection()
{
    return ioHandler.readMenuSelection();
}

std::string ApplicationFacade::getCurrentMenuSelection()
{
    return ioHandler.getCurrentMenuSelection();
}

void ApplicationFacade::run()
{
    if(actionStrategy.selectAction(ioHandler.getCurrentMenuSelection()))
    {
        actionStrategy.executeAction();
    }
}