# Select your compiler
CC=g++
 
# The objects. To add another file,
# just add the filename with a .o extension.
OBJECTS=APBAnimation.o  APBApp.o  APBEvent.o  APBSprite.o  APBSpriteManager.o  APBSurface.o  main.o
 
# Flags for C projects
CFLAGS=-Wall -g `sdl-config --cflags`
 
# Flags for C++ projects
CPPFLAGS=-Wall -g `sdl-config --cflags`
 
# For linking
LDFLAGS=`sdl-config --libs`
LIBS=-L/usr/lib -lSDLmain -lSDL -lSDL_image -lm
 
main: main.cpp others            
	$(CC) $(CPPFLAGS) -c main.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) $(LIBS) -o testGame
 
others: APBAnimation.cpp APBApp.cpp APBEvent.cpp APBSprite.cpp APBSpriteManager.cpp APBSurface.cpp main.cpp            
	$(CC) $(CPPFLAGS) -c APBAnimation.cpp  APBApp.cpp  APBEvent.cpp  APBSprite.cpp  APBSpriteManager.cpp  APBSurface.cpp  main.cpp
 
# cleanup
clean:
	rm -fr main $(OBJECTS)
