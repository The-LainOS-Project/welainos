CC=g++
SRC_DIR=src
SRC_FILES = src/main.cpp src/about.cpp src/r_image.cpp src/u_config.cpp src/window.cpp
OBJS = $(SRC_FILES:.cpp=.o)
DFILES = $(SRC_FILES:.cpp=.d)
GTKMMLIBS=`pkg-config gtkmm-4.0 --cflags --libs`
CXXFLAGS = `pkg-config gtkmm-4.0 --cflags --libs` -std=c++17 -Wall -g
BIN_DIR=bin
OUTPUT=$(BIN_DIR)/lainOS
PREFIX := /usr/local

all: lainOS

%.o: %.cpp
	$(CC) -MD -c $< -o $@ $(CXXFLAGS)
	@echo "[$(shell g++ --version | head -n 1)] $(shell date --iso=seconds) FILE $< COMPILED" >> LOG

lainOS: $(OBJS)
	@mkdir -p bin
	$(CXX) -o $(OUTPUT) $^ $(GTKMMLIBS)
	@echo "[+ $(shell ln --version | head -n 1)] $(shell date --iso=seconds) ALL OBJECT FILES GOT LINKED" >> LOG
clean:
	rm -f $(OBJS)
	rm -f $(DFILES)
	rm -f LOG

install: 
	install -m 777 $(BIN_DIR)/$(OUTPUT) $(DESTDIR)$(PREFIX)/bin/
	install -m 777 media/a.svg $(DESTDIR)/usr/share/icons/
	install -m 777 media/b.png $(DESTDIR)/usr/share/icons/
	install -m 777 media/c.png $(DESTDIR)/usr/share/icons/
	install -m 777 media/d.png $(DESTDIR)/usr/share/icons/
	install -m 777 lainos.desktop $(DESTDIR)/usr/share/

