#ifndef RECTANGLE_H
#define RECTANGLE_H

class CRectangle {
private:
    int width, height;
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int getWidth() { return width; }
    int getHeight() { return height; }
    int area() { return width * height; }
};

#endif