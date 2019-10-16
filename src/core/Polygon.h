#pragma once
#ifndef POLYGON_H
#define POLYGON_H


#include "core/constants.h"
#include "core/Point.h"
class Polygon{
public:
    Polygon();
    void add_vertex(Point p);

protected:
      vector<Point> vertices;
    
    
    
};



#endif
