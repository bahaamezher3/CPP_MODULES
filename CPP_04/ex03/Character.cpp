#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character constructor called (" << name << ")" << std::endl;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        name = other.name;
        
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called (" << name << ")" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
    
    if (!inventory[idx]) {
        std::cout << "Slot " << idx << " is already empty" << std::endl;
        return;
    }
    
    std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
    
    if (!inventory[idx]) {
        std::cout << "No materia in slot " << idx << std::endl;
        return;
    }
    
    inventory[idx]->use(target);
}