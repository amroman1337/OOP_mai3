#include "figure.h"
#include <sstream>
#include <gtest/gtest.h>

// тесты для Triangle
TEST(TriangleTest, DefaultConstructor) {
    Triangle t;
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(t.getArea(), 0.0);
}

TEST(TriangleTest, ParameterizedConstructor) {
    Triangle t(3.0, 1.0, 2.0);
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_NEAR(t.getArea(), 3.897114, 0.0001);
}

TEST(TriangleTest, CopyConstructor) {
    Triangle t1(3.0, 1.0, 2.0);
    Triangle t2(t1);
    
    auto center1 = t1.getCenter();
    auto center2 = t2.getCenter();
    EXPECT_DOUBLE_EQ(center1.first, center2.first);
    EXPECT_DOUBLE_EQ(center1.second, center2.second);
    EXPECT_DOUBLE_EQ(t1.getArea(), t2.getArea());
}

TEST(TriangleTest, AssignmentOperator) {
    Triangle t1(3.0, 1.0, 2.0);
    Triangle t2;
    t2 = t1;
    
    auto center1 = t1.getCenter();
    auto center2 = t2.getCenter();
    EXPECT_DOUBLE_EQ(center1.first, center2.first);
    EXPECT_DOUBLE_EQ(center1.second, center2.second);
    EXPECT_DOUBLE_EQ(t1.getArea(), t2.getArea());
}

TEST(TriangleTest, MoveConstructor) {
    Triangle t1(3.0, 1.0, 2.0);
    double area = t1.getArea();
    Triangle t2(std::move(t1));
    
    auto center = t2.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_DOUBLE_EQ(t2.getArea(), area);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle t1(3.0, 1.0, 2.0);
    Triangle t2(3.0, 1.0, 2.0);
    Triangle t3(4.0, 1.0, 2.0);
    
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(TriangleTest, DoubleConversion) {
    Triangle t(2.0, 0.0, 0.0);
    double area = static_cast<double>(t);
    EXPECT_NEAR(area, 1.73205, 0.0001);
}

// тесты для Square
TEST(SquareTest, DefaultConstructor) {
    Square s;
    auto center = s.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 0.0);
}

TEST(SquareTest, ParameterizedConstructor) {
    Square s(4.0, 2.0, 3.0);
    auto center = s.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 16.0);
}

TEST(SquareTest, CopyConstructor) {
    Square s1(4.0, 2.0, 3.0);
    Square s2(s1);
    
    auto center1 = s1.getCenter();
    auto center2 = s2.getCenter();
    EXPECT_DOUBLE_EQ(center1.first, center2.first);
    EXPECT_DOUBLE_EQ(center1.second, center2.second);
    EXPECT_DOUBLE_EQ(s1.getArea(), s2.getArea());
}

TEST(SquareTest, EqualityOperator) {
    Square s1(4.0, 2.0, 3.0);
    Square s2(4.0, 2.0, 3.0);
    Square s3(5.0, 2.0, 3.0);
    
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

// тесты для Rectangle
TEST(RectangleTest, DefaultConstructor) {
    Rectangle r;
    auto center = r.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(r.getArea(), 0.0);
}

TEST(RectangleTest, ParameterizedConstructor) {
    Rectangle r(5.0, 3.0, 2.0, 1.0);
    auto center = r.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
    EXPECT_DOUBLE_EQ(r.getArea(), 15.0);
}

TEST(RectangleTest, CopyConstructor) {
    Rectangle r1(5.0, 3.0, 2.0, 1.0);
    Rectangle r2(r1);
    
    auto center1 = r1.getCenter();
    auto center2 = r2.getCenter();
    EXPECT_DOUBLE_EQ(center1.first, center2.first);
    EXPECT_DOUBLE_EQ(center1.second, center2.second);
    EXPECT_DOUBLE_EQ(r1.getArea(), r2.getArea());
}

TEST(RectangleTest, EqualityOperator) {
    Rectangle r1(5.0, 3.0, 2.0, 1.0);
    Rectangle r2(5.0, 3.0, 2.0, 1.0);
    Rectangle r3(6.0, 3.0, 2.0, 1.0);
    
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}


// тесты для FigureArray
TEST(FigureArrayTest, AddAndRemoveFigures) {
    FigureArray array;
    array.addFigure(std::make_unique<Triangle>(3.0, 0.0, 0.0));
    array.addFigure(std::make_unique<Square>(4.0, 1.0, 1.0));
    array.addFigure(std::make_unique<Rectangle>(5.0, 3.0, 2.0, 2.0));
    
    EXPECT_EQ(array.size(), 3);
    array.removeFigure(1);
    EXPECT_EQ(array.size(), 2);
    
    Figure* fig = array.getFigure(0);
    EXPECT_NE(fig, nullptr);
    EXPECT_NEAR(fig->getArea(), 3.897114, 0.0001);
}

TEST(FigureArrayTest, TotalAreaCalculation) {
    FigureArray array;
    
    array.addFigure(std::make_unique<Triangle>(2.0, 0.0, 0.0)); // ~1.732
    array.addFigure(std::make_unique<Square>(2.0, 0.0, 0.0));    // 4.0
    array.addFigure(std::make_unique<Rectangle>(3.0, 2.0, 0.0, 0.0)); // 6.0
    
    double totalArea = array.getTotalArea();
    EXPECT_NEAR(totalArea, 11.732, 0.001);
}

TEST(FigureArrayTest, EmptyArray) {
    FigureArray array;
    
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.getTotalArea(), 0.0);
    EXPECT_EQ(array.getFigure(0), nullptr);
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, InvalidIndexAccess) {
    FigureArray array;
    array.addFigure(std::make_unique<Triangle>(3.0, 0.0, 0.0));
    EXPECT_EQ(array.getFigure(-1), nullptr);
    EXPECT_EQ(array.getFigure(1), nullptr);
    EXPECT_NE(array.getFigure(0), nullptr);
}

// тесты для создания фигур
TEST(CreateFigureTest, ValidTypes) {
    auto triangle = createFigure(1);
    auto square = createFigure(2);
    auto rectangle = createFigure(3);
    
    EXPECT_NE(triangle, nullptr);
    EXPECT_NE(square, nullptr);
    EXPECT_NE(rectangle, nullptr);
    
    EXPECT_NE(dynamic_cast<Triangle*>(triangle.get()), nullptr);
    EXPECT_NE(dynamic_cast<Square*>(square.get()), nullptr);
    EXPECT_NE(dynamic_cast<Rectangle*>(rectangle.get()), nullptr);
}

TEST(CreateFigureTest, InvalidType) {
    auto invalid = createFigure(0);
    auto invalid2 = createFigure(4);
    
    EXPECT_EQ(invalid, nullptr);
    EXPECT_EQ(invalid2, nullptr);
}

// тесты для полиморфизма
TEST(PolymorphismTest, FigurePointerOperations) {
    std::unique_ptr<Figure> triangle = std::make_unique<Triangle>(3.0, 1.0, 2.0);
    std::unique_ptr<Figure> square = std::make_unique<Square>(4.0, 2.0, 3.0);
    std::unique_ptr<Figure> rectangle = std::make_unique<Rectangle>(5.0, 3.0, 3.0, 4.0);

    auto center_t = triangle->getCenter();
    auto center_s = square->getCenter();
    auto center_r = rectangle->getCenter();
    
    EXPECT_DOUBLE_EQ(center_t.first, 1.0);
    EXPECT_DOUBLE_EQ(center_t.second, 2.0);
    EXPECT_DOUBLE_EQ(center_s.first, 2.0);
    EXPECT_DOUBLE_EQ(center_s.second, 3.0);
    EXPECT_DOUBLE_EQ(center_r.first, 3.0);
    EXPECT_DOUBLE_EQ(center_r.second, 4.0);

    double area_t = static_cast<double>(*triangle);
    double area_s = static_cast<double>(*square);
    double area_r = static_cast<double>(*rectangle);
    
    EXPECT_NEAR(area_t, 3.897114, 0.0001);
    EXPECT_DOUBLE_EQ(area_s, 16.0);
    EXPECT_DOUBLE_EQ(area_r, 15.0);
}


TEST(FigureTypesTest, DifferentTypesNotEqual) {
    Triangle triangle(3.0, 1.0, 2.0);
    Square square(3.0, 1.0, 2.0);
    Rectangle rectangle(3.0, 3.0, 1.0, 2.0);
    EXPECT_FALSE(triangle == square);
    EXPECT_FALSE(triangle == rectangle);
    EXPECT_FALSE(square == rectangle);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}