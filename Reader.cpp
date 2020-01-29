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
    std::ifstream ifs(_path);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()));;

    _config = content;
    std::cout << "Fichier lu :\n" << _config << std::endl;
    return _config;
}