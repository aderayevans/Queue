#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Testcase
{
    private:
        std::vector<std::string> tcase;
        std::string name;
    public:
        Testcase(std::string link_file)
        {
            name = link_file;
        }
        std::vector<std::string> get()
        {
            return this->tcase;
        }
        std::string get(int index)
        {
            return tcase[index];
        }
        bool create() 
        {
            std::string str;
            std::ofstream ofs (this->name);
            char ch;
            int testcase = 0;
            std::cout << "How much testcase do you want? ";
            std::cin >> testcase;
            std::cin.ignore();
            if (ofs.is_open()) {
                for (int i = 0; i < testcase; i++) {
                    if (i != 0) ofs << "\n";
                    std::cout << "Testcase " << i+1 << ": ";
                    getline(std::cin, str);
                    this->tcase.push_back(str);
                    std::stringstream ss(str);
                    while(ss >> std::noskipws >> ch) {
                        ofs << ch;
                    }
                }
                ofs.close();
                return true;
            }
            else {
                std::cout << "Unable to open file";
                return false;
            }
        }
        bool read() 
        {
            std::ifstream ifs(this->name);
            std::string str;
            int i = 0;
            if (ifs.is_open()) {
                while(getline(ifs,str)) {
                    this->tcase.push_back(str);
                }
                ifs.close();
                return true;
            }
            else {
                std::cout << "Unable to read file";
                return false;
            }
        }
};