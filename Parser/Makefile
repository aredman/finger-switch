#This makefile compiles the parsing program, and all the test programs
#it is somewhat manual, but that's fine. Make sure the bin folder is ignored

SRCDIR = ./src
BINDIR = ./bin

#make everything
all: $(BINDIR)/importTest $(BINDIR)/StatsTest

#test programs
$(BINDIR)/importTest:
	g++ -o $(BINDIR)/importTest $(SRCDIR)/importTest.cpp

$(BINDIR)/StatsTest:
	g++ -o $(BINDIR)/StatsTest $(SRCDIR)/StatsTest.cpp
