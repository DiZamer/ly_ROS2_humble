import RPi.GPIO as GPIO  # Модуль управления GPIO
import time
""" from tutorial 
https://www.youtube.com/watch?v=6UBXRyZ8b7I&list=PLLSegLrePWgLzBgQqDJvgZ4ewbpCnuare&index=7
 """
GPIO.setmode(GPIO.BCM)  # Указываем какие номера используются: GPIO 17, а не 11 

LED_PIN = 17
BUTTON_PIN = 26

GPIO.setup(LED_PIN, GPIO.OUT)  # ПИН используется для вывода данных
GPIO.setup(BUTTON_PIN, GPIO.IN)  # ПИН используется для вывода данных


while True:
    time.sleep(0.01)  # Разгрузка процессора в цикле
    if GPIO.input(BUTTON_PIN) == GPIO.HIGH:
        GPIO.output(LED_PIN, GPIO.HIGH)
    else:
        GPIO.output(LED_PIN, GPIO.LOW)

GPIO.cleanup()  # Освобождение GPIO
