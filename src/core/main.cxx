
#pragma once
#include "main.h"
#include "core/constants.h"
#include "IO/Reader.h"



int main(int, char *[])
{   

    Reader reader;
    Polygon poli;
    reader.read_polygon_vertices("polygons.vtk", poli);



  return EXIT_SUCCESS;

}
