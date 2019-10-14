 
#include "Reader.h"
 
 void Reader::read_polygon_vertices(std::string filename, Polygon poli){



  vtkDataSetReader *reader = vtkDataSetReader::New();
  reader->SetFileName(filename.c_str());
  reader->Update();


  // int tasku_kiekis=reader->GetOutput()->GetNumberOfPoints();
  int vertex_count=reader->GetOutput()->GetNumberOfPoints();
  // cout << tria_kiekis << "---------- trikampiu kiekis " << endl;
  double p[3];
  Point perkelimas;



  for (int i = 0; i < vertex_count; i++) {
        reader->GetOutput()->GetPoint(i, p);
        perkelimas.x=p[0];
        perkelimas.y=p[1];
        perkelimas.z=p[2];
        poli.add_vertex(perkelimas);
  }
}
