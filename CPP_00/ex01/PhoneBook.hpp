#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _count;
        int _nextIndex;

        std::string _formatField(const std::string &str) const;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void addContact(const Contact &contact);
        void displayContacts(void) const;
        void displayContact(int index) const;
        int getCount(void) const;

};

#endif