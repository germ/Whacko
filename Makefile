CFLAGS 		= -c -g -Wextra
CC 		 		= gcc
EXEC   		= racko
SRC		 	  = src
BUILD 	  = build
DOXYFILE  = Doxyfile
DOXYDIR	  = Doxy


all: ai.o main.o racko.o tags
	mv *.o $(BUILD)
	$(CC) $(BUILD)/ai.o $(BUILD)/main.o $(BUILD)/racko.o -o $(BUILD)/$(EXEC)

main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c

racko.o: $(SRC)/racko.c
	$(CC) $(CFLAGS) $(SRC)/racko.c

ai.o:	$(SRC)/ai.c 
	$(CC) $(CFLAGS) $(SRC)/ai.c

tags:
	ctags $(SRC)/*.c
	mv tags $(SRC)/tags

clean:
	rm -rf $(BUILD)
	mkdir $(BUILD)
	rm -rf $(DOXYDIR)
	mkdir $(DOXYDIR)
	rm -f $(ARCHIVE)
	rm -f $(SRC)/tags
	rm -f $(SRC)/*.o
	rm -f *.o

doxy:
	doxygen $(DOXYFILE)

run: 
	./$(BUILD)/$(EXEC)

gdb: all
	gdb $(BUILD)/$(EXEC)

val: all
	valgrind ./$(BUILD)/$(EXEC)

splint: 
	splint -checks src/*
