# Select your compiler
CC=g++
 
# The objects. To add another file,
# just add the filename with a .o extension.
OBJECTS=APBAnimation.o APBEvent.o  APBDisplay.o APBSprite.o  APBSpriteManager.o  APBSurface.o  APBApp.o TestGame.o
 
# Flags for C projects
CFLAGS=-Wall -g `sdl-config --cflags`
 
# Flags for C++ projects
CPPFLAGS=-Wall -g `sdl-config --cflags`
 
# For linking
LDFLAGS=`sdl-config --libs`
LIBS=-L/usr/lib -lSDLmain -lSDL -lSDL_image -lm
 
testGame: test_game/TestGame.cpp others
	$(CC) $(CPPFLAGS) -c test_game/TestGame.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) $(LIBS) -o testGame
 
others: engine/APBAnimation.cpp engine/APBEvent.cpp engine/APBDisplay.cpp engine/APBSprite.cpp engine/APBSpriteManager.cpp engine/APBSurface.cpp engine/APBApp.cpp test_game/TestGame.cpp            
	$(CC) $(CPPFLAGS) -c engine/APBAnimation.cpp engine/APBEvent.cpp engine/APBDisplay.cpp engine/APBSprite.cpp engine/APBSpriteManager.cpp  engine/APBSurface.cpp engine/APBApp.cpp test_game/TestGame.cpp
 
# cleanup
clean:
	rm -fr testGame $(OBJECTS)
