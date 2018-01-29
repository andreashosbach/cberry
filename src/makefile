all: cberry

cberry: cberry.o tft.o RAIO8870.o 
	gcc cberry.o tft.o RAIO8870.o -lbcm2835 -lrt -lm -o cberry

tft.o: tft.c tft.h
	gcc -Os -c tft.c

cberry.o: cberry.c 
	gcc -Os -c cberry.c
	
RAIO8870.o: RAIO8870.c RAIO8870.h
	gcc -Os -c RAIO8870.c


clean:
	rm -rf *o cberry

