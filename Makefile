CC = g++ -g

spellchecker: spellchecker.o
	$(CC) spellchecker.o -o spellchecker

spellchecker.o: spellchecker.cpp
	$(CC) spellchecker.cpp -c

.PHONY: clean
clean:
	rm -f spellchecker spellchecker.o