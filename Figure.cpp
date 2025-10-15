#include "Figure.h"

Figure::operator double() const {
    return getArea();
}

bool Figure::operator==(const Figure& other) const {
    return equals(&other);
}

Triangle::Triangle() : side(0), centerX(0), centerY(0) {}

Triangle::Triangle(double SIDE, double x, double y): side(SIDE), centerX(x), centerY(y) {}

Triangle::Triangle(const Triangle& other):
    side(other.side), centerX(other.centerX), centerY(other.centerY) {}

Triangle::Triangle(Triangle&& other) noexcept:
    side(std::move(other.side)), 
    centerX(std::move(other.centerX)), 
    centerY(std::move(other.centerY)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        side = other.side;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        side = std::move(other.side);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
    }
    return *this;
}

std::pair<double, double> Triangle::getCenter() const {
    return {centerX, centerY};
}

double Triangle::getArea() const {
    return (sqrt(3)/4)*side*side;
}

void Triangle::printVertices(std::ostream& output) const {
    double height = (sqrt(3)/2)*side;
    double r = height*2/3;
    output << "Bершины треугольника: " << std::endl;
    output << "1 (" << centerX << ", " << centerY+r << ")" << std::endl;
    output << "2 (" << centerX-side/2 << ", " << centerY-r/2 << ")" << std::endl;
    output << "3 (" << centerX+side/2 << ", " << centerY-r/2 << ")" << std::endl;
}

void Triangle::readData(std::istream& input) {
    std::cout << "Введите сторону треугольника ";
    input >> side;
    std::cout << "Введите координаты центра (x;y) ";
    input >> centerX >> centerY;
}

std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}

bool Triangle::equals(const Figure* other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(other);
    if (!t) {
        return false;
    }
    return side == t->side && centerX == t->centerX && centerY == t->centerY;
}




Square::Square() : side(0), centerX(0), centerY(0) {}

Square::Square(double SIDE, double x, double y) : side(SIDE), centerX(x), centerY(y) {}

Square::Square(const Square& other):
    side(other.side), centerX(other.centerX), centerY(other.centerY) {}

Square::Square(Square&& other) noexcept:
    side(std::move(other.side)), 
    centerX(std::move(other.centerX)), 
    centerY(std::move(other.centerY)) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        side = other.side;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        side = std::move(other.side);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
    }
    return *this;
}

std::pair<double, double> Square::getCenter() const {
    return {centerX, centerY};
}

double Square::getArea() const {
    return side * side;
}

void Square::printVertices(std::ostream& output) const {
    double hS = side / 2;
    output << "Вершины квадрата:" << std::endl;
    output << "1 (" << centerX - hS << ", " << centerY - hS << ")" << std::endl;
    output << "2 (" << centerX + hS << ", " << centerY - hS << ")" << std::endl;
    output << "3 (" << centerX + hS << ", " << centerY + hS << ")" << std::endl;
    output << "4 (" << centerX - hS << ", " << centerY + hS << ")" << std::endl;
}

void Square::readData(std::istream& input) {
    std::cout << "Введите значение стороны квадрата: ";
    input >> side;
    std::cout << "Введите координаты центра (x;y): ";
    input >> centerX >> centerY;
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

bool Square::equals(const Figure* other) const {
    const Square* s = dynamic_cast<const Square*>(other);
    if (!s){
        return false;
    }
    return side == s->side && centerX == s->centerX && centerY == s->centerY;
}





Rectangle::Rectangle() : width(0), height(0), centerX(0), centerY(0) {}

Rectangle::Rectangle(double w, double h, double x, double y):
    width(w), height(h), centerX(x), centerY(y) {}

Rectangle::Rectangle(const Rectangle& other):
    width(other.width), height(other.height), 
    centerX(other.centerX), centerY(other.centerY) {}

Rectangle::Rectangle(Rectangle&& other) noexcept:
    width(std::move(other.width)), 
    height(std::move(other.height)),
    centerX(std::move(other.centerX)), 
    centerY(std::move(other.centerY)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        width = std::move(other.width);
        height = std::move(other.height);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
    }
    return *this;
}

std::pair<double, double> Rectangle::getCenter() const {
    return {centerX, centerY};
}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::printVertices(std::ostream& output) const {
    double hW = width/2;
    double hH = height/2;
    output << "вершины прямоугольника:" << std::endl;
    output << "1 (" << centerX-hW << ", " << centerY-hH << ")" << std::endl;
    output << "2 (" << centerX+hW << ", " << centerY-hH << ")" << std::endl;
    output << "3 (" << centerX+hW << ", " << centerY+hH << ")" << std::endl;;
    output << "4 (" << centerX-hW << ", " << centerY+hH << ")" << std::endl;
}

void Rectangle::readData(std::istream& input) {
    std::cout << "введите ширину прямоугольника ";
    input >> width;
    std::cout << "введите высоту прямоугольника ";
    input >> height;
    std::cout << "введите координаты центра (x y) ";
    input >> centerX >> centerY;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

bool Rectangle::equals(const Figure* other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(other);
    if (!r) {
        return false;
    }
    return width == r->width && height == r->height && centerX == r->centerX && centerY == r->centerY;
}

void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void FigureArray::removeFigure(int index) {
    if (index > -1 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

size_t FigureArray::size() const {
    return figures.size();
}

Figure* FigureArray::getFigure(int index) {
    if (index > -1 && index < figures.size()) {
        return figures[index].get();
    }
    return nullptr;
}

double FigureArray::getTotalArea() const {
    double res = 0;
    for (const auto& figure : figures) {
        res += figure->getArea();
    }
    return res;
}

void FigureArray::printAll() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "фигура " << i + 1 << ":" << std::endl;
        auto center = figures[i]->getCenter();
        std::cout << "центр: (" << center.first << ", " << center.second << ")" << std::endl;
        std::cout << "площадь: " << figures[i]->getArea() << std::endl;
        std::cout << *figures[i]<< std::endl;
    }
}

std::ostream& operator<<(std::ostream& output, const Figure& figure) {
    figure.printVertices(output);
    return output;
}

std::istream& operator>>(std::istream& input, Figure& figure) {
    figure.readData(input);
    return input;
}

std::unique_ptr<Figure> createFigure(int key) {
    switch (key) {
        case 1:
            return std::make_unique<Triangle>();
        case 2:
            return std::make_unique<Square>();
        case 3:
            return std::make_unique<Rectangle>();
        default:
            return nullptr;
    }
}