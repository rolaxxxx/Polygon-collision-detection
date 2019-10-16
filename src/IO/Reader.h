
#pragma once

#ifndef READER_H
#define READER_H

#include "core/constants.h"
#include "core/Polygon.h"

class Reader {
public:
  Reader();
  void read_polygon_vertices(std::string filename, Polygon poli);

};

#endif // READER_H
