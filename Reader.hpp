#include <iostream>
#include <string>
#include <fstream>

#define TAILLE_PLATEAU 20

class Reader
{
    private :
        static Reader* _instance;
        std::string _path;
        std::string _config;

    public :
        Reader(std::string path);
        static Reader* getInstance(std::string path);
        std::string readConfig();
};