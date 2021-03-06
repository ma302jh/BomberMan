#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include "ImageLoader.h"

// The sprite class takes an image on creation, it then slices this image
// up and adds the sub images in the form of sprites initialized with a texture
// object onto an array list called frames.  Image loading class has been added to reduce overhead.
class Sprites{

    public:

        //constructor
        Sprites(std::string );

        //overload constructor for frames
        Sprites(std::string , int , int );

        //destructor
        ~Sprites();

        //pointer to self for deep copy of base class
        Sprites *sp_copy;

        //rows and cols for contact sheet frames, frame for what frame is presently on,
        //idle displays frame chosen to show static image to display no movement,
        //start and stopFrame are to loop only within certain frames
        int rows, cols, frame, idle, total_frames , startFrame;

        //Sprite object not Sprites object :/ ...must change name
        sf::Sprite sprite;

        //this vector will store an array of sprites that will each be part of an animation
        std::vector <sf::Sprite> frames;

        void loopMode(int, int);

        int getFrameCount();

        void loopMode(bool, int, int);

        bool setImage();

        void setSprite();

        void addFrames();

        bool collission(Sprites *);

        void setPosX(int);

        void setPosY(int);

        sf::Sprite getNext();

        void nextFrame();

        void idleFrame();

        void movePos(bool, int, int);

        sf::Sprite showFrame();

        void setXY(int, int);

        int getPosX();

        int getPosY();

        void setWidth(int);

        void setHeight(int);

        void setWH(int, int);

        int getWidth();

        int getHeight();

        void setCollide(bool);

        bool getCollide();

        void setPos(int, int);

        void destroy();

         //returns true if time in args has passed since last call
        bool getTicks(double);

        std::clock_t startTime;

        int getStoredX();
        int getStoredY();

        void setStoredX(int);
        void setStoredY(int);

        //shades the sprite colour at args rgb
        void colorSprite(int, int, int);

        //stores events so new instance does not have to be regularly made each loop
        sf::Event event;

        //image loader object
        ImageLoader iLoad;

         //texture file for initialising sprite with, needs to be public for splash screen
        sf::Texture tex;


    private:

        //path string will contain location of image to load on to cntSheet
        std::string path;

        //dimensions of the sprite or all frames of the sprite as a whole, this is for collisions or movement
        int posX, posY, sWidth, sHeight, storedX ,storedY;

        bool colliding;
};

#endif // SPRITE_H
