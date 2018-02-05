all: create_pic.o
	gcc -o picture create_pic.o

create_pic.o: create_pic.c
	gcc -c create_pic.c

run: all
	./picture
	convert picture.ppm picture.png
	open picture.png
