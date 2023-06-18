/*
** EPITECH PROJECT, 2023
** GENERATOR IMAGE
** File description:
** GENERATOR IMAGE
*/
#include "generator_image.hpp"

generator_image::generator_image()
{

}

bool generator_image::point_belond_to_sphere(int xSphere, int ySphere, int zSphere, int x, int y, int rayonSphere)
{
    for (int z = 0; z < zSphere; z++) {
        if (pow(rayonSphere, 2) - 50 < pow((xSphere - x), 2) + pow((ySphere - y), 2) + pow((zSphere - z), 2) && pow((xSphere - x), 2) + pow((ySphere - y), 2) + pow((zSphere - z), 2) < pow(rayonSphere, 2) + 50)
            return true;
    }
    //if (pow(rayonSphere, 2) - 50 < (pow((xSphere - x), 2) + pow((ySphere - y), 2)) && (pow((xSphere - x), 2) + pow((ySphere - y), 2)) < pow(rayonSphere, 2) + 50)
    //    return true;
    return false;
}

void generator_image::generate_ppm_image(libconfig::Config *cfg)
{
    const libconfig::Setting &racine = cfg->getRoot();

    const libconfig::Setting &sphere = racine["sphere"];
    int xSphere = sphere.lookup("x");
    int ySphere = sphere.lookup("y");
    int zSphere = sphere.lookup("z");
    int rayonSphere = sphere.lookup("rayon");


    const libconfig::Setting &light = racine["light"];
    int xLight = light.lookup("x");
    int yLight = light.lookup("y");
    int zLight = light.lookup("z");

    int width = 800;
    int height = 600;

    std::ofstream image("image.ppm");

    image << "P3" << std::endl;
    image << width << " " << height << std::endl;
    image << "255" << std::endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (point_belond_to_sphere(xSphere, ySphere, zSphere, x, y, rayonSphere))
                image << "195 0 0 ";
            else
                image << "0 0 0 ";
        }
        image << std::endl;
    }

    image.close();
}