#define MAX_VALUE 256
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>
#include "Resource.h"
#include <boost/compute/types.hpp>
#include <boost/compute/core.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/detail/sha1.hpp>
#include <boost/compute/utility/source.hpp>
#include <boost/compute/utility/program_cache.hpp>
#include <boost/lockfree/queue.hpp>
#include <experimental/filesystem>
#include <iostream>
#include <boost/compute/utility/wait_list.hpp>
#include <vector>
#include <math.h>
#include <boost/compute/system.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/algorithm/stable_sort_by_key.hpp>
#include <cstddef>
#include <algorithm>
#include <boost/assert.hpp>
#include <ctime>
#include <ratio>
#include <stdlib.h>
#include <boost/compute/system.hpp>
#include <boost/compute/algorithm/is_sorted.hpp>
#include <boost/compute/core.hpp>
#include <boost/compute/device.hpp>
#include <boost/compute/algorithm/detail/insertion_sort.hpp>
#include <boost/compute/async/future.hpp>
#include <boost/compute/event.hpp>
#include <boost/compute/algorithm/detail/radix_sort.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <boost/compute/core.hpp>
#include <boost/assert.hpp>
#include <algorithm>
#include <boost/compute/algorithm/stable_sort.hpp>
#include <boost/compute/algorithm/detail/merge_sort_on_gpu.hpp>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/functional/math.hpp>
#include <chrono>"
#include <CL/cl.h>
using boost::compute::int_;
#include <boost/compute/algorithm/sort_by_key.hpp>
namespace compute = boost::compute;
using namespace std;
using std::vector;
using std::cout;
using std::endl;
#include "vtkDataSetReader.h"
#include "vtkPointData.h"
#include <iterator>
#include "vtkPolyData.h"
#include <vtkPolyData.h>
#include "boost/multi_array.hpp"
#include "vtkDataSet.h"
#include <vtkDataSet.h>
#include "vtkDataArray.h"
#include "vtkDataSetWriter.h"
#include "vtkCellArray.h"
#include "vtkDoubleArray.h"
#include "vtkCellData.h"
#include <map>
#include <boost/compute/algorithm/unique.hpp>
#include<stdio.h>
#include <CL/cl.h>
#include <string.h>
#include <stdlib.h>
typedef boost::compute::double_ REAL;
typedef boost::compute::double4_ REAL4;
typedef boost::compute::uint_ UINT;
typedef boost::compute::int_ INT;
typedef boost::compute::int2_ INT2;
typedef boost::compute::uint4_ UINT4;
typedef boost::compute::ulong_ ULONG;
typedef boost::compute::uchar_ UCHAR;
 class Vertex {

     float x = 0;
     float y = 0;
     float z = 0;

     Vertex(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
      Vertex calculateMassCenter(vector<Face> faces) {
         Vertex massCenter = new Vertex(0, 0, 0);
         float mass = 0;
         for (Face face : faces) {
             Vertex triangleCenter = face.getCenter();
             float faceMass = face.getSurface();
             mass += faceMass;
             massCenter.x += faceMass * triangleCenter.x;
             massCenter.y += faceMass * triangleCenter.y;
             massCenter.z += faceMass * triangleCenter.z;
         }
         massCenter.x /= mass;
         massCenter.y /= mass;
         massCenter.z /= mass;
         return massCenter;
     }
};

class Face {

     Vertex v1;
     Vertex v2;
     Vertex v3;

     Face(Vertex v1, Vertex v2, Vertex v3) {
        this->v1 = v1;
        this->v2 = v2;
        this->v3 = v3;
    }

     Vertex getCenter() {
        Vertex triangleCenter = new Vertex(0, 0, 0);
        triangleCenter.x += v1.x;
        triangleCenter.x += v2.x;
        triangleCenter.x += v3.x;
        triangleCenter.y += v1.y;
        triangleCenter.y += v2.y;
        triangleCenter.y += v3.y;
        triangleCenter.z += v1.z;
        triangleCenter.z += v2.z;
        triangleCenter.z += v3.z;
        triangleCenter.x /= 3;
        triangleCenter.y /= 3;
        triangleCenter.z /= 3;
        return triangleCenter;
    }

     float getSurface() {
        float x1 = v1.x - v2.x;
        float x2 = v1.y - v2.y;
        float x3 = v1.z - v2.z;
        float y1 = v1.x - v3.x;
        float y2 = v1.y - v3.y;
        float y3 = v1.z - v3.z;
        return (float) sqrt(
                pow(x2 * y3 - x3 * y2, 2) +
                pow(x3 * y1 - x1 * y3, 2) +
                pow(x1 * y2 - x2 * y1, 2) ) / 2.f;
    }
};

