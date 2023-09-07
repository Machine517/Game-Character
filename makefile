GameCharacter: game.o GameCharacter.o
    c++ game.o GameCharacter.o -o GameCharacter

game.o: game.cpp
    c++ -c game.cpp

GameCharacter.o: GameCharacter.cpp
    c++ -c GameCharacter.cpp

clean:
    rm *.o GameCharacter
