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
FLAGS = -Wall -fopenmp

# All of the model is in this directory
MODEL = rti_qpon
ERT_OUTPUT = uln_rti_qpon_linux_ert_rtw
# This directory contains all the fluff from Embedded Coder/Simulink
EMBEDDED_CODER = R2014b

# Include sources
QPOASES_WRP_DIR = $(MODEL)/.uln_build
ERT_DIR = $(MODEL)/$(ERT_OUTPUT)
ULN_DIR = $(MODEL)

# Where is the qpOASES library?
LIB_DIRS = -L/home/pi/qpOASES-3.2.0/bin

# List all the include directories
INCLUDE_DIRS = -I$(QPOASES_WRP_DIR) -I$(ERT_DIR) -I$(EMBEDDED_CODER)/extern/include -I$(EMBEDDED_CODER)/rtw/c/src/ -I$(EMBEDDED_CODER)/simulink/include/

# Enumerate .c sources
ULN_SRC = $(wildcard $(ULN_DIR)/*.c)
QPO_SRC = $(wildcard $(QPOASES_WRP_DIR)/*.c)
ERT_SRC = $(filter-out $(ERT_DIR)/ert_main.c, $(wildcard $(ERT_DIR)/*.c))
SOURCES = $(ULN_SRC) $(ERT_SRC) $(QPO_SRC)
OBJS = $(SOURCES:.c=.o)

# Link against which libs?
LIBS = -static -lm -lqpOASES_wrapper -lstdc++ 

# Name of the binary to be built
BIN_NAME = uln_rti

# Makefile targets
%.o: %.c
	@echo Building $@
	$(CC) $(FLAGS) $(INCLUDE_DIRS) -c -o $@ $< $(LIB_DIRS) $(LIBS)

all:	$(OBJS)
	$(CC) $(FLAGS) -o $(BIN_NAME) $(OBJS) $(LIB_DIRS) $(LIBS)

clean:
	@echo "Removing binary and object files"
	$(RM) $(BIN_NAME)
	$(RM) $(OBJS)
