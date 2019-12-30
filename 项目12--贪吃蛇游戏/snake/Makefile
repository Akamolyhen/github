IMAGE = a.out
SRC = $(shell ls *.c)
OBJ = $(SRC:%.c=%.o)

VPATH += .
CFLAGS += -I ./  -g   -lpthread 

CC = arm-linux-gcc

$(IMAGE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	ctags *.[ch]

%.o : %.c
	$(CC) -c $< $(CFLAGS)


.PHONY:clean

clean:
	rm $(OBJ) $(IMAGE)



