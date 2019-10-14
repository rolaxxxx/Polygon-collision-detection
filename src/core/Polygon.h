
#ifndef MAIN_H
#define MAIN_H
#include "Point.h"


class Polygon{
public:
    Polygon();
    void add_vertex(Point p);

protected:
      std::vector<Point> vertices;
    
    
    
};



#endif
