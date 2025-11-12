Сборка реализован на ROS2 Humble devcontainer с использованием моделей TurtleBot3. 
В репозитории находятся: 
(1) программа-координатор движения роботов, 
(2) папки с конфигурированными ROS2-роботами,
(3) файлы в папке .devcontainers для сборки контейнера.

# 3. файлы в папке .devcontainers для сборки контейнера
Может использоваться для создания среды ROS2 с описанием роботов, элементами и виртуальной средой для визуализации движения

# 3.1. Вывод GUI из контейнера. Он необходим для работы gazebo, rviz2 или вывода изображения OpenCV
1) wayland: открыть доступ к дисплею через терминал хоста `xhost +local:` и сделать rebuild контейнера, если вывода нет
2) если предыдущий не сработал, сделать следующее:
    - в devcontainers.json раскоментировать 
        ``` json       
        , 
        "features": {
        "ghcr.io/devcontainers/features/desktop-lite:1": {}
        },
        "forwardPorts": [6080, 5901],
        "portsAttributes": {
        "6080": {
            "label": "Desktop (Web)"
        },
        "5901": {
            "label": "Desktop (VNC)"
        }
        }
        ```
    - закоментирвоать `--network=host`


# 3.2. Подготовка среды ROS2 (не обязательно): установка, пересборка контейнера и настройка вывода GUI 

# Запуск gazebo с эмуляцией готовых роботов TurtleBot3
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
Надо клавиатурного управления роботом
```bash
ros2 run turtlebot3_teleop teleop_keyboard
```





 