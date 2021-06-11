CC = g++
EXEC = HeroCorp
FLAGS = -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
STD = -std=c++17
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/Main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/Main.o: $(O)/Engine.o $(O)/ApiManager.o
	$(CC) $(S)/Main.cpp -c -o $(O)/Main.o $(STD) $(FLAGS)

$(O)/Engine.o: $(O)/World.o
	$(CC) $(S)/engine/Engine.cpp -c -o $(O)/Engine.o $(STD) $(FLAGS)

$(O)/World.o: $(O)/ApiManager.o
	$(CC) $(S)/business/World.cpp -c -o $(O)/World.o $(STD) $(FLAGS)

$(O)/ApiManager.o: $(O)/Forum.o $(O)/Guild.o $(O)/Dungeon.o
	$(CC) $(S)/api/ApiManager.cpp -c -o $(O)/ApiManager.o $(STD) $(FLAGS)

$(O)/Forum.o: $(O)/AbstractLocation.o
	$(CC) $(S)/business/Forum.cpp -c -o $(O)/Forum.o $(STD) $(FLAGS)

$(O)/Dungeon.o: $(O)/AbstractLocation.o
	$(CC) $(S)/business/Dungeon.cpp -c -o $(O)/Dungeon.o $(STD) $(FLAGS)

$(O)/Guild.o: $(O)/AbstractLocation.o 
	$(CC) $(S)/business/Guild.cpp -c -o $(O)/Guild.o $(STD) $(FLAGS)

$(O)/AbstractLocation.o: $(O)/Hunter.o $(O)/Monster.o
	$(CC) $(S)/business/AbstractLocation.cpp -c -o $(O)/AbstractLocation.o $(STD) $(FLAGS)

$(O)/Hunter.o: $(O)/AbstractPerso.o
	$(CC) $(S)/business/Hunter.cpp -c -o $(O)/Hunter.o $(STD) $(FLAGS)

$(O)/Monster.o: $(O)/AbstractPerso.o
	$(CC) $(S)/business/Monster.cpp -c -o $(O)/Monster.o $(STD) $(FLAGS)

$(O)/AbstractPerso.o:
	$(CC) $(S)/business/AbstractPerso.cpp -c -o $(O)/AbstractPerso.o $(STD) $(FLAGS)


clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)
