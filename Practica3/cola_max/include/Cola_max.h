/**
  * @file Cola_max.h
  * @brief Documento que se usa para decidir la implementacion de la cola
  *
  */

#define CUAL_COMPILA 1	
#if CUAL_COMPILA == 1
 #include "Cola_max_vd.h"
#else
 #include "Cola_max_pila.h"
#endif



