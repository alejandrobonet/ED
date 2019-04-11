SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


colapila: $(BIN)/Cola_pila

colaVD: $(BIN)/Cola_VD
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/Cola_pila : $(OBJ)/pruebacola_max.o
	$(CXX) -o $(BIN)/Cola_pila $(OBJ)/pruebacola_max.o

$(BIN)/Cola_VD :  $(OBJ)/pruebacola_max.o
	$(CXX) -o $(BIN)/Cola_VD  $(OBJ)/pruebacola_max.o

$(OBJ)/pruebacola_max.o:  $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp 




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*  $(OBJ)/*
