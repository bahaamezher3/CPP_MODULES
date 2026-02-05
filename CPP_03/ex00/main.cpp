#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Bob");

    robot.attack("Target");
    robot.takeDamage(5);
    robot.beRepaired(5);
    return 0;
}