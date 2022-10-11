#include "iostream"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <list>
using namespace std;
using namespace cv;


struct imagenes
{
  Mat imagen;
  int valor;
};


list<imagenes> imagenesCargadas;

void guardarIMagen(Mat imagen,String nombre)
{
  imwrite( nombre + ".png", imagen );
  cout<<"-----IMAGEN " << nombre << ".png CREADA----"<<endl; 
}

Mat metodoDistorsion(Mat srcFrame, int k1) 
{    
  Mat map_x, map_y, output;
  double Cy = (double)srcFrame.cols/2;
  double Cx = (double)srcFrame.rows/2;
  map_x.create(srcFrame.size(), CV_32FC1);
  map_y.create(srcFrame.size(), CV_32FC1);
    
  for (int x=0; x<map_x.rows; x++) {
    for (int y=0; y<map_y.cols; y++) {
      double r2 = (x-Cx)*(x-Cx) + (y-Cy)*(y-Cy);
        map_x.at<float>(x,y) = (double) ((y-Cy)/(1 + double(k1/1000000.0)*r2)+Cy); // se suma para obtener la posicion absoluta
        map_y.at<float>(x,y) = (double) ((x-Cx)/(1 + double(k1/1000000.0)*r2)+Cx); // la posicion relativa del punto al centro
      }
  }
  remap(srcFrame, output, map_x, map_y, CV_INTER_LINEAR);
  return output;
}

Mat eliminarRuido(Mat imagen)
{
  Mat sinRuido;
  GaussianBlur( imagen, sinRuido, Size(3,3), 3, 3);
  GaussianBlur( sinRuido, sinRuido, Size(3,3), 3, 3);
  guardarIMagen(sinRuido,"sin_Ruido");
  return sinRuido;
}

Mat prepararImagen(Mat imagen)
{
  Mat resultado;
  resultado = eliminarRuido(imagen);
  return imagen;
}

void llenarLista()
{
  if(imagenesCargadas.empty())
  {
    cout<<"entró a if "<<endl;
  }
}

int main( int argc, char** argv )
{
    //-----LECTURA DE IMAGEN-----

    if ( argc < 2 )
    {
        std::cerr << "Usage: " << argv[ 0 ] << " image_file" << std::endl;
        return( -1 );
    } 

  std::cout << "-------------------------" << std::endl;
  for( int a = 0; a < argc; a++ )
    std::cout << argv[ a ] << std::endl;
  std::cout << "-------------------------" << std::endl;

  Mat image;
  image = imread( argv[1], 1 );

  if ( !image.data )
  {
    std::cerr << "Error: No image data" << std::endl;
    return( -1);
  }

  //-------- INICIO DEL PROGRAMA ---------

  llenarLista();
  Mat imagenF = prepararImagen(image);

  if(!imagenesCargadas.empty())
  {
    cout<<"Lista de Imagenes llena"<<endl;
  }
  else{
    cout<<"Lista de Imagenes vacia"<<endl;
  }
}