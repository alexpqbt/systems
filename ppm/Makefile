TARGET = checkerboard
OUTPUT = checkerboard.mp4

.PHONY: all clean run

all: $(TARGET)

$(TARGET): main.c
	gcc -o $@ $^ 

run: $(TARGET) 
	./$(TARGET)
	ffmpeg -i output-%02d.ppm -r 60 $(OUTPUT)

clean:
	rm -rv *.ppm *.mp4 $(TARGET)

