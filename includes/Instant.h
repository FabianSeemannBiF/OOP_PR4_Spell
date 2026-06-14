//
// Created by Fabian on 6/14/26.
//

#ifndef OOP_PR4_SPELL_INSTANT_H
#define OOP_PR4_SPELL_INSTANT_H
#include "Spell.h"

class Instant : public Spell {
public:

    static const int DAMAGE = 1;
    static const int HEAL = 2;

    //Constructor and Deconstructor
    Instant(int type);
    ~Instant() override = default;

    //Functions
    void cast(Wizard *target) override;

protected:

private:
    int power;
};

#endif //OOP_PR4_SPELL_INSTANT_H
