CC = gcc 
OUT = visit_graph
all:Adj_list.h
	$(CC) -o $(OUT) $(OUT).c -I . -Wall
debug:
	$(CC) -g $(OUT).c -o $(OUT) -I .
clean:
	rm $(OUT)

