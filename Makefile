EXECUTABLE = motor_test
CC = g++ -O3
CFLAGS = -g -Wall 
LDFLAGS = -lpthread -L. -lrobotlib

all: motor_test.o
	@mkdir -p bin
	@mkdir -p error_files
	@rm -f /error_files/*
	@echo "Linking all objects to ./bin/motor_test"
	@$(CC) $(CFLAGS) motor_test.o -o ./bin/$(EXECUTABLE) $(LDFLAGS)

motor_test.o: motor_test.cpp 
	@echo "Compiling motor_test.cpp to motor_test.o"
	@$(CC) $(CFLAGS) -c motor_test.cpp -o motor_test.o

run: 
	./bin/$(EXECUTABLE)

clean:
	@rm -f *.o
	@rm -f ./bin/$(EXECUTABLE) 
	@rm -f -R ./error_files
