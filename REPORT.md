# Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.

```bash
$ cat >README.md <<EOF
> #Отчёт по лабораторной работе №2
> ##Подготовил: Мельников Егор ИУ8-22
> EOF
$ cat >REPORT.md <<EOF
> EOF
$ git init
$ git add .
$ git commit -m "added README.md and REPORT.md files"
```

3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.

```bash
$ cat >hello_world.cpp <<EOF
> #include <iostream>
> 
> using namespace std;
> 
> int main()
> {
>     cout << "Hello, World!" << endl;
>
>     return 0;
> }
> EOF
```

4. Добавьте этот файл в локальную копию репозитория.

```bash
$ git add hello_world.cpp
```

5. Закоммитьте изменения с *осмысленным* сообщением.

```bash
$ git commit -m "added hello_world.cpp file"
```

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.

```bash
$ edit hello_world.cpp
```

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	cout << "Enter your name: "; cin >> name;
	cout << "Hello world from " << name << endl;
	return 0;
}
```

7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?

```bash
$ git commit -am "updated hello_world.cpp"
```

Добавлять `git add` не надо по той причине, что система `git` уже отслеживает файл программы и он находится в системе контроля версии. Единственное что нужно сделать чтобы изменить его состояние в ветке, так это выполнить команду `git commit` с флагом `-a`.

8. Запуште изменения в удалёный репозиторий.

```bash
$ git push origin master
```

9. Проверьте, что история коммитов доступна в удалёном репозитории.

### Part II

1. В локальной копии репозитория создайте локальную ветку `patch1`.

```bash
$ git branch patch1
$ git chechout patch1
```

2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.

```bash
$ edit hello_world.cpp
```

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Enter your name: "; std::cin >> name;
    std::cout << "Hello world from " << std::name << endl;
    return 0;
}
```

3. **commit**, **push** локальную ветку в удалённый репозиторий.

```bash
$ git commit -am "fixed rough code style"
$ git push origin patch1
```

4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.

5. Создайте pull-request `patch1 -> master`.

6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.

```bash
$ edit hello_world.cpp
```

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name; //Объявление переменной, хранящей имя пользователя
    std::cout << "Enter your name: "; std::cin >> name; //Ввод имени пользователя
    std::cout << "Hello world from " << std::name << endl; //Вывод сообщения с именеи=м пользователя
    return 0;
}
```

7. **commit**, **push**.

```bash
$ git commit -am ""
$ git push origin master
```

8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request

9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.

10. Локально выполните **pull**.

```bash
$ git pull origin master
```

11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.

```bash
$ git log
commit cb79ffa5c51422f451494f4cb6a4e4003bc0853f (HEAD -> master, origin/master, origin/HEAD)
Merge: 9cfa04a 2ed0102
Author: jo22i <99878853+jo22i@users.noreply.github.com>
Date:   Mon Mar 14 00:58:50 2022 +0300

    Merge branch 'patch1'

commit 2ed0102f5a9a4fe470e7b2f30603046c32688665 (origin/patch1, patch1)
Author: jo22i <99878853+jo22i@users.noreply.github.com>
Date:   Sun Mar 13 23:57:54 2022 +0300

    added comments

commit c9df36cd328f08f6abb9b59453c715ba212dc561 (upstream/patch1)
Author: jo22i <99878853+jo22i@users.noreply.github.com>
Date:   Sun Mar 13 21:28:06 2022 +0300

    fixed rough code style

commit 9cfa04a164e11211a0dac3e54a2bd9b25856cee0 (upstream/master)
Author: jo22i <99878853+jo22i@users.noreply.github.com>
Date:   Sun Mar 13 21:09:34 2022 +0300
```

12. Удалите локальную ветку `patch1`.

```bash
$ git branch -d patch1
```

### Part III

1. Создайте новую локальную ветку `patch2`.

```bash
$ git checkout -b patch2
```

2. Измените *code style* с помощью утилиты **clang-format**. Например, используя опцию `-style=Mozilla`.

```bash
$ clang-format -style=Google hello_world.cpp
```

```cpp
#include <iostream>
#include <string>

int main() {
  std::string name;  //Объявление переменной, хранящей имя пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;  //Ввод имени пользователя
  std::cout << "Hello world from " << std::name
            << endl;  //Вывод сообщения с именем пользователя
  return 0;
}
```

3. **commit**, **push**, создайте pull-request `patch2 -> master`.

```bash
$ git commit -am "changed style to Google"
$ git push origin patch2
```

4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.

```bash
-	 std::cout << "Hello world from " << std::name << endl; //Вывод сообщения с именеи=м пользователя
+    std::cout << "Hello world from " << std::name << endl; //Вывод сообщения с именем пользователя
```

5. Убедитесь, что в pull-request появились *конфликтны*.



6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.

```bash

```

7. Сделайте *force push* в ветку `patch2`



8. Убедитель, что в pull-request пропали конфликтны. 



9. Вмержите pull-request `patch2 -> master`.

```bash
$ git pull origin master
$ edit hello_world.cpp
$ git commit -m "fixed conflicts between branches"
$ git checkout patch2
$ edit hello_world.cpp
$ git add hello_world.cpp
$ git checkout master
$ git add .
$ git commit -m "fixed conflicts between branches v2"
$ git merge
$ git merge master
$ git merge --no-ff patch2
$ git push --force origin master
$ git checkout patch2
$ edit hello_world.cpp
$ git merge patch2
$ git checkout master
$ git push origin master
$ edit hello_world.cpp
$ git commit -am "some fixes"
$ git push origin master
```
