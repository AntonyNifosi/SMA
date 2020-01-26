#include <iostream>

class Reader
{
    private :
        static Reader* _instance;
        std::string _path;

    public :
        Reader(std::string path);
        static Reader* getInstance(std::string path);
};