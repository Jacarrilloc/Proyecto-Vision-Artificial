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