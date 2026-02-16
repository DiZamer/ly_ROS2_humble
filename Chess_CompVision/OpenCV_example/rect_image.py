import sys
import numpy as np
import cv2 as cv
import math

hsv_min = np.array((0, 0, 73), np.uint8)
hsv_max = np.array((203, 255, 154), np.uint8)

color_blue = (255, 0, 0)
color_yellow = (0, 255, 255)

if __name__ == "__main__":
    fn = "/home/dizamer/MyPythonProjects/SMLRobotic/OpenCV/color_and_shape/rects.jpg"  # имя файла, который будем анализировать
    img = cv.imread(fn)

    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)  # меняем цветовую модель с BGR на HSV
    thresh = cv.inRange(hsv, hsv_min, hsv_max)  # применяем цветовой фильтр
    contours0, hierarchy = cv.findContours(
        thresh.copy(), cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE
    )

    # перебираем все найденные контуры в цикле
    for cnt in contours0:
        if len(cnt) >= 4:
            rect = cv.minAreaRect(cnt)  # пытаемся вписать прямоугольник
            box = cv.boxPoints(rect)  # поиск четырех вершин прямоугольника
            box = np.int32(box)  # округление координат
            center = (int(rect[0][0]), int(rect[0][1]))
            area = int(rect[1][0] * rect[1][1])  # вычисление площади
            # вычисление координат двух векторов, являющихся сторонам прямоугольника
            edge1 = np.int32((box[1][0] - box[0][0], box[1][1] - box[0][1]))
            edge2 = np.int32((box[2][0] - box[1][0], box[2][1] - box[1][1]))

            # выясняем какой вектор больше
            usedEdge = edge1
            if cv.norm(edge2) > cv.norm(edge1):
                usedEdge = edge2
            reference = (1, 0)  # горизонтальный вектор, задающий горизонт

            # вычисляем угол между самой длинной стороной прямоугольника и горизонтом
            angle = (
                180.0
                / math.pi
                * math.acos(
                    (reference[0] * usedEdge[0] + reference[1] * usedEdge[1])
                    / (cv.norm(reference) * cv.norm(usedEdge))
                )
            )

            if 1000 < area < 200000:
                cv.drawContours(img, [box], 0, (0, 0, 255), 2)  # рисуем прямоугольник
                cv.circle(
                    img, center, 5, color_yellow, 2
                )  # рисуем маленький кружок в центре прямоугольника
                # выводим в кадр величину угла наклона
                cv.putText(
                    img,
                    "%d" % int(angle),
                    (center[0] + 20, center[1] - 20),
                    cv.FONT_HERSHEY_SIMPLEX,
                    1,
                    color_yellow,
                    2,
                )

    cv.imshow("contours", img)  # вывод обработанного кадра в окно

    cv.waitKey()
    cv.destroyAllWindows()
