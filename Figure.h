#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual void printCoords(std::ostream& output) const = 0;
    virtual void readCoords(std::istream& input) = 0;
    virtual operator double() const;
    virtual std::unique_ptr<Figure> copyFig() const = 0;
    virtual bool equals(const Figure* other) const = 0;
    bool operator==(const Figure& other) const;
};


class Triangle : public Figure {
public:
    Triangle();
    Triangle(double s, double x, double y);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;

    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printCoords(std::ostream& output) const override;
    void readCoords(std::istream& input) override;
    std::unique_ptr<Figure> copyFig() const override;
    bool equals(const Figure* other) const override;
private:
    double side;
    double centerX, centerY;
};

class Square : public Figure {
public:
    Square();
    Square(double s, double x, double y);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printCoords(std::ostream& output) const override;
    void readCoords(std::istream& input) override;
    std::unique_ptr<Figure> copyFig() const override;
    bool equals(const Figure* other) const override;
private:
    double side;
    double centerX, centerY;
};

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double w, double h, double x, double y);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printCoords(std::ostream& output) const override;
    void readCoords(std::istream& input) override;
    std::unique_ptr<Figure> copyFig() const override;
    bool equals(const Figure* other) const override;
private:
    double width, height;
    double centerX, centerY;
};

class FigureArray {
public:
    void addFig(std::unique_ptr<Figure> figure);
    void removeFig(int index);
    size_t size() const;
    Figure* getFig(int index);
    double getTotalArea() const;
    void printAll() const;
private:
    std::vector<std::unique_ptr<Figure>> figures;
};

std::ostream& operator<<(std::ostream& output, const Figure& figure);
std::istream& operator>>(std::istream& input, Figure& figure);
std::unique_ptr<Figure> createFig(int choice);