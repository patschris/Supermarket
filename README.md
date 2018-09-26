# Supermarket
This program simulates how a supermarket works. A customer arrives at queue at a random time and has a random service time. A cashier has to serve every customer that arrives in his queue. The cashiers have to serve all the remaining customers after the closing hour.<br/>
The program prints stats  for each cashier for the:
- Amount of customers served
- Time units that cashier was inactive
- Average time that a customer waited until he served

## Makefile
 - `make` to compile
 - `make clean` to delete the object files and the executable
 - `make run` to execute the program
 - `make check` to run valgrind to check for memory leaks.
