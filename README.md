# Лабораторна робота №2: ООП

# Студента групи КІ2С-23-1 Рудичука Дмитра 
# Варіант завдання №4

## Тема
Основні поняття про класи, методи класів, оператори new, delete в мові програмування С++

## Повний звіт з результатами виконання лабораторної роботи знаходиться у директорії "documents"

## Мета
- Вивчити структуру класу мови С++
- Навчитися оголошувати класи, їх данні та методи
- Ознайомитися з поняттям об'єкту
- Навчитися вирішувати задачі за допомогою класів

## Структура програми
Цей проект є реалізацією футбольного турніру, де зберігається інформація про команди, гравців та їх статистику. Програма підтримує пошук гравців і команд, збереження результатів турніру у файл та динамічне керування об'єктами. Використовуються основні принципи ООП: інкапсуляція, створення класів та методів, робота з динамічною пам'яттю.

### Функціонал
- Зберігання інформації про команди та гравців.
- Пошук гравців за іменем.
- Пошук команди за назвою.
- Оновлення та виведення статистики команд.
- Збереження результатів у файл `results.txt`.
- Використання динамічної пам'яті для управління об'єктами.

### Структура
Програма складається з трьох основних файлів:
- `main.cpp` — містить основну логіку програми.
- `team.h`, `team.cpp` — визначення та реалізація класів `FootballPlayer` і `FootballTeam`.


## Виконання програми
1. Клонувати репозиторій:
   ```bash
   git clone https://github.com/RudychukDmytro/OOP_Labs_2
2. Перейти відкрити в термінальному вікні робочий каталог
3. Виконати компіляцію:
   ```bash
   g++ main.cpp students.cpp trains.cpp -o program
4. Запустити скомпільований файл:
   ```bash
   ./program

Приклад для запуску програми наведено для операційної системи Ubuntu або їй подібним.

## Висновки
У ході виконання лабораторної роботи я навчився створювати класи та їх методи в мові програмування C++, опрацював такі важливі аспекти ООП, як інкапсуляція, робота з об'єктами та методами класів. Також здобув досвід роботи з динамічною пам'яттю за допомогою операторів new і delete, а також навчився реалізовувати взаємодію об'єктів між класами та зберігати результати в файли.
