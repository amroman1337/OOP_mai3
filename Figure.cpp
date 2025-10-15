#include "Figure.h"

Figure::operator double() const {
    return getArea();
}

bool Figure::operator==(const Figure& other) const {
    return equals(&other);
}

Triangle::Triangle() : side(0), centerX(0), centerY(0) {}

Triangle::Triangle(double s, double x, double y): side(s), centerX(x), centerY(y) {}

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
    return (sqrt(3) / 4) * side * side;
}

void Triangle::printVertices(std::ostream& os) const {
    double height = (sqrt(3) / 2) * side;
    double r = height * 2 / 3;
    os << "Bершины треугольника: " << std::endl;
    os << "1 (" << centerX << ", " << centerY + r << ")" << std::endl;
    os << "2 (" << centerX - side/2 << ", " << centerY - r/2 << ")" << std::endl;
    os << "3 (" << centerX + side/2 << ", " << centerY - r/2 << ")" << std::endl;
}

void Triangle::readData(std::istream& is) {
    std::cout << "Введите длину стороны треугольника: ";
    is >> side;
    std::cout << "Введите координаты центра (x;y): ";
    is >> centerX >> centerY;
}

std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}

bool Triangle::equals(const Figure* other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(other);
    if (!t) return false;
    return side == t->side && centerX == t->centerX && centerY == t->centerY;
}




Square::Square() : side(0), centerX(0), centerY(0) {}

Square::Square(double s, double x, double y) : side(s), centerX(x), centerY(y) {}

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

void Square::printVertices(std::ostream& os) const {
    double halfSide = side / 2;
    os << "Вершины квадрата:" << std::endl;
    os << "1 (" << centerX - halfSide << ", " << centerY - halfSide << ")" << std::endl;
    os << "2 (" << centerX + halfSide << ", " << centerY - halfSide << ")" << std::endl;
    os << "3 (" << centerX + halfSide << ", " << centerY + halfSide << ")" << std::endl;
    os << "4 (" << centerX - halfSide << ", " << centerY + halfSide << ")" << std::endl;
}

void Square::readData(std::istream& is) {
    std::cout << "Введите значение стороны квадрата: ";
    is >> side;
    std::cout << "Введите координаты центра (x;y): ";
    is >> centerX >> centerY;
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

bool Square::equals(const Figure* other) const {
    const Square* s = dynamic_cast<const Square*>(other);
    if (!s) return false;
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

void Rectangle::printVertices(std::ostream& os) const {
    double halfWidth = width / 2;
    double halfHeight = height / 2;
    os << "Вершины прямоугольника:" << std::endl;
    os << "1 (" << centerX - halfWidth << ", " << centerY - halfHeight << ")" << std::endl;
    os << "2 (" << centerX + halfWidth << ", " << centerY - halfHeight << ")" << std::endl;
    os << "3 (" << centerX + halfWidth << ", " << centerY + halfHeight << ")" << std::endl;;
    os << "4 (" << centerX - halfWidth << ", " << centerY + halfHeight << ")" << std::endl;
}

void Rectangle::readData(std::istream& is) {
    std::cout << "Введите ширину прямоугольника: ";
    is >> width;
    std::cout << "Введите высоту прямоугольника: ";
    is >> height;
    std::cout << "Введите координаты центра (x y): ";
    is >> centerX >> centerY;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

bool Rectangle::equals(const Figure* other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(other);
    if (!r) return false;
    return width == r->width && height == r->height && 
           centerX == r->centerX && centerY == r->centerY;
}


std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    figure.readData(is);
    return is;
}

void FigureArray::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

size_t FigureArray::size() const {
    return figures.size();
}

Figure* FigureArray::getFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        return figures[index].get();
    }
    return nullptr;
}

double FigureArray::getTotalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += figure->getArea();
    }
    return total;
}

void FigureArray::printAll() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        auto center = figures[i]->getCenter();
        std::cout << "Центр: (" << center.first << ", " << center.second << ")" << std::endl;
        std::cout << "Площадь: " << figures[i]->getArea() << std::endl;
        std::cout << *figures[i]<< std::endl;
    }
}

std::unique_ptr<Figure> createFigure(int choice) {
    switch (choice) {
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