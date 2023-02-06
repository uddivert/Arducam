CC = g++
SRC = src
LIBS = -lArduCamLib -lusb-1.0 -larducam_config_parser -lpthread #`pkg-config --cflags --libs opencv`
FLAGS = -L. -I. -std=gnu++11 -g
LDIR = ./Arducam_SDK
IDIR = ./include

Arducam_USB_Driver: $(SRC)/test.cpp  $(IDIR)/ArduCamLib.h
	$(CC) $^ -o $@ $(LIBS) $(FLAGS) 

.PHONY:clean

clean:
	rm -f Arducam_USB_Driver 
