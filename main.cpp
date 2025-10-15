#include "Figure.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FigureArray figureArray;
    int key;
    std::cout << "Лабораторная работа номер 3, вариант 33"<< std::endl;
    while (true) {
        std::cout << "\n Меню: " << std::endl;
        std::cout << "1 добавить фигуру" << std::endl;
        std::cout << "2 удалить фигуру по индексу" << std::endl;
        std::cout << "3 показать все фигуры" << std::endl;
        std::cout << "4 вычислить общую площадь" << std::endl;
        std::cout << "5 Bыход" << std::endl;
        std::cout << "выберите действие: " << std::endl;
        std::cin >> key;
        
        switch (key) {
            case 1: {
                std::cout << "Выберите тип фигуры: " << std::endl;
                std::cout << "1-Треугольник " << std::endl;
                std::cout << "2-Квадрат "<< std::endl;
                std::cout << "3-Прямоугольник " << std::endl;
                std::cout << "Ваш выбор: " << std::endl;
                int figureType;
                std::cin >> figureType;
                
                auto figure=createFig(figureType);
                if (figure) {
                    std::cin >> *figure;
                    figureArray.addFig(std::move(figure));
                    std::cout << "фигура добавлена!" << std::endl;
                } 
                else {
                    std::cout << "error: неверный выбор фигуры" << std::endl;
                }
                break;
            }
            case 2: {
                if (figureArray.size()==0) {
                    std::cout << "Mассив фигур пуст" << std::endl;;
                    break;
                }
                std::cout << "Bведите индекс фигуры для удаления (1-" << figureArray.size() << "): ";
                int index;
                std::cin >> index;
                figureArray.removeFig(index-1);
                std::cout << "фигура успешно удалена" << std::endl;
                break;
            }
            case 3: {
                if (figureArray.size()==0) {
                    std::cout << "Mассив фигур пуст" << std::endl;
                } 
                else {
                    figureArray.printAll();
                }
                break;
            }
            case 4: {
                double totalArea=figureArray.getTotalArea();
                std::cout << "0бщая площадь фигур: " << totalArea << std::endl;
                break;
            }
            case 5:
                std::cout << "Выход из программы" << std::endl;
                return 0;
            default:
                std::cout << "error: Hеверный выбор" << std::endl;
        }
    }
    return 0;
}