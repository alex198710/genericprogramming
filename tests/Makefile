include ../Makefile.inc

SRC = $(wildcard *.cpp)
OUT = $(SRC:.cpp=.out)

all: $(OUT)

%.out: %.o
	@$(ECHO) Linking [$@]
	@$(LD) -o $@ $< $(LD_FLAGS)

%.o: %.cpp
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

clean:
	@$(ECHO) Cleaning directory
	@$(RM) -f *.o

distclean: clean
	@$(ECHO) Dist cleaning directory
	@$(RM) -f *.out

#---- TESTS ----

multi_array_traits_iterator.o: multi_array_traits_iterator.cpp ../multi_array_traits_iterator.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

multi_array_traits_baseType.o: multi_array_traits_baseType.cpp ../multi_array_traits_baseType.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

multi_array_traits_depth.o: multi_array_traits_depth.cpp ../multi_array_traits_depth.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

multi_array_range.o: multi_array_range.cpp ../multi_array_range.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

multi_array_stack.o: multi_array_stack.cpp ../multi_array_stack.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

#multi_array_view.o: multi_array_view.cpp ../multi_array_view.h
#	@$(ECHO) Compiling [$<]
#	@$(CC) -o $@ -c $< $(CC_FLAGS)
#multi_array_view.out: multi_array_view.o ../multi_array_view.o ../multi_array_range.o
#	@$(ECHO) Linking [$@]
#	@$(LD) -o $@ $^ $(LD_FLAGS)
multi_array_view.out:
	@$(ECHO) Compiling [$@] : Disabled