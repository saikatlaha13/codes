cc=g++
src=main.cpp
obj=*.o
trgt=a.out

${trgt} : ${obj}
	${cc} $^ -o $@

${obj} : ${src}
	${cc} -c ${src}

clean:
	rm *.o a.out
