COMPILER =  g++

FLAGS =  -Wall -std=c++20

LINKS = -Iinc  -lSDL2 -lSDL2_image -lSDL2_ttf

TARGET =  ./src/*.cpp

EXECUTABLE = game


build:
	$(COMPILER) $(FLAGS) $(TARGET)  $(LINKS) -o  $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clear:
	rm -f $(EXECUTABLE)