#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) 
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout << "DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << _name 
              << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}