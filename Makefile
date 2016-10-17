#Makefile for BlockTowerGA program, which utilizes the Polycode game engine for graphics and input.  

#compiler
CC=g++

#directory of Polycode framework
POLYDIR=$(HOME)/Polycode/Release/Linux/Framework/

#compiler flags for include directories
CFLAGS=-I$(POLYDIR)Core/Dependencies/include -I$(POLYDIR)Core/Dependencies/include/AL -I$(POLYDIR)Core/Dependencies/include/freetype2 -I$(POLYDIR)Core/include/ -I$(POLYDIR)Modules/include -I$(POLYDIR)Modules/Dependencies/include -I$(POLYDIR)Modules/Dependencies/include/bullet -g

#linker flags for library directories
LDFLAGS=-lrt -ldl -lpthread $(POLYDIR)Core/lib/libPolycore.a $(POLYDIR)Core/Dependencies/lib/libfreetype.a $(POLYDIR)Core/Dependencies/lib/liblibvorbisfile.a $(POLYDIR)Core/Dependencies/lib/liblibvorbis.a $(POLYDIR)Core/Dependencies/lib/liblibogg.a $(POLYDIR)Core/Dependencies/lib/libopenal.so $(POLYDIR)Core/Dependencies/lib/libphysfs.a $(POLYDIR)Core/Dependencies/lib/libpng15.a $(POLYDIR)Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL $(POLYDIR)Modules/lib/libPolycode2DPhysics.a $(POLYDIR)Modules/Dependencies/lib/libBox2D.a $(POLYDIR)Modules/lib/libPolycode3DPhysics.a $(POLYDIR)Modules/Dependencies/lib/libBulletDynamics.a $(POLYDIR)Modules/Dependencies/lib/libBulletCollision.a $(POLYDIR)Modules/Dependencies/lib/libLinearMath.a -lX11

#LDFLAGS=-lrt -ldl -lpthread -L$(POLYDIR)Core/lib/ -L$(POLYDIR)Core/Dependencies/lib/ -lGL -lGLU -lSDL -L$(POLYDIR)Modules/lib/ -L$(POLYDIR)Modules/Dependencies/lib/ -lX11


default: BlockTower

clean:
	rm BlockTower

BlockTower:
	@$(CC) $(CFLAGS) main.cpp BlockTowerApp.cpp -o BlockTower $(LDFLAGS)
