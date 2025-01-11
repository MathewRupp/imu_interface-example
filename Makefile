CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = main.c bosch_sensor.c stm_sensor.c
OBJ = $(SRC:.c=.o)
EXEC = accelerometer_demo

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)

