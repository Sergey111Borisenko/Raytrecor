/*
** EPITECH PROJECT, 2023
** GENERATOR IMAGE
** File description:
** GENERATOR IMAGE
*/
#include "generator_image.hpp"

generator_image::generator_image()
{
    compteur = 0;
}

bool generator_image::point_belond_to_sphere(int xSphere, int ySphere, int zSphere, int x, int y, int z, int rayonSphere)
{
    for (int z2 = 0; z2 < z + rayonSphere; z2++) {
        if (pow(rayonSphere, 2) - (z + rayonSphere * 2) < pow((xSphere - x), 2) + pow((ySphere - y), 2) + pow((zSphere - z2), 2) && pow((xSphere - x), 2) + pow((ySphere - y), 2) + pow((zSphere - z2), 2) < pow(rayonSphere, 2) + (z + rayonSphere * 2))
            return true;
    }
    return false;
}

bool generator_image::point_belond_to_light(int xLight, int yLight, int zLight, int x, int y, int z, int rayonLight)
{
    for (int z2 = 0; z2 < z + rayonLight; z2++) {
        if (pow(rayonLight, 2) - (z + rayonLight * 2) < pow((xLight - x), 2) + pow((yLight - y), 2) + pow((zLight - z2), 2) && pow((xLight - x), 2) + pow((yLight - y), 2) + pow((zLight - z2), 2) < pow(rayonLight, 2) + (z + rayonLight * 2))
            return true;
    }
    return false;
}

bool generator_image::light_have_direct_ray_to_sphere(int xSphere, int ySphere, int zSphere, int x, int y, int z, int rayonSphere, int xLight, int yLight, int zLight)
{
    int dx = xSphere - xLight;
    int dy = ySphere - yLight;
    int dz = zSphere - zLight;
    float distance = pow(dx, 2) + pow(dy, 2) + pow(dz, 2);
    distance = sqrt(distance);

    int dx2 = 0;
    int dy2 = 0;
    int dz2 = 0;
    float distance2 = 0;

    for (int z2 = 0; z2 < z + rayonSphere; z2++) {
        dx2 = x - xLight;
        dy2 = y - yLight;
        dz2 = z - zLight;
        distance2 = sqrt(pow(dx2 , 2) + pow(dy2 , 2) + pow(dz2 , 2));

        if (distance2 < distance) {
            return true;
        }
    }
    return false;
}

void generator_image::generate_ppm_image(libconfig::Config *cfg)
{
    const libconfig::Setting &racine = cfg->getRoot();

    const libconfig::Setting &sphere = racine["sphere"];
    int rayonSphere = sphere.lookup("rayon");
    int xSphere = sphere.lookup("x");
    int ySphere = sphere.lookup("y");
    int zSphere = sphere.lookup("z");


    const libconfig::Setting &light = racine["light"];
    int rayonLight = light.lookup("rayon");
    int xLight = light.lookup("x");
    int yLight = light.lookup("y");
    int zLight = light.lookup("z");

    int width = 800;
    int height = 600;

    std::ofstream image("image.ppm");

    image << "P3" << std::endl;
    image << width << " " << height << std::endl;
    image << "255" << std::endl;

    int red = 180;
    std::string strRed = "180";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (point_belond_to_sphere(xSphere, ySphere, zSphere, x, y, std::max(zSphere, zLight), rayonSphere)) {
                if (light_have_direct_ray_to_sphere(xSphere, ySphere, zSphere, x, y, std::max(zSphere, zLight), rayonSphere, xLight, yLight, zLight)) {
                    if (compteur == 100) {
                        red += 1;
                        strRed = std::to_string(red);
                        image << strRed + " 0 0 ";  
                        compteur = 0;
                    } else
                        image << strRed + " 0 0 ";
                    compteur += 1;
                } else
                    image << "180 0 0 ";
            }
            else if (point_belond_to_light(xLight, yLight, zLight, x, y, std::max(zSphere, zLight), rayonLight)) {
                image << "255 255 51 ";
            }
            else
                image << "0 0 0 ";
        }
        image << std::endl;
    }

    image.close();
}