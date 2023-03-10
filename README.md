#Ресурсы, использованные в данной работе

•	Microsoft Visual Studio Enterprise 2019.

•	Версия компилятора: 16.11.8

•	Библиотека graphics.h (https://github.com/ahuynh359/Graphics)




Важный момент для понимания работы программы: программа обрабатывает сразу обе фигуры, т.е. при вызове функции для обработки программа работает сразу с обеими фигурами.

В основе реализации 3 класса. Деление кода следующее:

•	Файл main.cpp. Это основное тело программы. Функция main() запускает меню программы.

•	Файлы Menu.h и Menu.cpp. Файл Menu.h содержит в себе класс Menu, отвечающий за вызов основного меню, вызов графического интерфейса и за выполнение основных блоков действий. В файле Menu.cpp содержится реализация методов класса Menu.

•	Файлы Vertex.h и Vertex.cpp. Файл Vertex.h содержит в себе класс Vertex, который инициализирует вершины фигур. В файле Vertex.cpp содержится реализация методов класса Vertex.

•	Файлы Figure.h и Figure.cpp. Файл Figure.h содержит в себе класс Figure, который инициализирует матрицы точек, уравнений плоскостей, их произведений на вектора источника света и наблюдателя и рисование с преобразованием фигур. В файле Figure.cpp содержится реализация методов класса Figure.



#Реализация основных функций: 

•	Перемещение. За перемещение отвечает функция move(). Сначала создаётся объект класса Figure, который отвечает за данную фигуру. Затем в зависимости от состояния, которое задаётся в функции moving (класс Menu) она выполняет перемещение фигуры в плоскости по одной из любых 3 осей в любом из 2 направлений. Потом с помощью класса Vertex происходит преобразование полученных координат фигуры, и они записываются в объект класса Figure, после чего экран перерисовывает фигуры.

•	Масштабирование. За масштабирование отвечает функция scale(). Сначала создаётся объект класса Figure, который отвечает за данную фигуру. Затем в зависимости от состояния, которое задаётся в функции scaling (класс Menu) она выполняет изменение масштаба фигуры (либо расширение, либо сжатие). Потом с помощью класса Vertex происходит преобразование полученных координат фигуры, и они записываются в объект класса Figure, после чего экран перерисовывает фигуры.

•	Вращение. За вращение отвечает функция rotate(). Сначала создаётся объект класса Figure, который отвечает за данную фигуру. Затем в зависимости от состояния, которое задаётся в функции rotating (класс Menu) она выполняет вращение фигуры по любой из 3 осей либо против, либо по часовой стрелке. Потом с помощью класса Vertex происходит преобразование полученных координат фигуры, и они записываются в объект класса Figure, после чего экран перерисовывает фигуры.

•	Заливка с затравкой. За заливку отвечает функция fill. Сначала создаётся стек для хранения там пикселей. Дальше программа проверяет, в какой именно зоне находится грань. Если грань находится в тени, то пиксели в ней закрашиваются в тёмно-серый цвет, если нет, то в жёлтый. Каждый пиксель помещается в стек и окрашивает. Потом проверяются пиксели с остальных сторон. В результате полученная грань окрашивается в заданный цвет.

•	Рисование параллелепипеда. Сначала определяется центр фигуры и по уже имеющимся функциям рисования тени и удаления невидимых наблюдателю плоскостей происходят преобразования. Фигура проецируется на плоскость экрана и по граням происходит рисование фигуры с заливкой (если грань в теневой области, то она закрашивается в серый, иначе в жёлтый.



#Следующие 2 функции используются для реализации алгоритма Робертса.

•	Удаление невидимых граней. За удаление отвечает функция del_invisible_line. Сначала создаются матрицы уравнений плоскости и их умножение на векторы источника света и наблюдателя. Потом идёт проверка через центральную точку параллелепипеда. После этого все матрицы уравнений плоскости проверяются, и программа распознаёт, какие линии следует игнорировать при рисовании фигуры.

•	Рисование тени. За рисование тени отвечает функция draw_shadow. Сначала берётся проекция точек фигуры на плоскость пола. Следующим шагом идёт рисование и заливка тени. Для этого происходит преобразование координат тени в проекцию на плоскости. Преобразование точек происходит по следующему принципу. Точки проекции (в зависимости от координаты) получается следующим образом: на точку тени (в зависимости от координаты) умножается разность расстояния от глаза и расстояния от объекта до монитора. После этого рисуется тень и закрашивается в серый цвет.



#Дополнительные, но необходимые функции: 

•	Рисование грани. За рисование грани отвечает функция drawgran. Она рисует заданную грань с определённым цветом в зависимости от её положения (тень или свет).

•	Функция equation_of_flat. Она необходима для определения коэффициентов уравнения плоскости.

•	going_abroad. Данная функция отвечает за проверку выхода фигуры за границы экрана и совершает преобразование для возврата фигуры на экран полноценно.


#Функции меню:

•	menu. Данная функция вызывает главное меню программы. Для выхода необходимо нажать клавишу 0. В противном случае будет переход в подменю выбора режима. Дополнительно имеется глобальная переменная l. Она необходима для того, чтобы не создавать лишние графические окна и совершать работу в одном и том же окне.

•	menu_par. Данная функция рисует фигуры на экране. Тут по нажатию клавиши выбирается режим изменения фигуры: перемещение (клавиша M), масштабирование (клавиша S) и вращение (клавиша R). Выход осуществляется при нажатии клавиши Esc.

•	moving. Данная функция запускает режим перемещения. Все клавиши, необходимые для перемещения (QWEASD) выводятся на экран. При нажатии нужной происходит перемещение в заданном направлении по заданной оси. Выход осуществляется при нажатии клавиши Esc.

•	scaling. Данная функция запускает режим масштабирования. Все клавиши, необходимые для масштабирования (WS) выводятся на экран. При нажатии нужной происходит масштабирование в заданном режиме (расширение или сжатие). Выход осуществляется при нажатии клавиши Esc.

•	rotating. Данная функция запускает режим вращения. Все клавиши, необходимые для вращения (QWEASD) выводятся на экран. При нажатии нужной происходит вращение в заданном направлении по заданной оси. Выход осуществляется при нажатии клавиши Esc.



Ещё важный момент, который необходим для понимания работы программы: рисование фигур напрямую зависит от размера фигуры: чем она больше, тем медленней рисуется, а чем меньше, тем быстрее.
