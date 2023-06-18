/*
** EPITECH PROJECT, 2023
** GENERATOR IMAGE
** File description:
** GENERATOR IMAGE
*/

#ifndef GENERATOR_IMAGE_HPP_
#define GENERATOR_IMAGE_HPP_

#include <libconfig.h++>
#include <fstream>
#include <cmath>
#include <iostream>

class generator_image
{
    public:
        generator_image();
        void generate_ppm_image(libconfig::Config *cfg);
        bool point_belond_to_sphere(int xSphere, int ySphere, int zSphere, int x, int y, int z, int rayonSphere);
        bool point_belond_to_light(int xLight, int yLight, int zLight, int x, int y, int z, int rayonLight);
        bool light_have_direct_ray_to_sphere(int xSphere, int ySphere, int zSphere, int x, int y, int z, int rayonSphere, int xLight, int yLight, int zLight);
};


#endif