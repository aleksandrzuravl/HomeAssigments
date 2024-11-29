/*zhuravlev alexander st129760
    assigment 2b
*/
#include <iostream> 
#include <sstream> 
#include <string> 
 
int MAX_SIZE = 100; // Максимальный размер массива 
 
int main() { 
    std::string input; 
    std::getline(std::cin, input); // Считываем всю строку ввода 
 
    std::istringstream iss(input); 
    int lenght = 10;
    double* sp = new double[lenght]; // Массив для хранения чисел и результатов 
    int size = 0; // Текущий размер массива 
 
    std::string token; 
    while (iss >> token) { // Разделяем строку на токены 
        if (token != "+" && token != "-" && token != "*" && token != "/") { 
            if (size == lenght) {
            	lenght *= 2; 
                double* nsp = new double[lenght]; 
                for (int i = 0; i < size; ++i) { 
                    nsp[i] = sp[i]; 
                } 
                delete[] sp; // Освобождаем старый массив 
                sp = nsp;
                }
            sp[size++] = std::stod(token); // Добавляем число в массив    
        } else { 
            if (size < 2) { 
                std::cout << "Not enough operands" << std::endl; 
                return 1; // Не хватает операндов 
            } 
            double op1 = sp[size - 1]; 
            double op2 = sp[size - 2]; 
            size -= 2; // Удаляем два последних операнда 
 
            if (token == "+") { 
                sp[size++] = op2 + op1; 
            } else if (token == "-") { 
                sp[size++] = op2 - op1; 
            } else if (token == "*") { 
                sp[size++] = op2 * op1; 
            } else if (token == "/") { 
                if (op1 == 0) { 
                    std::cout << "error" << std::endl; 
                    return 1; // Ошибка деления на ноль 
                } else { 
                    sp[size++] = op2 / op1; 
                } 
            } 
        } 
    } 
 
    if (size > 0) { 
        std::cout << sp[size - 1] << std::endl; // Выводим результат 
    } 
 
    return 0; 
}
