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
    virtual void printVertices(std::ostream& output) const = 0;
    virtual void readData(std::istream& input) = 0;
    virtual operator double() const;
    virtual std::unique_ptr<Figure> clone() const = 0;
    virtual bool equals(const Figure* other) const = 0;
    bool operator==(const Figure& other) const;
};


class Triangle : public Figure {
private:
    double side;
    double centerX, centerY;
public:
    Triangle();
    Triangle(double s, double x, double y);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;

    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& output) const override;
    void readData(std::istream& input) override;
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
};

class Square : public Figure {
private:
    double side;
    double centerX, centerY;
public:
    Square();
    Square(double s, double x, double y);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& output) const override;
    void readData(std::istream& input) override;
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
};

class Rectangle : public Figure {
private:
    double width, height;
    double centerX, centerY;
public:
    Rectangle();
    Rectangle(double w, double h, double x, double y);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices(std::ostream& output) const override;
    void readData(std::istream& input) override;
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
};

std::ostream& operator<<(std::ostream& output, const Figure& figure);
std::istream& operator>>(std::istream& input, Figure& figure);

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;
public:
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(int index);
    
    size_t size() const;
    Figure* getFigure(int index);
    
    double getTotalArea() const;
    void printAll() const;
};

std::unique_ptr<Figure> createFigure(int choice);