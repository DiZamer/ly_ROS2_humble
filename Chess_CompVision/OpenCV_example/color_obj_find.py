import cv2
import numpy as np

if __name__ == "__main__":
    def callback(*arg):
        print(arg)


cv2.namedWindow("result")

cap = cv2.VideoCapture(0)
# HSV фильтр для зеленых объектов из прошлого урока
hsv_min = np.array((32, 69, 32), np.uint8)
hsv_max = np.array((111, 226, 224), np.uint8)

color_yellow = (0,255,255)

while True:
    flag, img = cap.read()
    img = cv2.flip(img,1) # отражение кадра вдоль оси Y
    # преобразуем RGB картинку в HSV модель
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    # применяем цветовой фильтр
    thresh = cv2.inRange(hsv, hsv_min, hsv_max)

    # вычисляем моменты изображения
    moments = cv2.moments(thresh, 1)
    dM01 = moments["m01"]
    dM10 = moments["m10"]
    dArea = moments["m00"]
    # будем реагировать только на те моменты,
    # которые содержать больше 100 пикселей
    if dArea > 100:
        x = int(dM10 / dArea)
        y = int(dM01 / dArea)
        cv2.circle(img, (x, y), 5, color_yellow, 2)
        cv2.putText(img, "%d-%d" % (x,y), (x+10,y-10), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1, color_yellow, 2)

    cv2.imshow("result", img)

    # Выход по клавише 'q'
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
