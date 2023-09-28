#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

int main()
{
    try
    {
        typedef struct language {
            std::string lang;
            std::string designer;
            int date;
        }language_t;

        std::vector<language_t> books;

        std::ifstream inf("language.txt");
        if(!inf.fail())
        {
            std::string line;
            while(std::getline(inf, line))
            {
                std::istringstream is(line);
                language_t langs;
                if(!(is >> langs.lang >> langs.designer >> langs.date))
                    std::runtime_error("Error reading inptut stream");

                books.push_back(langs);
            }
        }

        for(const auto& e : books)
            std::cout << e.lang << ", " << e.designer << ", " << e.date << "\n";
    }
    catch(std::exception& e)
    {
        std::cout << "Exception occurred while parsing " << e.what();
    }

    return 0;
}
