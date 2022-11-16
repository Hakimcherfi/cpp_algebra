CC=g++
tags=-Wall

main: Matrix.o main.cpp
	$(CC) $(tags) $^ -o $@

%.o:%.cpp %.h
	$(CC) $(tags) $< -c $@

clean:
	rm main