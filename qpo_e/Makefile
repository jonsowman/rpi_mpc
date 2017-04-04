# Jon Sowman 2016-17
# jonathan.sowman@ricardo.com
# November 2016
#
# This file is part of the Ultra-low NOx (ULN) project and EngD project
#
# All rights reserved
# Ricardo 2016-17
#

CC = gcc
FLAGS = -Wall -Wno-unused-function -fopenmp -D__SUPPRESSANYOUTPUT__

# All of the model is in this directory
MODEL = uln_rti_linux
ERT_OUTPUT = uln_rti_linux_ert_rtw

# Include sources
QPOASES_DIR = $(MODEL)/.uln_build
ERT_DIR = $(MODEL)/$(ERT_OUTPUT)
ULN_DIR = $(MODEL)

# List all the include directories
INCLUDE_DIRS = -I$(ERT_DIR) -I$(QPOASES_DIR) -I$(QPOASES_DIR)/qpo -I$(QPOASES_DIR)/qpo/include -I$(QPOASES_DIR)/qpo/include/qpOASES_e -I$(QPOASES_DIR)/qpo/include/qpOASES_e/extras
#-I$(EMBEDDED_CODER)/extern/include -I$(EMBEDDED_CODER)/rtw/c/src/ -I$(EMBEDDED_CODER)/simulink/include/

# Enumerate .c sources
ULN_SRC = $(wildcard $(ULN_DIR)/*.c)
QPO_SRC = $(wildcard $(QPOASES_DIR)/qpo/src/*.c) $(QPOASES_DIR)/rqp.c
ERT_SRC = $(filter-out $(ERT_DIR)/ert_main.c, $(wildcard $(ERT_DIR)/*.c))
SOURCES = $(ULN_SRC) $(ERT_SRC) $(QPO_SRC)
OBJS = $(SOURCES:.c=.o)

# Link against which libs?
LIBS = -static -lm

# Name of the binary to be built
BIN_NAME = uln_rti

# Makefile targets
%.o: %.c
	@echo Building $@
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c -o $@ $< $(LIBS)

all:	$(OBJS)
	$(CC) $(FLAGS) -o $(BIN_NAME) $(OBJS) $(LIBS)

clean:
	@echo "Removing binary and object files"
	$(RM) $(BIN_NAME)
	$(RM) $(OBJS)
