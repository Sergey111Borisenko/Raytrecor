/*
** EPITECH PROJECT, 2023
** PARSER
** File description:
** PARSER
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <libconfig.h++>

class parser {
    public:
        parser();
        libconfig::Config* parse(const char *path);
};


#endif
