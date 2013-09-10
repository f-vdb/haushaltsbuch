# 
# Makefile-4
# change the make file with make -f filename
# 
# Attention:
# target: dependencies
# [tab] system command   DON'T FORGET THE TAB AT THE BEGINNING OF THE LINE
#
# c++0x
CC= clang++
#CC= g++
# -c compile, but do not link
# -O optimize  (-O1 or -O2 or -O3)
#CFLAGS= -Wextra -Weffc++ -pedantic -O -std=c++0x -c
# c++98
CFLAGS= -Wextra -Weffc++ -pedantic -O -std=c++11  -c 
#CFLAGS= -Wextra -Weffc++ -pedantic -g -std=c++11  -c
LDFLAGS= 
SOURCES= main.cpp OpenFile.cpp showMainMenu.cpp wrongInput.cpp buildMenu.cpp fillVector.cpp printVector.cpp \
		 oberkatVerwalten.cpp showOberkatMenu.cpp writeVectorToFile.cpp timeStamp.cpp account.cpp  makeBackup.cpp deleteAccount.cpp timeframe.cpp pressAnyKeyToContinue.cpp userInputsNumber.cpp
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE=haushaltsbuch.out	
# install: all
# 	mv $(EXECUTABLE) c:\...
#
all: $(SOURCES) $(EXECUTABLE)
	rm *.o		   # delete all object files IMPORTANT use cmd.exe or rm *.o
	#./$(EXECUTABLE)  # start the programm

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
# $< current file
# $@ 
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# make -f Makefile-4 clean
clean:
	rm *.o

# .PHONY tells Make which targets are not files.
# This avoids conflict with file of the same name, and improve performance.
# Generally all targets, which do not produce the file with the target name,
# should be PHONY.
PHONY: clean all


