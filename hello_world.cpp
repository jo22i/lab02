#include <iostream>
#include <string>

int main()
{
    std::string name; //Объявление переменной, хранящей имя пользователя
    std::cout << "Enter your name: "; std::cin >> name; //Ввод имени пользователя
    std::cout << "Hello world from " << std::name << endl; //Вывод сообщения с именеи=м пользователя
    return 0;
}
