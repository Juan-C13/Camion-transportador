/*
  Archivo: Camion.h
  Autor: Juan Esteban Clavijo Garcia <juan.esteban.clavijo@correounivalle.edu.co>
  Fecha creación: 2022-10-11
  Fecha última modificación: 2022-10-25
*/

/**
  CLASE: Camion
  INTENCIÓN: Estoy modelando un camión con una placa, que puede transportar una cierta carga en kilos, y que tiene una capacidad máxima en kilos. Se le puede pedir que me diga su placa, que cargue un objeto, que transporte toda la carga y que me diga cuanto transportó y que descargue todo.
  RELACIONES: Ninguna
*/

#ifndef HH_CAMION
#define HH_CAMION

#include <string>
using namespace std;

class Camion
{
  private:
  string la_placa;
  int la_capacidad_maxima;
  int peso_cargado_actual;
  bool mudanza_realizada;
       
  public:
  /**
  Constructor: Da valores iniciales a los atributos internos.
  */
  Camion(string la_placa, int la_capacidad_maxima);
  /**
  Destructor: No hace nada.
  */
  virtual ~Camion();
  /**
  Pregunta y retorna la placa del camion.
  */
  virtual string cual_es_la_placa();
  /**
  Mira el peso de un objeto y si este se puede cargar.
  true = se pudo hacer; false = no se pudo.
  */
  bool cargar_un_objeto(int peso_del_objeto);
  /**
  Da la orden al camion de hacer la mudanza.
  */
  virtual void hacer_mudanza();
  /**
  Retorna la carga que transportó.
  */
  virtual int peso_transportado();
  /**
  Descarga los objetos que lleva en el momento.
  */
  virtual void descargar();
};

#else
class Camion;
#endif