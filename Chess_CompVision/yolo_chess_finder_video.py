from ultralytics import YOLO   # type: ignore
import cv2
import numpy as np
import os

# import sys
# sys.path.append('./images')

# Загрузка модели YOLOv8
# model = YOLO('best.pt')  # https://huggingface.co/yamero999/chess-piece-detection-yolo11n
model = YOLO('yolov8n.pt')

# model = YOLO('chesspiece-detection-model.pt')  # https://huggingface.co/acapitani/chesspiece-detection-yolo

""" 
"Работа с YOLOV8. Детекция, сегментация, трекинг объектов, а также подготовка собственного датасета и обучение"
Stepan_Burmistrov
https://habr.com/ru/articles/821971/
"""


# Список цветов для различных классов
colors = [
    (255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0), (0, 255, 255),
    (255, 0, 255), (192, 192, 192), (128, 128, 128), (128, 0, 0), (128, 128, 0),
    (0, 128, 0), (128, 0, 128), (0, 128, 128), (0, 0, 128), (72, 61, 139),
    (47, 79, 79), (47, 79, 47), (0, 206, 209), (148, 0, 211), (255, 20, 147)
]

cap = cv2.VideoCapture(0)

# Функция для обработки изображения
def process_image():
    
    while True:
        flag, image = cap.read()

        results = model(image)[0] # type: ignore
        
        # Получение оригинального изображения и результатов
        image = results.orig_img
        classes_names = results.names
        classes = results.boxes.cls.cpu().numpy()
        boxes = results.boxes.xyxy.cpu().numpy().astype(np.int32)

        # Подготовка словаря для группировки результатов по классам
        grouped_objects = {}

        # Рисование рамок и группировка результатов
        for class_id, box in zip(classes, boxes):
            class_name = classes_names[int(class_id)]
            color = colors[int(class_id) % len(colors)]  # Выбор цвета для класса
            if class_name not in grouped_objects:
                grouped_objects[class_name] = []
            grouped_objects[class_name].append(box)

            # Рисование рамок на изображении
            x1, y1, x2, y2 = box
            cv2.rectangle(image, (x1, y1), (x2, y2), color, 2)
            cv2.putText(image, class_name, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)

        
        cv2.imshow("result", image)

        # Выход по клавише 'q'
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break


    cap.release()
    cv2.destroyAllWindows()

process_image()