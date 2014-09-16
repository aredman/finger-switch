#This makefile compiles the parsing program, and all the test programs
#it is somewhat manual, but that's fine. Make sure the bin folder is ignored

SRCDIR = ./src
BINDIR = ./bin

#make everything
all: $(BINDIR)/Parser

#test programs
$(BINDIR)/linearTest: $(SRCDIR)/linearTest.cpp $(SRCDIR)/linearCal.h
	g++ -o $(BINDIR)/linearTest $(SRCDIR)/linearTest.cpp

$(BINDIR)/StatsTest: $(SRCDIR)/StatsTest.cpp $(SRCDIR)/Stats.h
	g++ -o $(BINDIR)/StatsTest $(SRCDIR)/StatsTest.cpp

$(BINDIR)/importTest: $(SRCDIR)/importTest.cpp $(SRCDIR)/import.h
	g++ -o $(BINDIR)/importTest $(SRCDIR)/importTest.cpp

$(BINDIR)/AngleAnalyzerTest: $(SRCDIR)/AngleAnalyzerTest.cpp $(SRCDIR)/AngleAnalyzer.h
	g++ -o $(BINDIR)/AngleAnalyzerTest $(SRCDIR)/AngleAnalyzerTest.cpp

$(BINDIR)/ArgStringTest: $(SRCDIR)/ArgStringTest.cpp $(SRCDIR)/ArgString.h
	g++ -o $(BINDIR)/ArgStringTest $(SRCDIR)/ArgStringTest.cpp

$(BINDIR)/VectorMathTest: $(SRCDIR)/VectorMathTest.cpp $(SRCDIR)/VectorMath.h
	g++ -o $(BINDIR)/VectorMathTest $(SRCDIR)/VectorMathTest.cpp

#main program
$(BINDIR)/Parser: $(BINDIR)/importTest $(BINDIR)/StatsTest $(BINDIR)/linearTest $(BINDIR)/AngleAnalyzerTest $(BINDIR)/ArgStringTest $(BINDIR)/VectorMathTest $(SRCDIR)/main.cpp 
	g++ -o $(BINDIR)/Parser $(SRCDIR)/main.cpp

#testing
test: $(BINDIR)/Parser
	$(BINDIR)/Parser ../Data/Trial1/Trial1 ../Calibrations/main.cal
