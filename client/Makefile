CC = g++ -g 
CFLAGS = -std=c++11

#DIR_BIN = ./bin
TARGET = target
BIN_TARGET = ./${TARGET}
LIB = -L /usr/lib/ -lpthread -lboost_thread


SRC = $(wildcard ./*.cpp)

${BIN_TARGET}:${SRC}
	${CC}  ${CFLAGS} $^ -o ${TARGET} ${LIB}

.PHONY:clean
clean:
	rm  $(TARGET)
