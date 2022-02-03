cal.out : quadratic.o triples.o sum.o cal.o 
	g++ -o "cal.exe" quadratic.o triples.o sum.o cal.o 

quadratic.o : quadratic.c
	g++ -c quadratic.c

triples.o : triples.c
	g++ -c triples.c

sum.o : sum.c
	g++ -c sum.c

cal.o : cal.c
	g++ -c cal.c

clean:
	rm -rf *.o