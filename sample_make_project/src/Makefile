IDIR =../include
ODIR =../obj
CC=g++

CFLAGS=-I$(IDIR)
LIBS=-lm

# $(patsubst pattern,replacement,text)
# Finds whitespace-separated words in text that match pattern and replaces them
# with replacement.
_DEPS = string_process.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = test.o string_process.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

foo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~

# Note:
# rule_name: dependency_list
#	rule_definition
# $@: Value at left side of :, i.e., rule_name
# $^: Value at right side of :, i.e., entire dependency_list
# $<: First value in right side of :, i.e., first entry in dependency_list
