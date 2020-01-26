#include "Reader.hpp"

Reader* Reader::_instance = nullptr;

Reader::Reader(std::string path)
{
    _path = path;
}

Reader* Reader::getInstance(std::string path)
{
    if (_instance == nullptr)
    {
        _instance = new Reader(path);
    }
    return _instance;
}

std::string Reader::readConfig()
{
    std::ifstream fichier(_path); 
    std::string line;

    if(fichier)
    {
        while (getline(fichier, line))
        {
            _config += line;
        }
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }

    return _config;
}