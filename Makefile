SOURCES:= $(wildcard *.c) $(wildcard *.h)
OBJECTS:= $(wildcard *.c)
OUT:= bin/main
main: $(SOURCES)
	cc -W -Wall -o $(OUT) $(OBJECTS)

debug: $(SOURCES)
	cc -g -o $(OUT) $(OBJECTS)
