#include "RGB.h"

RGB::RGB(int rr, int gg, int bb) {
    Red = saturar(rr, 0, 255);
    Green = saturar(gg, 0, 255);
    Blue = saturar(bb, 0, 255);
}


RGB::~RGB() {}

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

void RGB::ajustar(int delta) {
    Red = saturar(Red + delta, 0, 255);
    Green = saturar(Green + delta, 0, 255);
    Blue = saturar(Blue + delta, 0, 255);
}

bool RGB::operator==(const RGB& otroRgb) const {
    return (Red == otroRgb.Red && Green == otroRgb.Green && Blue == otroRgb.Blue);
}
