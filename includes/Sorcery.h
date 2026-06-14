//
// Created by Fabian on 6/14/26.
//

#ifndef OOP_PR4_SPELL_SORCERY_H
#define OOP_PR4_SPELL_SORCERY_H
#include "Spell.h"

class Sorcery : public Spell {
public:

    static const int DEBUFF = 1;
    static const int BUFF = 2;

    //Constructor and Deconstructor
    Sorcery(int type);
    ~Sorcery() override = default;

    //Functions
    void cast(Wizard *target) override;

private:
};

#endif //OOP_PR4_SPELL_SORCERY_H
