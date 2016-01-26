FLAGS = -std=c++0x
FLAGS += -lncursesw
TITLE = shoppingList
CPP = NcursesTools.cpp
CPP += List.cpp
CPP += Item.cpp
CPP += Display.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${FLAGS} ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
