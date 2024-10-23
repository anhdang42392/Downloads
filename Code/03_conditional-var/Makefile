# Conditional Variable

.PHONY := conVar pooling

CC := gcc
CFLAGS := -pthread

pooling:
	$(CC) -o out main.c $(CFLAGS)

conVar:
	$(CC) -o out con_var.c $(CFLAGS)

clean:
	rm -rf  out con_var