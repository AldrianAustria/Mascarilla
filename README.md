# Mascarilla
A Presence Triggered Face Mask Detection using YOLOv5 Object Detection Model and Arduino UNO R3 Ultrasonic Sensor.

The program is intergrated with an Arduino UNO R3 micro-controller, HC-SR04 Ultrasonic Sensor to determine the distance to simulate the presence detection, and three LED indicators to visualized the output of the program  corresponding to the type of face mask that a user is wearing.

Presence Trigger Distance: 
121cm from the ultrasonic sensor

LED Indicators:
With mask - Green LED
Without mask - Red LED
Mask wear incorrectly - Yellow LED


You can change the weight of this program with your own weight you have trained in YOLOv5 Google Colab.
NOTE: Convert your .pt file into .onnx for the program to work.

About the Weight:
WeightA.onnx is provided in the Weight Link file where the metrics is also provided.
