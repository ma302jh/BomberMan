#include "Block.h"

Block::Block(int _t, int _x, int _y, int _w, int _h): destruct(_t), Sprites("blocks.png", 1, 2){

    setXY(_x, _y);
    setWH( _w, _h);
    setPos(getPosX(), getPosY());
    setMarked(false);
}

bool Block::getType(){

    return destruct;
}

sf::Sprite Block::returnBlock(bool _b){

    return frames[_b];
}

void Block::setType(bool _b){

    destruct = _b;
}

// a marked block is a block set to be removed carefully as it will sit in an array of pointers
void Block::setMarked(bool _m){

    marked = _m;
}

bool Block::getMarked(){

    return marked;
}
