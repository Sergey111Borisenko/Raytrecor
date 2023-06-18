/*
** EPITECH PROJECT, 2023
** PARSER
** File description:
** PARSER
*/
#include "parser.hpp"

parser::parser()
{

}

libconfig::Config* parser::parse(const char *path)
{
    libconfig::Config *cfg = new libconfig::Config();

    cfg->readFile(path);
    return cfg;
}
