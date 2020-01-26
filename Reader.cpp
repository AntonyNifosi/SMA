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