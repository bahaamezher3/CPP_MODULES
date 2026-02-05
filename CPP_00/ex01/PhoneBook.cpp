#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : _count(0), _nextIndex(0) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::addContact(const Contact &contact)
{
    _contacts[_nextIndex] = contact;
    _nextIndex = (_nextIndex + 1) % 8;
    if (_count < 8)
        _count++;
}

std::string PhoneBook::_formatField(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::displayContacts(void) const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << _formatField(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << _formatField(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << _formatField(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getCount(void) const
{
	return _count;
}