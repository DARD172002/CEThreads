GCC = gcc
FLAGS = -Wall -g -I.
OUT_DIR = out
OBJ = $(OUT_DIR)/CEThreads.o


# Asegurar que el directorio de salida exista antes de compilar

$(OUT_DIR)/main: $(OBJ) main.c
	$(GCC) $(FLAGS) $(OBJ) main.c -o $(OUT_DIR)/main

$(OUT_DIR)/CEThreads.o: library/CEThreads.c library/CEThreads.h
	$(GCC) $(FLAGS) -c library/CEThreads.c -o $(OUT_DIR)/CEThreads.o

$(OUT_DIR)/test_library: test/test_library.c $(OBJ) 
	$(GCC) $(FLAGS) $(OBJ) test/test_library.c  -o $(OUT_DIR)/test_library

delete:
	rm -f $(OUT_DIR)/main $(OUT_DIR)/CEThreads.o
