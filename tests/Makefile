
INC=-I../include -Iigloo -Wno-deprecated-declarations
CXXFLAGS=-std=c++14

TESTS=test_runner.o \
      test_argconsumer.o \
      test_meta.o \
      # test_option.o \


.cpp.o:
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<

default: testrunner

testrunner: $(TESTS)
	$(CXX) *.o -o testrunner

check: testrunner
	./testrunner

clean:
	rm -f *.o test_runner
