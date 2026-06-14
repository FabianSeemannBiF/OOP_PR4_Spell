//
// Created by Fabian on 6/14/26.
//
#include "../includes/Instant.h"

#include <cstdlib>

Instant::Instant(int type) : Spell(type) {
    this->power = (rand() % 5) + 1;
}

void Instant::cast(Wizard *target) {
    if (this->type == DAMAGE) {
        target->changeMana(-this->power);
    } else if (this->type == HEAL) {
        target->changeMana(this->power);
    }
}
