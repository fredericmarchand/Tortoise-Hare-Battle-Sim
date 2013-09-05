play:		Hare.o  Tortoise.o  Screen.o  random.o  Deque.o  Pirate.o  PirateNode.o  Battle.o  main.o
		g++ -o play Hare.o Tortoise.o Screen.o Deque.o Pirate.o PirateNode.o Battle.o main.o random.o

main.o:		main.cpp  Battle.h
		g++ -c main.cpp

Hare.o:		Hare.cpp  Hare.h  Pirate.h  random.h
		g++ -c Hare.cpp

Tortoise.o:	Tortoise.cpp  Tortoise.h  Pirate.h  random.h
		g++ -c Tortoise.cpp

Screen.o:	Screen.cpp  Screen.h  Tortoise.h  Hare.h
		g++ -c Screen.cpp

Pirate.o:	Pirate.cpp  Pirate.h  random.h  Tortoise.h  Hare.h
		g++ -c Pirate.cpp

PirateNode.o:	PirateNode.cpp PirateNode.h Pirate.h
		g++ -c PirateNode.cpp

Deque.o:	Deque.cpp  Deque.h  Pirate.h PirateNode.h
		g++ -c Deque.cpp

Battle.o:	Battle.cpp  Battle.h  Deque.h  Hare.h  Tortoise.h  Screen.h  Pirate.h  PirateNode.h
		g++ -c Battle.cpp

clean:
	rm -f Tortoise.o Hare.o Screen.o Deque.o Pirate.o PirateNode.o Battle.o main.o play
