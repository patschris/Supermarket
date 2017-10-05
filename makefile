CC		= gcc
CFLAGS	= -g3 -Wall
EXEC 	= SuperMarket
OBJS 	= ATDTamias.o ch6_QArray.o ch6_Simulation.o TStoixeiouOuras.o
SRCS 	= ATDTamias.c ch6_QArray.c ch6_Simulation.c TStoixeiouOuras.c


.PHONY : all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

ATDTamias.o: ATDTamias.c
	$(CC) $(CFLAGS) -c ATDTamias.c

ch6_QArray.o: ch6_QArray.c
	$(CC) $(CFLAGS) -c ch6_QArray.c


ch6_Simulation.o: ch6_Simulation.c
	$(CC) $(CFLAGS) -c ch6_Simulation.c

TStoixeiouOuras.o: TStoixeiouOuras.c
	$(CC) $(CFLAGS) -c TStoixeiouOuras.c



.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)



.PHONY: run
run:
	./$(EXEC)



.PHONY: check
check:
	valgrind --leak-check=full ./$(EXEC)
