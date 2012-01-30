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

multi_array_dimensions.o: multi_array_dimensions.cpp ../multi_array_dimensions.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)
multi_array_dimensions.out: multi_array_dimensions.o ../multi_array_dimensions.o
	@$(ECHO) Linking [$@]
	@$(LD) -o $@ $^ $(LD_FLAGS)

range_traits.o: range_traits.cpp ../include/pps/range/traits.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

range_traitsBaseType.o: range_traitsBaseType.cpp ../include/pps/range/traitsBaseType.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

range_begin.o: range_begin.cpp ../include/pps/range/begin.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

range_end.o: range_end.cpp ../include/pps/range/end.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

range_indexes.o: range_indexes.cpp ../include/pps/range/indexes.h ../include/pps/range/traits.h
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)

range_viewSubRange.o: range_viewSubRange.cpp ../include/pps/range/viewSubRange.h ../src/pps/range/viewSubRange.cpp ../include/pps/range/viewSubRangeIterator.h ../src/pps/range/viewSubRangeIterator.cpp
	@$(ECHO) Compiling [$<]
	@$(CC) -o $@ -c $< $(CC_FLAGS)
range_viewSubRange.out: range_viewSubRange.o ../src/pps/range/viewSubRange.o ../src/pps/range/viewSubRangeIterator.o
	@$(ECHO) Linking [$@]
	@$(LD) -o $@ $^ $(LD_FLAGS)

range_view.o: range_view.cpp ../include/pps/range/view.h
	@$(ECHO) Compiling [$<]
range_view.out: range_view.o
	@$(ECHO) Linking [$@]