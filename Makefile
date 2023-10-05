CC=g++
SRC_DIR=src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
GTKMMLIBS=`pkg-config gtkmm-4.0 --cflags --libs`
BIN_DIR=bin
OUTPUT=lainOS
PREFIX := /usr/local

lainOS: $(SRC_FILES)
	mkdir -p bin
	$(CC) $^ --std="c++17" -o $(BIN_DIR)/$@ $(GTKMMLIBS)

install: 
	install -m 777 $(BIN_DIR)/$(OUTPUT) $(DESTDIR)$(PREFIX)/bin/
	install -m 777 media/a.svg $(DESTDIR)/usr/share/icons/
	install -m 777 media/b.png $(DESTDIR)/usr/share/icons/
	install -m 777 media/c.png $(DESTDIR)/usr/share/icons/
	install -m 777 media/d.png $(DESTDIR)/usr/share/icons/
	install -m 777 lainos.desktop $(DESTDIR)/usr/share/

