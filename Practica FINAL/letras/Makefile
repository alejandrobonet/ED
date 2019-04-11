SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c


all:$(BIN)/letras

cantidad: $(BIN)/cantidad_letras

diccionario: $(BIN)/testdiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/letras: $(OBJ)/letras.o $(LIB)/libletras.a
	$(CXX) -o $(BIN)/letras $(OBJ)/*.o -Llib/ -lletras

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(LIB)/libletras.a
		$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/ConjuntoLetras.o $(OBJ)/diccionario.o -Llib/ -lletras

$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o
				$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o

$(LIB)/libletras.a : $(OBJ)/ConjuntoLetras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/diccionario.o $(OBJ)/letra.o
	ar rvs $(LIB)/libletras.a $(OBJ)/*.o

$(OBJ)/letra.o : $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letra.o $(SRC)/letra.cpp

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

$(OBJ)/ConjuntoLetras.o : $(SRC)/ConjuntoLetras.cpp $(OBJ)/letra.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/ConjuntoLetras.o $(SRC)/ConjuntoLetras.cpp

$(OBJ)/Bolsa_Letras.o : $(SRC)/Bolsa_Letras.cpp $(OBJ)/ConjuntoLetras.o
		$(CXX) $(CPPFLAGS) -o $(OBJ)/Bolsa_Letras.o $(SRC)/Bolsa_Letras.cpp

$(OBJ)/letras.o : $(SRC)/letras.cpp $(OBJ)/ConjuntoLetras.o $(OBJ)/Bolsa_Letras.o $(OBJ)/diccionario.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o $(SRC)/letras.cpp

$(OBJ)/cantidad_letras.o : $(SRC)/cantidad_letras.cpp $(OBJ)/ConjuntoLetras.o $(OBJ)/diccionario.o
		$(CXX) $(CPPFLAGS) -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp

$(OBJ)/testdiccionario.o : $(SRC)/testdiccionario.cpp  $(OBJ)/diccionario.o
			$(CXX) $(CPPFLAGS) -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp
# ************ Limpieza ************
clean :
	-rm $(OBJ)/*.o $(LIB)/*


mrproper : clean
	-rm $(BIN)/* doc/html/*
