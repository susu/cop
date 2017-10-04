
INC=-I../include -Iigloo -Wno-deprecated-declarations
CXXFLAGS=-std=c++14

TESTS=test_runner.o \
      test_argconsumer.o \
      test_meta.o \
      test_option.o \
      test_flag.o \
      test_posarg.o \


.cpp.o:
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

$(OBJECTS) : %.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	@$(CC) -M $< > $@

default: testrunner

testrunner: $(TESTS)
	$(CXX) *.o -o testrunner

check: testrunner
	./testrunner

clean:
	rm -f *.o test_runner
