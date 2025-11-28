#include "RGB.h"

RGB::RGB(int rr, int gg, int bb) {
    
}

RGB::~RGB() {

}

int RGB::getR() const {
    return Red;
}

int RGB::getG() const {
    return Green;
}

int RGB::getB() const {
    return Blue;
}

void RGB::setR(int rr) {
    this->Red = rr;
}

void RGB::setG(int gg) {
    this->Green = gg;
}

void RGB::setB(int bb) {
    this->Blue = bb;
}
