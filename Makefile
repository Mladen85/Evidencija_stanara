# test\Makefile

################################################################
## Makefile is used to build library "libmy_game.a",
## to use this library, make and run test (test_)
################################################################

# Compiler to use
CCOMPILER = g++

# Test name
#TEST = _zgrada


################################################################
## LIBRARY
# Library path
LIB_DIR = lib

# Library archive
LIB = stan
LIB_NAME = $(LIB_DIR)/lib$(LIB).a

# Library source
SRC_LIB_DIR = src
SRC_LIB = $(wildcard $(LIB_DIR)/$(SRC_LIB_DIR)/*.cpp)

# Library include (headers)
INC_LIB_DIR = inc
INC_LIB = $(wildcard $(LIB_DIR)/$(INC_LIB_DIR)/*.h)

# Library object
OBJ_LIB_DIR = obj
OBJ_LIB = $(patsubst %,$(LIB_DIR)/$(OBJ_LIB_DIR)/%, $(notdir $(SRC_LIB:.cpp=.o)))
################################################################

################################################################
## APPLICATION
TARGET = test

# Test path
#TEST_DIR = test

# Use for final application
# Application source
SRC_APP = $(wildcard *.cpp)

# TODO - When there are all test apps, use argument to run each test
# As we are testing now, there will be only one test app for each test
#TEST_APP = $(wildcard $(TARGET).cpp)

# Application object
#TEST_OBJ_APP_DIR = obj
#OBJ_APP = $(patsubst %,$(TEST_OBJ_APP_DIR)/%, $(&(TEST_APP):.cpp=.o))
OBJ_APP_DIR = obj
OBJ_APP = $(patsubst %,$(OBJ_APP_DIR)/%, $(SRC_APP:.cpp=.o))
################################################################

################################################################
# Defining compiler, compiler flags and linker flags
CC = $(CCOMPILER)
DEBUG_FLAG = -g
CFLAGS_LIB = -std=c++11 -I$(LIB_DIR)/$(INC_LIB_DIR)
CFLAGS_APP = -std=c++11 -I$(LIB_DIR)/$(INC_LIB_DIR)
LFLAGS_APP = -l$(LIB) -L$(LIB_DIR)
W_PEDANTIC = -Wall -pedantic

################################################################

## make library is first to set it as default make rule

################################################################
## make library
# Command to first create lib/obj direcotory (if doesn't exist), compile cpp files and then create library
make_lib: | $(LIB_DIR)/$(OBJ_LIB_DIR) $(LIB_NAME)

# Create library
$(LIB_NAME) : $(OBJ_LIB)
	$(AR) -cr $@ $^

# Create lib/obj folder if doesn't exist
$(LIB_DIR)/$(OBJ_LIB_DIR):
	mkdir -p $(LIB_DIR)/$(OBJ_LIB_DIR)

# Compile cpp files
$(LIB_DIR)/$(OBJ_LIB_DIR)/%.o : $(LIB_DIR)/$(SRC_LIB_DIR)/%.cpp
	$(CC) $(DEBUG_FLAG) $(CFLAGS_LIB) -c $< -o $@

################################################################


################################################################
## Build application
$(TARGET) : $(OBJ_APP) $(LIB_NAME)
	$(CC) $(DEBUG_FLAG) $(LFLAGS_APP) -o $@ $^

# Compile application
$(OBJ_APP_DIR)/%.o : %.cpp
	$(CC) $(DEBUG_FLAG) $(CFLAGS_APP) -c $< -o $@

# Create obj folder
$(OBJ_APP_DIR):
	mkdir -p $(OBJ_APP_DIR)

################################################################


.PHONY : run all make_app make_lib clean_all clean app_clean libs_build libs_clean help

# Run program
run : all
	./$(TARGET)

# Create obj folder (if doesn't exist) and build project
all : libs_build make_app


make_app: | $(OBJ_APP_DIR) $(TARGET)


# Run library (build library)
libs_build : make_lib


# Clean program and delete obj folders
clean_all: clean
	$(RM) -d $(OBJ_APP_DIR)
	$(RM) -d $(LIB_DIR)/$(OBJ_LIB_DIR)

# Clean program
clean : app_clean libs_clean

# Changed because of Windows specific requirements
# g++ is adding .exe at the end of out file
# (can't use obj/*.o, have to use obj\*o)

# Clean application
app_clean :
	$(RM) $(TARGET) $(OBJ_APP)

# Clean library
libs_clean :
	$(RM) $(OBJ_LIB) $(LIB_NAME)


help :
	@echo "inc_lib: $(INC_LIB)"
	@echo "src_lib: $(SRC_LIB)"
	@echo "obj_lib: $(OBJ_LIB)"
	@echo "src_app: $(SRC_APP)"
	@echo "obj_app: $(OBJ_APP)"