#include <Application/ApplicationFacade.hpp>


int main()
{
    std::string menuContent(std::string("\n====================\n") +
                            std::string("SDiZO Projekt nr 1: Tablica, Lista oraz Kopiec\n") +
                            std::string("Autor: Grzegorz Wolanski\n\n") +
                            std::string("Menu:\n") +
                            std::string("0. Wyjscie.\n\n") +
                            std::string("Wybor: "));


    ApplicationFacade application(menuContent);

    while(application.getCurrentMenuSelection() != "0")
    {
        application.printMenu();
        application.readMenuSelection();
        application.run();
    }

    return 0;
}
