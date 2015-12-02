CC=gcc
CFLAGS=-g -c -Wall -export-dynamic `pkg-config --cflags gtk+-3.0`
LDFLAGS=-g -Wall -export-dynamic -ludev `pkg-config --libs gtk+-3.0`
SOURCES=main.c ps3ir.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=girbox
DEPS=$(OBJECTS:.o=.d)


all: $(SOURCES) $(EXECUTABLE)


clean:
	$(RM) $(OBJECTS) $(DEPS) $(EXECUTABLE)


rebuild: clean all


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@


.c.o:
	$(CC) -MMD -MP $(CFLAGS) $< -o $@


-include $(DEPS)
