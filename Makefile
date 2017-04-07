# ------------------------------------------------------------------------------
# FILE:         Makefile
#
# DESCRIPTION:  Makefile for Spring 2017 CS202 Project 2: Polynomial Class
#
# NOTES:        None
#
# MODIFICATION HISTORY:
#
# Author        Date          Modification(s)
# -----------   ----------    ---------------
# Aaryna Irwin  2017-03-25    0.1 - Initial version
# ------------------------------------------------------------------------------

CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=Polynomial.cpp poly_class.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=poly_class

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o :
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm $(OBJECTS); find . -name "$(EXECUTABLE)" ! -name "*.cpp" -type f -delete
