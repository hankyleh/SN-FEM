CXX := g++
SRC_DIR := src
BUILD_DIR := build
C_FLAGS := -O0 -std=c++17
CWD := $(CURDIR)

SOURCES := input.cpp echo.cpp parse.cpp msg.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)
BUILD_OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS))

MFEM_LIB := $(CWD)/tpls/mfem-4.9/

all: snsolve check_mfem

check_mfem:
	@if [ -d "$(MFEM_LIB)" ]; then \
		true; \
	else \
		echo "MFEM library not found -- specify with  make MFEM_LIB='full/path/mfem' "; \
		exit 1; \
	fi


snsolve: $(BUILD_OBJECTS)
	$(CXX) $^ -I$(MFEM_LIB) -L$(MFEM_LIB) -lmfem  -o $@ $(C_FLAGS)



$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) -c $< -I$(MFEM_LIB) -L$(MFEM_LIB) -lmfem  -o $@  -I./src $(C_FLAGS)

clean:
	rm -rf $(BUILD_DIR) snsolve