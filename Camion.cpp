/*
  Archivo: Camion.cpp
  Autor: Juan Esteban Clavijo Garc{ia} <juan.esteban.clavijo@correounivalle.edu.co>
  Fecha creación: 2022-10-11
  Fecha última modificación: 2022-10-25
*/

#include "Camion.h"

Camion::Camion(string la_placa, int la_capacidad_maxima): la_placa(la_placa),la_capacidad_maxima(la_capacidad_maxima)
{
  peso_cargado_actual = 0;
  mudanza_realizada = false;
}

Camion::~Camion()
{
  //No hay que hacer nada
}

string Camion::cual_es_la_placa()
{
  return la_placa;
}

bool Camion::cargar_un_objeto(int peso_del_objeto)
{
  if(peso_cargado_actual + peso_del_objeto <= la_capacidad_maxima)
  {
    peso_cargado_actual = peso_cargado_actual + peso_del_objeto;
    return true;
  }
  else
    return false;
}

void Camion::hacer_mudanza()
{
  mudanza_realizada = true;
}

int Camion::peso_transportado()
{
  if(mudanza_realizada)
    return peso_cargado_actual;
  else
    return 0;
} 

void Camion::descargar()
{
  mudanza_realizada = false;
  peso_cargado_actual = 0;
}