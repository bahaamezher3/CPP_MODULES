#include "ScavTrap.hpp"

int main() {
    ScavTrap guard("Serena");

    guard.attack("Intruder");
    guard.guardGate();
    return 0;
}