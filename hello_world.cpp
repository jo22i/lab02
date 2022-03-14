#include <iostream>
#include <string>

int main() {
  std::string name;  //Объявление переменной, хранящей имя пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;  //Ввод имени пользователя
  std::cout << "Hello world from " << std::name
<<<<<<< HEAD
            << endl;  //Вывод сообщения с именем пользователя
=======
            << endl;  //Вывод сообщения с именеи=м пользователя
>>>>>>> patch2
  return 0;
}
