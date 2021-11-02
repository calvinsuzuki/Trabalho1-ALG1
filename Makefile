UTIL=Source/jogo.c Source/catalogo.c Source/Util.c
MAIN=main.c
BINARY=Main
ZIP=Ex2

all:
	gcc -Wall -g -I ./ $(UTIL) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)

ex:
	./$(BINARY)<2.in

clear:
	clear

r: clear all run

rr: clear all ex
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o

zip:
	@zip -r ../$(ZIP).zip *

delzip:
	@rm $(ZIP).zip
