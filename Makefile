.PHONY: all

CC = g++

BUILD_DIR = build
TARGET = trajets
TEST_TARGET = test_trajets


SRC:= $(wildcard src/*.cpp)

#SRC := src/main.cpp src/Catalogue.cpp src/TrajetCompose.cpp src/TrajetSimple.cpp

OBJ := $(SRC:%.cpp=$(BUILD_DIR)/%.o)
SRC_TEST := src/Trajet.cpp src/TrajetCompose.cpp src/TrajetSimple.cpp src/Catalogue.cpp test/TestCatalogue.cpp test/Test.cpp test/TestTrajetSimple.cpp test/TestTrajetCompose.cpp test/main.cpp
OBJ_TEST := $(SRC_TEST:%.cpp=$(BUILD_DIR)/%.o)

CFLAGS := -ansi -pedantic -Wall -std=c++11 -Isrc -Itest
# LDFLAGS :=
ifdef MAP
	CFLAGS += -DMAP
endif

ifdef COLORS
	CFLAGS += -DCOLORS
endif

ifdef DEBUG
	CFLAGS += -g

endif

ifdef SAN
	CFLAGS += -fsanitize=address
	LDFLAGS += -lasan
endif


all: $(TARGET)
	@echo "Done."


map: $(TARGET)



# édition des liens
$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# fichiers objets
$(BUILD_DIR)/%.o: %.cpp
	@echo $(@D)
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


test: $(TEST_TARGET)

# édition des liens
$(TEST_TARGET): $(OBJ_TEST) | $(BUILD_DIR)
	$(CC) $(OBJ_TEST) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir build
