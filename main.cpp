#include <iostream>
#include <time.h>
#include "Wizard.h"

int main()
{
    srand (time(nullptr)); //Initializing random seed

    Wizard wizOne = Wizard("Xardas"); //Creating the wizards
    Wizard wizTwo = Wizard("Pyrokar");

    while(wizOne.spellsLeft() || wizTwo.spellsLeft())
    {//Casting spells until no spells are left
        if(wizOne.spellsLeft())
            try {
                wizOne.castSpell(&wizTwo);
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            } catch (...) {
                std::cerr << "Unknown error" << std::endl;
            }
        if(wizTwo.spellsLeft())
            try {
                wizTwo.castSpell(&wizOne);
            } catch (std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
            } catch (...) {
                std::cerr << "Unknown error" << std::endl;
            }
    }

    wizOne.print(); //Print final state
    wizTwo.print();

    return 0;
}
