#include <iostream>
#include <fstream>
#include "Sed.hpp"

bool Sed::replaceInFile(const std::string& filename,
                        const std::string& s1,
                        const std::string& s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return false;
    }

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return false;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error: could not create output file" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::string result;
        std::size_t pos = 0;
        std::size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result.append(line, pos, found - pos);
            result.append(s2);
            pos = found + s1.length();
        }
        result.append(line, pos, line.length() - pos);

        outfile << result;
        if (!infile.eof())
            outfile << std::endl;
    }

    return true;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    if (!Sed::replaceInFile(argv[1], argv[2], argv[3]))
        return 1;

    return 0;
}
