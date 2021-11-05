SRC = $(wildcard src/*.cpp)
INC = -I"C:\Users\Ethan\Programming\c++\Libraries\SDL2\include" -I"C:\Users\Ethan\Programming\c++\BUG\include" -L"C:\Users\Ethan\Programming\c++\Libraries\SDL2\lib"
LIB = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -std=c++17
OUT = BUG

$(OUT).EXE: $(SRC)
	@g++ $(SRC) $(INC) $(LIB) -o $(OUT)
	@$(OUT).exe

