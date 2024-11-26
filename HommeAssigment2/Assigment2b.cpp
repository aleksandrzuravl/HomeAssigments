/*zhuravlev alexander st129760
    assigment 2b
*/
#include <iostream> 
#include <sstream> 
#include <string> 
 
int main() { 
    std::string input; 
    std::getline(std::cin, input); 
 
    const int MAX_SIZE = 100; // Максимальный размер стека 
    int stack[MAX_SIZE];       // Массив для хранения элементов стека 
    int top = -1;              // Индекс верхнего элемента стека 
    std::istringstream stream(input); 
    std::string token; 
 
    while (stream >> token) { 
        if (token != "+" && token != "-" && token != "*" && token != "/") { 
            // Преобразование строки в целое число и добавление в стек 
            if (top < MAX_SIZE - 1) { 
                stack[++top] = std::stoi(token); 
            } else { 
                std::cerr << "Stack overflow" << std::endl; 
                return 1; 
            } 
        } else { 
            // Проверка наличия достаточного количества элементов в стеке для выполнения операции 
            if (top < 1) { 
                std::cerr << "Not enough values in stack" << std::endl; 
                return 1; 
            } 
 
            int b = stack[top--]; // Последний элемент 
            int a = stack[top--]; // Предпоследний элемент 
 
            if (token == "+") { 
                stack[++top] = a + b; 
            } else if (token == "-") { 
                stack[++top] = a - b; 
            } else if (token == "*") { 
                stack[++top] = a * b; 
            } else if (token == "/") { 
                if (b == 0) { 
                    std::cout << "error" << std::endl; 
                    return 1; // Завершение программы с ошибкой 
                } else { 
                    stack[++top] = a / b; 
                } 
            } 
        } 
    } 
 
    // Вывод результата 
    if (top >= 0) { 
        std::cout << stack[top] << std::endl; // Вывод верхнего элемента стека 
    } else { 
        std::cout << "Stack is empty" << std::endl; 
    } 
 
    return 0; 
}
