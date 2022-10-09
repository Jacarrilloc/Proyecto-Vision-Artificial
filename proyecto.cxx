#include "iostream"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <list>
using namespace std;
using namespace cv;

list<Mat> imagenes;

void guardarIMagen(Mat imagen,String nombre)
{
  imwrite( nombre + ".png", imagen );
  cout<<"-----IMAGEN " << nombre << ".png CREADA----"<<endl; 
}

Mat eliminarRuido(Mat imagen)
{
  Mat sinRuido;
  Mat kernel, kernel_2;
  Point anchor,anchor_2;
  double delta;
  int ddepth;
  int kernel_size, kernel_size_2;

  anchor = Point( -1 , -1 );
  delta = 0;
  ddepth = -1;

  for(int i = 0 ; i < 5 ; i++)
  {
    int ind = 0;
    for(int i=0;i<5;i++)
    {
      kernel_size = 3 + 2*( ind%5 );
      kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
      filter2D(imagen, sinRuido, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
    }
  }
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
  if(imagenes.empty())
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

  if(!imagenes.empty())
  {
    cout<<"Lista de Imagenes llena"<<endl;
  }
  else{
    cout<<"Lista de Imagenes vacia"<<endl;
  }
}