#pragma once

class RGB {
private:
    int Red, Green, Blue;
    int saturar(int v, int lo, int hi) {
        if (v < lo) {
            return lo;
        }
        if (v > hi) {
            return hi;
        }
        return v;
    }

public:
    // Constructor
    RGB(int rr = 0, int gg = 0, int bb = 0);

    // destrcutor
    ~RGB();

    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int rr);
    void setG(int gg);
    void setB(int bb);
    void ajustar(int delta);
    bool operator==(const RGB& otroRgb) const;
};