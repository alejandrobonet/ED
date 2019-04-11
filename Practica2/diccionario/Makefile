SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario:$(OBJ)/pruebadiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/*.o -Llib/ -ldiccionario

$(LIB)/libdiccionario.a : $(OBJ)/diccionario.o $(OBJ)/termino.o
	ar rvs $(LIB)/libdiccionario.a $(OBJ)/*.o

$(OBJ)/termino.o : $(SRC)/termino.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/termino.o $(SRC)/termino.cpp

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp $(OBJ)/termino.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp 

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(OBJ)/diccionario.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)


mrproper : clean
	-rm $(BIN)/* doc/html/*
