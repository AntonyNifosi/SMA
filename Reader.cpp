/**
 * @file Reader.cpp
 * @author Rémi Valarcher - Antony Nifosi
 * @brief Implémentation des fonctions relatives à la classe Reader
 * @version 1
 * @date 2019-04-01
 * 
 * @copyright Copyright (c) 2020
 */

#include "Reader.hpp"

/// Initialisation de l'instance du Reader à nullptr
Reader* Reader::_instance = nullptr;


/**
 * @brief Constructeur de la classe Reader
 * 
 * @param path chemin vers le fichier de configuration
 */
Reader::Reader(std::string path)
{
    _path = path;
}

/**
 * @brief Implémentation du patron singleton renvoyant le reader déjà créer ou sinon en crée un nouveau
 * 
 * @param path chemin vers le fichier de configuration
 * @return Reader* Reader créé
 */
Reader* Reader::getInstance(std::string path)
{
    /// Permet de vérifier si un Reader a déjà été créé
    if (_instance == nullptr)
    {
        _instance = new Reader(path);
    }
    return _instance;
}

/**
 * @brief Fonction retournant le contenu du fichier de configuration du Reader
 * 
 * @return std::string Contenu de fichier de configuration lu
 */
std::string Reader::readConfig()
{
    std::ifstream ifs(_path);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()));;

    _config = content;
    std::cout << "Fichier lu :\n" << _config << std::endl;
    return _config;
}