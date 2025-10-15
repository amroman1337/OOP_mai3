#include "Figure.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FigureArray arr;
    int key;
    std::cout << "Лабораторная работа номер 3, вариант 33"<< std::endl;
    while (true) {
        std::cout << "\n Меню: " << std::endl;
        std::cout << "добавить фигуру - 1" << std::endl;
        std::cout << "удалить фигуру по индексу - 2" << std::endl;
        std::cout << "показать все фигуры - 3" << std::endl;
        std::cout << "вычислить общую площадь - 4" << std::endl;
        std::cout << "Bыход - 5" << std::endl;
        std::cout << "выберите действие: " << std::endl;
        std::cin >> key;
        
        switch (key) {
            case 1: {
                int f;
                std::cout << "Bыберите тип фигуры " << std::endl;
                std::cout << "1-Треугольник " << std::endl;
                std::cout << "2-Квадрат "<< std::endl;
                std::cout << "3-Прямоугольник " << std::endl;
                std::cout << "Ваш выбор: " << std::endl;
                std::cin >> f;
                
                auto fig=createFig(f);
                if (fig) {
                    std::cin >> *fig;
                    arr.addFig(std::move(fig));
                    std::cout << "фигура добавлена!" << std::endl;
                } 
                else {
                    std::cout << "error: неверный выбор фигуры" << std::endl;
                }
                break;
            }
            case 2: {
                int i;
                if (arr.size()==0) {
                    std::cout << "Mассив фигур пуст" << std::endl;;
                    break;
                }
                std::cout << "Bведите индекс фигуры для удаления (1-" << arr.size() << "): ";
                std::cin >> i;
                arr.removeFig(i-1);
                std::cout << "фигура успешно удалена" << std::endl;
                break;
            }
            case 3: {
                if (arr.size()==0) {
                    std::cout << "Mассив фигур пуст" << std::endl;
                } 
                else {
                    arr.printAll();
                }
                break;
            }
            case 4: {
                double totalArea=arr.getTotalArea();
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