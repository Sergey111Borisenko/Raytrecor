/*
** EPITECH PROJECT, 2023
** RAYTRECOR
** File description:
** RAYTRECOR
*/
#include "raytrecor.hpp"
#include "parser.hpp"
#include "generator_image.hpp"

int main(int argc, char **argv)
{
    parser Parser = parser();
    libconfig::Config *cfg = Parser.parse(argv[1]);

    generator_image gen = generator_image();
    gen.generate_ppm_image(cfg);
    return 0;
}
