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
  bool posicion; //si es true, es front, si es false, es back
};

list<imagenes> imagenesCargadas;

void llenarLista()
{
  if(imagenesCargadas.empty())
  {
    
  }
}

void guardarIMagen(Mat imagen,String nombre)
{
  imwrite( nombre + ".png", imagen );
  cout<<"-----IMAGEN " << nombre << ".png CREADA----"<<endl; 
}

Mat canalesRGB(Mat image)
{
  // Crear canales de las Imagenes

  // Canal Rojo
  Mat rImg = Mat::zeros( image.size( ), CV_8UC3 );
  
  // Canal Verde
  Mat gImg = Mat::zeros( image.size( ), CV_8UC3 );

  // Canal Azul
  Mat bImg = Mat::zeros( image.size( ), CV_8UC3 );
   
  // Fill color channel images
  MatIterator_< Vec3b > it, crIt, cgIt, cbIt, rgbIt, end, endr, endg, endb, endrgb;
  it = image.begin< Vec3b >( );
  crIt = rImg.begin< Vec3b >( );
  cgIt = gImg.begin< Vec3b >( );
  cbIt = bImg.begin< Vec3b >( );
  end = image.end< Vec3b >( );
  endr = rImg.end< Vec3b >( );
  endg = gImg.end< Vec3b >( );
  endb = bImg.end< Vec3b >( );
  for(  ; it != end, crIt != endr, cgIt != endg, cbIt != endb; ++it, ++crIt, ++cgIt, ++cbIt)
  {
  	(*crIt)[0] = 0;
  	(*crIt)[1] = 0;
  	(*crIt)[2] = (*it)[2];

  	(*cgIt)[0] = 0;
  	(*cgIt)[1] = (*it)[1];
  	(*cgIt)[2] = 0;
  	
  	(*cbIt)[0] = (*it)[0];
  	(*cbIt)[1] = 0;
  	(*cbIt)[2] = 0;

  } // rof

  // Escribir Resultados de Canales

  guardarIMagen(rImg,"canal_Rojo");
  guardarIMagen(gImg,"canal_Verde");
  guardarIMagen(bImg,"canal_Azul");

  //Compresion de Tamaño

  Mat res_img_R = Mat::zeros( rImg.size( ), CV_8UC3 );
  Mat res_img_B = Mat::zeros( gImg.size( ), CV_8UC3 );
  Mat res_img_G  = Mat::zeros( bImg.size( ), CV_8UC3 );


  resize(rImg, res_img_R, Size(), 0.75 , 0.75 , INTER_LINEAR);  
  resize(gImg, res_img_G, Size(), 0.5 , 0.5 , INTER_LINEAR);
  resize(bImg, res_img_B, Size(), 0.25 , 0.25 , INTER_LINEAR);

  //Escribir Resultados de Compresion


  guardarIMagen(res_img_R,"canal_Rojo_comprimido");
  guardarIMagen(res_img_G,"canal_Verde_comprimido");
  guardarIMagen(res_img_B,"canal_Azul_comprimido");

  //Inicio de Reescalado

  Mat res_img_R_2 = Mat::zeros( res_img_R.size( ), CV_8UC3 );
  Mat res_img_G_2  = Mat::zeros( res_img_B.size( ), CV_8UC3 );
  Mat res_img_B_2 = Mat::zeros( res_img_G.size( ), CV_8UC3 );

  resize(res_img_R, res_img_R_2, Size(), 1.333 , 1.333 , INTER_LINEAR);
  resize(res_img_G, res_img_G_2, Size(), 2 , 2 , INTER_LINEAR);  
  resize(res_img_B, res_img_B_2, Size(), 4 , 4 , INTER_LINEAR);  

  //Escribir Resultados

  guardarIMagen(res_img_R_2,"canal_Rojo_reescalado");
  guardarIMagen(res_img_R_2,"canal_Verde_reescalado");
  guardarIMagen(res_img_B_2,"canal_Azul_reescalado");

  //Reconstruir Imagen

  // From color channel images, reconstruct the original color image

  Mat rgbImg = Mat::zeros( image.size( ), CV_8UC3 );

  MatIterator_< Vec3b > rgbIt_2,crIt_2,cgIt_2,cbIt_2,endr_2,endg_2,endb_2,endrgb_2;

  crIt_2 = res_img_R_2.begin< Vec3b >( );
  cgIt_2 = res_img_G_2.begin< Vec3b >( );
  cbIt_2 = bImg.begin< Vec3b >( );
  rgbIt_2 = rgbImg.begin< Vec3b >( );
  endr_2 = res_img_R_2.end< Vec3b >( );
  endg_2 = res_img_G_2.end< Vec3b >( );
  endb_2 = res_img_B_2.end< Vec3b >( );
  endrgb_2 = rgbImg.end< Vec3b >( );
  for(  ; crIt_2 != endr_2, cgIt_2 != endg_2, cbIt_2 != endb_2, rgbIt_2 != endrgb_2; ++crIt_2, ++cgIt_2, ++cbIt_2, ++rgbIt_2)
  {
  	(*rgbIt_2)[0] = (*cbIt_2)[0];
  	(*rgbIt_2)[1] = (*cgIt_2)[1];
  	(*rgbIt_2)[2] = (*crIt_2)[2];
  }

  //Escribir Resultados

  guardarIMagen(rgbImg,"canal_rRGB");

  //Comparacion de Imagenes reescaladas y Original

  Mat resultado = Mat::zeros( image.size( ), CV_8UC3 );

  MatIterator_< Vec3b > ItOriginalI, ItOriginalF, ItResultadoI , ItResultadoF, ItDeferenciaI, ItDeferenciaF;

  ItOriginalI = image.begin< Vec3b >( );
  ItOriginalF = image.end< Vec3b >( );

  ItResultadoI = rgbImg.begin< Vec3b >( );
  ItResultadoF = rgbImg.end< Vec3b >( );

  ItDeferenciaI = resultado.begin< Vec3b >( );
  ItDeferenciaF = resultado.end< Vec3b >( );

  for( ; ItDeferenciaI != ItDeferenciaF, ItOriginalI != ItOriginalF, ItResultadoI != ItResultadoF ; ItDeferenciaI++, ItOriginalI++, ItResultadoI++){
    (*ItDeferenciaI) = (*ItResultadoI) - (*ItOriginalI);
  }

  //Escribir Resultado

  guardarIMagen(resultado,"canal_Diferencia");

  return resultado;

}

/*Mat metodoDistorsion(Mat srcFrame, int k1) 
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
}*/

Mat segmentarImg(Mat imagen)
{
  int threshold_value = 4;
    // Valid Values: 0, 1, 2, 3, 4
  int threshold_type = 1; 
    // maxVal, useful for threshold_type 1 and 2
  int maxVal = 255;
    // Source image
  Mat src = imagen;
  Mat src_gray, dst;
    // Convert the image to GrayScale
  cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
  guardarIMagen(src_gray,"escala_gris");
  
  threshold(src_gray, dst, threshold_value,maxVal, threshold_type);
  guardarIMagen(dst,"segmentado");
  return dst;
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
  Mat prueba = segmentarImg(imagen);
  resultado = canalesRGB(imagen);
  resultado = eliminarRuido(resultado); 
  return resultado;
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

  //llenarLista();
  Mat imagenF = prepararImagen(image);

  if(!imagenesCargadas.empty())
  {
    cout<<"Lista de Imagenes llena"<<endl;
  }
  else{
    cout<<"Lista de Imagenes vacia"<<endl;
  }
}