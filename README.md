В сборке установлен ROS2 Humble через devcontainer. 

Особенности настройки и установки под windows и nixos описаны в папке setup.

Папка turtlebot3_ws создержит установленного робота TurtleBot3.
# 1. Структура проекта

# 1.1. ros2_ws
``` Проект "ИНТЕРАКТИВНЫЙ РОБОТ-МАНИПУЛЯТОР СО ВСТРОЕННЫМ ШАХМАТНЫМ ДВИЖКОМ" ```

# 1.2. Chess_CompVision


# 2. Справочные команды для быстрого запуска

# 2.1. Вывод GUI из контейнера. Он необходим для работы gazebo, rviz2 или вывода изображения OpenCV
wayland: открыть доступ к дисплею через терминал хоста `xhost +local:` и сделать rebuild контейнера, если вывода нет

# 2.2. Справочные команды для черепашки
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key


# 2.3. Справочные команды для запуска TurtleBot3
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