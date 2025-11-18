.PHONY: all

BUILD_DIR = build
TARGET = $(BUILD_DIR)/catalogue_interactif
TEST_TARGET = $(BUILD_DIR)/test_catalogue_interactif

SRC:= $(wildcard src/*.cpp)

#SRC := src/main.cpp src/Catalogue.cpp src/Trajet.cpp src/TrajetCompose.cpp src/TrajetSimple.cpp

OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
SRC_TEST := $(SRC) test/TestTrajetSimple.cpp test/TestTrajetCompose.cpp test/TestTrajet.cpp
OBJ_TEST := $(SRC_TEST:%.cpp=$(BUILD_DIR)/%.o)

CFLAGS := -ansi -pedantic -Wall -std=c++11
# LDFLAGS := 

all: $(TARGET)
	@echo "Done.\n"

# édition des liens
$(TARGET): $(OBJ) | $(BUILD_DIR)
	g++ $(OBJ) -o $@ $(LDFLAGS)

# fichiers objets
$(BUILD_DIR)/%.o: %.cpp
	@echo $(@D)
	mkdir -p $(@D)
	g++ $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 


test: $(TEST_TARGET)

# édition des liens
$(TEST_TARGET): $(OBJ_TEST) | $(BUILD_DIR)
	g++ $(OBJ_TEST) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir build
