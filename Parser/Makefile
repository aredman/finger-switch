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

$(BINDIR)/ArgString: $(SRCDIR)/ArgStringTest.cpp $(SRCDIR)/ArgString.h
	g++ -o $(BINDIR)/ArgStringTest $(SRCDIR)/ArgStringTest.cpp

#main program
$(BINDIR)/Parser: $(BINDIR)/importTest $(BINDIR)/StatsTest $(BINDIR)/linearTest $(BINDIR)/AngleAnalyzerTest $(BINDIR)/ArgString
	g++ -o $(BINDIR)/Parser $(SRCDIR)/main.cpp
