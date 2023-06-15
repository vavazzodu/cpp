CC = g++
FLAG = -Wall -Wextra -g

default:
	$(CC) $(FLAG) main.cpp MyString.cpp -o exe

clean:
	rm exe
