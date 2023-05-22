make: build run

build:
	g++ src/*.cpp src/**/*.cpp -o bin/exe -Ilib -Llib -lm3 -ltdRGB

run:
	./bin/exe