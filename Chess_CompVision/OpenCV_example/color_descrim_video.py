import cv2
import numpy as np

if __name__ == '__main__':
   def callback(*arg):
       print (arg)

cv2.namedWindow( "result" )

cap = cv2.VideoCapture(0)

hsv_min = np.array((32, 69, 32), np.uint8)
hsv_max = np.array((111, 226, 224), np.uint8)

while True:
    flag, img = cap.read()
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV )
    thresh = cv2.inRange(hsv, hsv_min, hsv_max)

    cv2.imshow('result', thresh)

    # Выход по клавише 'q'
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()