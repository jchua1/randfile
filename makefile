compile: rand.c
	gcc -o rand rand.c

run: rand
	./rand

clean:
	rm *~
	rm rand
