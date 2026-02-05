#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static std::string getInput(const std::string &prompt)
{
	std::string input;
	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return "";
	}
	return input;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
		{
			Contact contact;
			contact.setFirstName(getInput("First name: "));
			contact.setLastName(getInput("Last name: "));
			contact.setNickname(getInput("Nickname: "));
			contact.setPhoneNumber(getInput("Phone number: "));
			contact.setDarkestSecret(getInput("Darkest secret: "));
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.getCount() == 0)
			{
				std::cout << "PhoneBook is empty." << std::endl;
				continue;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index: ";
			std::string indexStr;
			std::getline(std::cin, indexStr);
			int index = std::atoi(indexStr.c_str());
			phoneBook.displayContact(index);
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}
