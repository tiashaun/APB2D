# Select your compiler
CC=g++
 
# The objects. To add another file,
# just add the filename with a .o extension.
OBJECTS=APBAnimation.o APBEvent.o  APBDisplay.o APBSprite.o  APBSpriteManager.o  APBSurface.o  APBApp.o TestGame.o
 
# Includes
INCLUDEDIRS = \
	-Isrc/test_game/ \
	-Isrc/engine/ \

# Flags for C projects
CFLAGS=-Wall -g `sdl-config --cflags`
 
# Flags for C++ projects
CPPFLAGS=-Wall -g `sdl-config --cflags` $(INCLUDEDIRS)
 
# For linking
LDFLAGS=`sdl-config --libs`
LIBS=-L/usr/lib -lSDLmain -lSDL -lSDL_image -lm
 
testGame: src/test_game/*.cpp others
	$(CC) $(CPPFLAGS) -c src/test_game/*.cpp
	$(CC) $(OBJECTS) $(CPPFLAGS) $(LDFLAGS) $(LIBS) -o testGame
 
others: src/engine/*.cpp src/test_game/*.cpp            
	$(CC) $(CPPFLAGS) -c src/engine/*.cpp src/test_game/*.cpp
 
# cleanup
clean:
	rm -fr testGame $(OBJECTS)
