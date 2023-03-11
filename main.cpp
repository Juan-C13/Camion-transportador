/*
  Archivo: laboratorio_1_JC.cpp
  The autor: Juan Esteban Clavijo García <juan.esteban.clavijo@correounivalle.edu.co>
  Fecha creación: 2022/10/11
  Última modificación: 2022/10/25
  Versión: 0.2
*/

/**
  HISTORIA: Tenemos dos camiones y un conjunto de objetos a transportar, para hacer una mudanza. Cada objeto lo intentamos subir al primer camión, pero si no se puede lo llevamos al segundo camión; y si tampoco se puede, lo dejamos en tierra (no se puede transportar). Luego a cada camión le pedimos que haga la mudanza, que nos diga cuanto peso transportó y que descargue los objetos. Adicionado a esto, se chequea el peso de cada objeto y si uno llega a ser menor a 0 kg se descarta (ya que un peso negativo no tiene sentido).
*/

#include "Camion.h"
#include <vector>
#include <iostream>

int main()
{
  Camion primer_camion("ABC-001", 10000);
  Camion segundo_camion("DEF-002", 5000);
  
  vector <int> objetos = {1000, 3000, 5000, 2000, 500, 1800, 4000, 30};

  for(int cual_objeto = 0; cual_objeto < objetos.size(); cual_objeto++)
  {
    int objeto_a_transportar = objetos.at(cual_objeto);
    
    if(objeto_a_transportar<0) //chequea el objeto y si pesa menos de 0 kg se descarta
    {
      objeto_a_transportar = 0;
      cout << "El objeto número " << cual_objeto << " que pesa " << objetos.at(cual_objeto) << " kg no se tiene en cuenta porque un objeto no puede pesar menos de 0 kg." << endl << endl;
    }
    
    if(not primer_camion.cargar_un_objeto(objeto_a_transportar))
    {
      if(not segundo_camion.cargar_un_objeto(objeto_a_transportar))
        cout << "El objeto número " << cual_objeto << " que pesa " << objetos.at(cual_objeto) << " no se puede cargar en ningún camión." << endl << endl;
    }
  }
  
  primer_camion.hacer_mudanza();
  segundo_camion.hacer_mudanza();
  
  cout << "El camión " << primer_camion.cual_es_la_placa() << " transportó " << primer_camion.peso_transportado() << " kg." << endl;
  cout << "El camión " << segundo_camion.cual_es_la_placa() << " transportó " << segundo_camion.peso_transportado() << " kg." << endl;
  
  primer_camion.descargar();
  segundo_camion.descargar();

  return 0;
}
