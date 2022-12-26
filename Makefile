CC = g++
CXXFLAGS = -std=c++20 -Wall
LDFLAGS = 

# main engine variables
APPNAME = breeze
OUT = bin/breeze.exe

files := ${wildcard src/*.cpp}
files += ${wildcard utils/*.cpp}
files += ${wildcard src/core/*.cpp}
files += ${wildcard src/list/*.cpp}
include = -I.

${APPNAME}:
	${CC} ${include} -o ${OUT} ${files}
	cd bin && breeze.exe -h

build:
	${CC} ${include} -o ${OUT} ${files}

clean:
	cd bin && del breeze.exe
