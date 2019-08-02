cc=gcc
src=main.c
obj=*.o
trgt=a.out

${trgt}:${obj}
	${cc} $^ -o $@

${obj}:${src}
	${cc} -c ${src}

clean:
	rm ${obj} *.out
