#include "figure.h"
#include <sstream>
#include <gtest/gtest.h>

// Triangle test cases
class TriangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        default_triangle = std::make_unique<Triangle>();
        param_triangle = std::make_unique<Triangle>(3.0, 1.0, 2.0);
    }
    
    std::unique_ptr<Triangle> default_triangle;
    std::unique_ptr<Triangle> param_triangle;
};

TEST_F(TriangleTest, NewInstanceHasZeroCenterAndArea) {
    auto center = default_triangle->getCenter();
    ASSERT_DOUBLE_EQ(center.first, 0.0);
    ASSERT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(default_triangle->getArea(), 0.0);
}

TEST_F(TriangleTest, ParameterizedConstructionSetsCorrectProperties) {
    auto center = param_triangle->getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_NEAR(param_triangle->getArea(), 3.897114, 0.0001);
}

TEST_F(TriangleTest, CopyCreatesIdenticalInstance) {
    Triangle copied(*param_triangle);
    
    auto original_center = param_triangle->getCenter();
    auto copied_center = copied.getCenter();
    EXPECT_DOUBLE_EQ(original_center.first, copied_center.first);
    EXPECT_DOUBLE_EQ(original_center.second, copied_center.second);
    EXPECT_DOUBLE_EQ(param_triangle->getArea(), copied.getArea());
}

TEST_F(TriangleTest, AssignmentOperatorMakesEqualCopy) {
    Triangle assigned;
    assigned = *param_triangle;
    
    auto original_center = param_triangle->getCenter();
    auto assigned_center = assigned.getCenter();
    EXPECT_DOUBLE_EQ(original_center.first, assigned_center.first);
    EXPECT_DOUBLE_EQ(original_center.second, assigned_center.second);
    EXPECT_DOUBLE_EQ(param_triangle->getArea(), assigned.getArea());
}

TEST_F(TriangleTest, MoveOperationTransfersState) {
    double original_area = param_triangle->getArea();
    Triangle moved(std::move(*param_triangle));
    
    auto center = moved.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_DOUBLE_EQ(moved.getArea(), original_area);
}

TEST_F(TriangleTest, IdenticalTrianglesAreEqual) {
    Triangle another(3.0, 1.0, 2.0);
    Triangle different(4.0, 1.0, 2.0);
    
    EXPECT_TRUE(*param_triangle == another);
    EXPECT_FALSE(*param_triangle == different);
}

TEST_F(TriangleTest, DoubleConversionReturnsArea) {
    Triangle t(2.0, 0.0, 0.0);
    double area_value = static_cast<double>(t);
    EXPECT_NEAR(area_value, 1.73205, 0.0001);
}

// Square test cases
TEST(SquareTest, DefaultSquareHasOriginCenterAndZeroArea) {
    Square s;
    auto center = s.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 0.0);
}

TEST(SquareTest, SquareWithParametersComputesCorrectArea) {
    Square s(4.0, 2.0, 3.0);
    auto center = s.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 16.0);
}

TEST(SquareTest, SquareCopyPreservesAllAttributes) {
    Square original(4.0, 2.0, 3.0);
    Square copy(original);
    
    auto orig_center = original.getCenter();
    auto copy_center = copy.getCenter();
    EXPECT_DOUBLE_EQ(orig_center.first, copy_center.first);
    EXPECT_DOUBLE_EQ(orig_center.second, copy_center.second);
    EXPECT_DOUBLE_EQ(original.getArea(), copy.getArea());
}

TEST(SquareTest, EqualSquaresReturnTrueForEquality) {
    Square first(4.0, 2.0, 3.0);
    Square second(4.0, 2.0, 3.0);
    Square different(5.0, 2.0, 3.0);
    
    EXPECT_TRUE(first == second);
    EXPECT_FALSE(first == different);
}

// Rectangle test cases
TEST(RectangleTest, NewRectangleInitializesToZero) {
    Rectangle r;
    auto center = r.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
    EXPECT_DOUBLE_EQ(r.getArea(), 0.0);
}

TEST(RectangleTest, RectangleAreaCalculationIsCorrect) {
    Rectangle r(5.0, 3.0, 2.0, 1.0);
    auto center = r.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
    EXPECT_DOUBLE_EQ(r.getArea(), 15.0);
}

TEST(RectangleTest, RectangleCopyMaintainsIntegrity) {
    Rectangle original(5.0, 3.0, 2.0, 1.0);
    Rectangle replica(original);
    
    auto orig_center = original.getCenter();
    auto replica_center = replica.getCenter();
    EXPECT_DOUBLE_EQ(orig_center.first, replica_center.first);
    EXPECT_DOUBLE_EQ(orig_center.second, replica_center.second);
    EXPECT_DOUBLE_EQ(original.getArea(), replica.getArea());
}

TEST(RectangleTest, RectangleEqualityCheckWorks) {
    Rectangle rect1(5.0, 3.0, 2.0, 1.0);
    Rectangle rect2(5.0, 3.0, 2.0, 1.0);
    Rectangle rect3(6.0, 3.0, 2.0, 1.0);
    
    EXPECT_TRUE(rect1 == rect2);
    EXPECT_FALSE(rect1 == rect3);
}

// Figure collection tests
TEST(FigureCollectionTest, AddAndRemoveOperationsWork) {
    FigureArray collection;
    
    collection.addFigure(std::make_unique<Triangle>(3.0, 0.0, 0.0));
    collection.addFigure(std::make_unique<Square>(4.0, 1.0, 1.0));
    collection.addFigure(std::make_unique<Rectangle>(5.0, 3.0, 2.0, 2.0));
    
    EXPECT_EQ(collection.size(), 3);
    
    collection.removeFigure(1);
    ASSERT_EQ(collection.size(), 2);
    
    Figure* figure = collection.getFigure(0);
    EXPECT_NE(figure, nullptr);
    EXPECT_NEAR(figure->getArea(), 3.897114, 0.0001);
}

TEST(FigureCollectionTest, TotalAreaAggregation) {
    FigureArray collection;
    
    collection.addFigure(std::make_unique<Triangle>(2.0, 0.0, 0.0));
    collection.addFigure(std::make_unique<Square>(2.0, 0.0, 0.0));
    collection.addFigure(std::make_unique<Rectangle>(3.0, 2.0, 0.0, 0.0));
    
    double total = collection.getTotalArea();
    EXPECT_NEAR(total, 11.732, 0.001);
}

TEST(FigureCollectionTest, EmptyCollectionBehavior) {
    FigureArray empty;
    
    EXPECT_EQ(empty.size(), 0);
    EXPECT_EQ(empty.getTotalArea(), 0.0);
    EXPECT_EQ(empty.getFigure(0), nullptr);
    
    empty.removeFigure(0); // Should not crash
    EXPECT_EQ(empty.size(), 0);
}

TEST(FigureCollectionTest, InvalidIndexHandling) {
    FigureArray collection;
    collection.addFigure(std::make_unique<Triangle>(3.0, 0.0, 0.0));
    
    EXPECT_EQ(collection.getFigure(-1), nullptr);
    EXPECT_EQ(collection.getFigure(5), nullptr);
    EXPECT_NE(collection.getFigure(0), nullptr);
}

// Factory function tests
TEST(FigureFactoryTest, CreatesCorrectFigureTypes) {
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

TEST(FigureFactoryTest, InvalidTypeReturnsNull) {
    EXPECT_EQ(createFigure(0), nullptr);
    EXPECT_EQ(createFigure(99), nullptr);
}

// Polymorphism verification
TEST(PolymorphismTest, CommonInterfaceWorks) {
    std::unique_ptr<Figure> triangle = std::make_unique<Triangle>(3.0, 1.0, 2.0);
    std::unique_ptr<Figure> square = std::make_unique<Square>(4.0, 2.0, 3.0);
    std::unique_ptr<Figure> rectangle = std::make_unique<Rectangle>(5.0, 3.0, 3.0, 4.0);

    EXPECT_DOUBLE_EQ(triangle->getCenter().first, 1.0);
    EXPECT_DOUBLE_EQ(triangle->getCenter().second, 2.0);
    EXPECT_DOUBLE_EQ(square->getCenter().first, 2.0);
    EXPECT_DOUBLE_EQ(square->getCenter().second, 3.0);
    EXPECT_DOUBLE_EQ(rectangle->getCenter().first, 3.0);
    EXPECT_DOUBLE_EQ(rectangle->getCenter().second, 4.0);

    EXPECT_NEAR(static_cast<double>(*triangle), 3.897114, 0.0001);
    EXPECT_DOUBLE_EQ(static_cast<double>(*square), 16.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*rectangle), 15.0);
}

TEST(FigureComparisonTest, DifferentTypesAreNotEqual) {
    Triangle triangle(3.0, 1.0, 2.0);
    Square square(3.0, 1.0, 2.0);
    Rectangle rectangle(3.0, 3.0, 1.0, 2.0);
    
    EXPECT_FALSE(triangle == square);
    EXPECT_FALSE(triangle == rectangle);
    EXPECT_FALSE(square == rectangle);
}

int runTests(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int main(int argc, char **argv) {
    return runTests(argc, argv);
}