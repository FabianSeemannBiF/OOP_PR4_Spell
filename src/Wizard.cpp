//
// Created by Fabian on 6/14/26.
//
#include "Wizard.h"

#include <iostream>
#include <ostream>

#include "Instant.h"
#include "Sorcery.h"

Wizard::Wizard(const std::string &name) {
    this->name = name;
    this->mana = 20;
    this->spellCounter = 7;

    for (int j = 0; j < 7; j++) {
        this->spells[j] = nullptr;
    }

    for (int i = 0; i < 7; i++) {
        const int spell_type = rand() % 2;
        const int type = (rand() % 2) + 1;
        if (spell_type == 0) {
            this->spells[i] = new Instant(type);
        } else {
            this->spells[i] = new Sorcery(type);
        }
    }
}

Wizard::~Wizard() {
    for (int i = 0; i < 7; i++) {
        if (this->spells[i] != nullptr) {
            delete this->spells[i];
            this->spells[i] = nullptr;
        }
    }
}

void Wizard::print() const {
    std::cout << "Wizard name: " << name << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Spells left: " << this->spellCounter << std::endl;
}

void Wizard::castSpell(Wizard *target) {
    if (target == nullptr) {
        throw std::invalid_argument("target is null");
    }

    if (this->spellCounter == 0) return;

    Spell *currentSpell = this->spells[this->spellCounter - 1];

    if (currentSpell == nullptr) {
        spellCounter--;
        return;
    }

    // Pointer aus Array entfernen BEVOR cast() aufgerufen wird,
    // damit looseSpell() diesen nicht nochmal löschen kann
    this->spells[this->spellCounter - 1] = nullptr;
    spellCounter--;

    int type = currentSpell->getType();

    Instant *instant = dynamic_cast<Instant *>(currentSpell);
    Wizard* finalTarget = target;

    if (instant != nullptr) {
        if (type == Instant::HEAL) {
            finalTarget = this;
        }
    } else {
        if (type == Sorcery::BUFF) {
            finalTarget = this;
        }
    }

    currentSpell->cast(finalTarget);

    delete currentSpell;
}

bool Wizard::spellsLeft() const {
    if (spellCounter > 0) {
        return true;
    }
    return false;
}

void Wizard::changeMana(const int power) {
    this->mana += power;
}

void Wizard::looseSpell() {
    if (spellCounter > 0) {
        delete this->spells[spellCounter - 1];
        this->spells[spellCounter - 1] = nullptr;
        spellCounter--;
    }
}

void Wizard::addSpell() {
    if (this->spellCounter < 7) {
        const int spell_type = rand() % 2;
        const int type = (rand() % 2) + 1;
        if (spell_type == 0) {
            this->spells[this->spellCounter] = new Instant(type);
        } else {
            this->spells[this->spellCounter] = new Sorcery(type);
        }
        this->spellCounter++;
    }
}

std::string Wizard::getName() {
    return this->name;
}

int Wizard::getMana() const {
    return this->mana;
}