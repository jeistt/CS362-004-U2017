CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

cardEffects.o: cardEffects.c cardEffects.h
	gcc -c cardEffects.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o cardEffects.o 
	gcc -c dominion.c -g  $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o cardEffects.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o cardEffects.o $(CFLAGS)

	
rtaout: randomtestadventurer
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out 	
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o cardEffects.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o cardEffects.o $(CFLAGS)

rtc1out: randomtestcard1
	./randomtestcard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o cardEffects.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o cardEffects.o $(CFLAGS)

rtc2out: randomtestcard2
	./randomtestcard2 >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out

cardtest1: cardtest1.c dominion.o rngs.o cardEffects.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o cardEffects.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o cardEffects.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o cardEffects.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o cardEffects.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o cardEffects.o $(CFLAGS)


cardtest4: cardtest4.c dominion.o rngs.o cardEffects.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o cardEffects.o $(CFLAGS)


unittest1: unittest1.c dominion.o rngs.o cardEffects.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o cardEffects.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o cardEffects.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o cardEffects.o $(CFLAGS)
unittest3: unittest3.c dominion.o rngs.o cardEffects.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o cardEffects.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o cardEffects.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o cardEffects.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o cardEffects.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
