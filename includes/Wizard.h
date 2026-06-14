//
// Created by Fabian on 6/14/26.
//

#ifndef OOP_PR4_SPELL_WIZARD_H
#define OOP_PR4_SPELL_WIZARD_H
#include <string>

#include "Spell.h"

class Spell;

class Wizard {
public:
    //Constructor and Deconstructor
    Wizard(const std::string &name);
    ~Wizard();

    //Functions
    void print() const;
    void castSpell(Wizard *target);
    bool spellsLeft() const;
    void changeMana(int power);
    void looseSpell();
    void addSpell();

    //Getters
    std::string getName();
    int getMana() const;
private:
    Spell *spells[7];
    std::string name;
    int mana, spellCounter;
};

#endif //OOP_PR4_SPELL_WIZARD_H
