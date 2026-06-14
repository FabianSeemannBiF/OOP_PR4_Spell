//
// Created by Fabian on 6/14/26.
//
#include "Sorcery.h"

#include "Instant.h"

Sorcery::Sorcery(int type) : Spell(type) {}

void Sorcery::cast(Wizard *target) {
    if (this->type == DEBUFF) {
        target->looseSpell();
    } else if (this->type == BUFF) {
        target->addSpell();
    }
}