CC                 = g++
CFLAGS             = -o
PATH_HEADER_CP     = src/avlTree.cpp
PATH_HEADER_H      = src/main.cpp
OUT                = calistir


all:
	${CC} ${CFLAGS} ${OUT} ${PATH_HEADER_CP} ${PATH_HEADER_H}
