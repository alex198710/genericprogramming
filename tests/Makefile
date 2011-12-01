include ../Makefile.inc

SRC = $(wildcard *.cpp)
OUT = $(SRC:.cpp=.out)

all: $(OUT)

%.out:
	@$(ECHO) Warning: No rule defined for [$@] test

%.o: %.cpp
	@$(ECHO) Compiling [$<]
	@$(CC) -c $< -o $@ $(CC_FLAGS)

clean:
	@$(ECHO) Cleaning directory
	@$(RM) -f *.o

distclean: clean
	@$(ECHO) Dist cleaning directory
	@$(RM) -f *.out

#---- TESTS ----

base_type_detection.out: base_type_detection.o
	@$(ECHO) Linking [$@]
	@$(LD) -o $@ $^ $(LD_FLAGS)