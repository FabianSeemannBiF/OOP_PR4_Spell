#ifndef SPELL_H
#define SPELL_H

#include "Wizard.h"

class Wizard;

class Spell {
public:
    //Constructor and Deconstructor
    Spell(int type);
    virtual ~Spell();

    //Functions
    virtual void cast(Wizard *target) = 0;

    //Getters
    int getType();

protected:
    int type; //Instants are either damaging or healing
    //Sorceries are either debuffing or buffing

private:
};

#endif // SPELL_H
