/**
 * @file Reader.hpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Interface de la classe Reader
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#ifndef READER_HPP
#define READER_HPP

#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Taille du plateau 
 */
#define TAILLE_PLATEAU 20

/**
 * @brief 
 * 
 */
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

#endif