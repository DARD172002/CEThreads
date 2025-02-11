GCC = gcc
FLAGS = -Wall -g -I.
OUT_DIR = out
OBJ = $(OUT_DIR)/CEThreads.o

$(OUT_DIR)/main: $(OBJ) main.c
	$(GCC) $(FLAGS) $(OBJ) main.c -o $(OUT_DIR)/main

$(OUT_DIR)/CEThreads.o: library/CEThreads.c library/CEThreads.h
	$(GCC) $(FLAGS) -c library/CEThreads.c -o $(OUT_DIR)/CEThreads.o

delete:
	rm -f $(OUT_DIR)/main $(OUT_DIR)/CEThreads.o
