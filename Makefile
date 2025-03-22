# COMPILER FLAGS
CXX = g++
CXXFLAGS = -std=c++17 -I include/ -g
LDFLAGS = -L lib/ -lraylib -lGL -lm -lpthread -ldl -lrt

# SOURCE FILES
GAME_SOURCES  = main.cpp src/render.cpp src/entity.cpp src/snake.cpp  src/state.cpp src/uiStates.cpp src/stateController.cpp src/engine.cpp


#OBJECT FILES
GAME_OBJECTS = $(GAME_SOURCES:.cpp=.o)

# OUTPUT EXECUTABLES
GAME_TARGET = game

# DEFAULT TARGET
default: $(GAME_TARGET)

# BUILD GAME EXECUTABLES
$(GAME_TARGET): $(GAME_OBJECTS)
	$(CXX) $(GAME_OBJECTS) $(LDFLAGS) -o $(GAME_TARGET)

# COMPILE .CPP FILES INTO .O FILES
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# CLEAN BUILD ARTIFACTS
clean: 
	rm -rf $(GAME_TARGET) $(GAME_OBJECTS)

# PHONY TARGETS
.PHONY: default clean 
