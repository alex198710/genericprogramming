include Makefile.inc

LIB = libMultiArray.so

all: tests

tests: forceLook
	@$(CD) tests ; $(MAKE)

clean:
	@$(ECHO) Cleaning project
	@$(RM) -Rf src/*.o
	@$(CD) tests ; $(MAKE) clean

distclean: clean
	@$(ECHO) Dist cleaning project
	@$(RM) -f $(LIB)
	@$(CD) tests ; $(MAKE) distclean

forceLook:
	@true