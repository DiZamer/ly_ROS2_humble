В сборке установлен ROS2 Humble через devcontainer. 

Особенности настройки и установки под windows и nixos описаны в папке setup.

Папка turtlebot3_ws создержит установленного робота TurtleBot3.
# 1. Структура проекта

# 1.1. ros2_ws
``` Проект "ИНТЕРАКТИВНЫЙ РОБОТ-МАНИПУЛЯТОР СО ВСТРОЕННЫМ ШАХМАТНЫМ ДВИЖКОМ" ```

# 1.2. Chess_CompVision


# 2. Установка и настройка Raspbery Pi

# 2.1. Установка
Видеоинструкция: https://www.youtube.com/watch?v=IuA8kkImewQ&list=PLLSegLrePWgLzBgQqDJvgZ4ewbpCnuare&index=2
- Скачать и установить для вашей ОС Raspberry Pi Imager https://www.raspberrypi.com/software/
- Следуя инструкции установить на хост SD-карту Raspberry Pi OS (64-bit): 
    SSH включить, пользователя pi с паролем создать, сеть WiFI раздать с телефона.
- Вставить флэшку в RPi и подключить к питанию 2А через USB-type-C.

# 2.1. Подключение через терминал в RPi
- Установить ПО Angry IP Scanner на ваш хост. В вашей локальной WIFI-сети найти RPi и определить его IP-адрес.
- Через терминал ПК подключиться по SSH, указав имя пользователя pi, IP-адрес RPi и введя пароль. Например: `ssh pi-01@10.243.135.156`
- Когда RPi подключится к сети, вы увидете на телефоне дополнительное устройство у WiFi-точки
- Выклюение: `sudo poweroff`

# 2.2. Создание монитора через VNC
Видеоинструкция: https://www.youtube.com/watch?v=E5cbM-aYgO4&list=PLLSegLrePWgLzBgQqDJvgZ4ewbpCnuare&index=3
- Подключиться к RPi через терминал по SSH
- Запустить на RPi: `sudo raspi-config`. В открывшемся меню найти interface options и включить VNC. Перезапустить RPi: sudo reboot
- Зайти по SSH, `sudo raspi-config`, System Options -> Boot -> Desktop Autologin (или Desctop GUI) -> Save -> Reboot
- Зайти по SSH, `sudo raspi-config`, Display Options -> VNC Resolution -> Установить разрешение, близкое хосту
- Скачать и установить на хост real vnc viever
- В VNC viewer создать новое подключение: в качестве сервера задаем ip RPi. Если вохникает "The connection closed unexpectedly", отключаем VPN.

# 2.4. Настройка ОС Raspberry Pi
- Меню `Пуск` -> Preferences -> Raspberry Pi Configuration (или Contral Center) -> System - Проверить, что загрузка на рабочий стол
- Проверить сеть WiFi. При необходимости можно сменить сеть компьютера и RPi, предварительно определив IP
- Установить обновления


















# 4. Справочные команды для быстрого запуска

# 4.1. Вывод GUI из контейнера. Он необходим для работы gazebo, rviz2 или вывода изображения OpenCV
wayland: открыть доступ к дисплею через терминал хоста `xhost +local:` и сделать rebuild контейнера, если вывода нет

# 4.2. Справочные команды для черепашки
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key


# 4.3. Справочные команды для запуска TurtleBot3
```Документация к TurtleBot3: https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/```

Робот в пустом пространстве
```bash
export TURTLEBOT3_MODEL=burger
ros2 launch turtlebot3_gazebo empty_world.launch.py
```
Робот среди столбов
```bash
export TURTLEBOT3_MODEL=waffle
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py
```
Робот в квартире
```bash
export TURTLEBOT3_MODEL=waffle_pi
ros2 launch turtlebot3_gazebo turtlebot3_house.launch.py
```
Узел с клавиатурным управлением робота
```bash
ros2 run turtlebot3_teleop teleop_keyboard
```