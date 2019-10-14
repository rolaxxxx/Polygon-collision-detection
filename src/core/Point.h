#ifndef POINT_H
#define POINT_H
#include "constants.h"


struct Point {
  REAL x;
  REAL y;
  REAL z;

  bool bandyta_deti_maz = false;
  int koordinacinis_num;
  int ID;
  void PrintStructure() {
    std::cout << " daleles koordinates " << std::endl;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    std::cout << "koordinacinis numeris : " << koordinacinis_num << std::endl;
  }
};

typedef Point PointType;
typedef std::vector<PointType> PointsArrayType;

typedef std::set<PointType> PointsSetType;

//// TODO operatorius perkrauti kad butu patogu matematinius vieksmus atlikti,
///cia tik aprasai, kodas i cxx faila.
/// tai butu +,-,daugyba dalyba is skaliaro, cross product, dot product,
/// vektoriaus ilgis
///

Point operator*(Point A, INT B);
Point operator+(Point A, Point B);
Point operator*(REAL A, Point B);
Point operator*(Point A, Point B);
Point operator/(Point A, REAL B);
Point operator-(Point A, REAL B);
Point operator+(Point A, REAL B);
Point operator-(Point A, Point B);
bool operator!=(PointType A, PointType B);
REAL dot_prod(Point vec_a, Point vec_b);
Point cross_prod(Point vec_a, Point vec_b);
REAL vector_len(Point vec);
REAL vec_distance(Point a, Point c);
Point cross2D(Point vec_a, Point vec_b);
REAL tripleScalarProd(Point vec_a, Point vec_b, Point vec_c);

#endif // POINT_H
