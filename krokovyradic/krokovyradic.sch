EESchema Schematic File Version 4
LIBS:krokovyradic-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_Motor:Pololu_Breakout_A4988 A?
U 1 1 5BE2F1A4
P 7200 3300
F 0 "A?" H 7250 4178 50  0000 C CNN
F 1 "Pololu_Breakout_A4988" H 7250 4087 50  0000 C CNN
F 2 "Module:Pololu_Breakout-16_15.2x20.3mm" H 7475 2550 50  0001 L CNN
F 3 "https://www.pololu.com/product/2980/pictures" H 7300 3000 50  0001 C CNN
	1    7200 3300
	1    0    0    -1  
$EndComp
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 5BE2F265
P 8800 3450
F 0 "M?" H 8988 3573 50  0000 L CNN
F 1 "Stepper_Motor_bipolar" H 8988 3482 50  0000 L CNN
F 2 "" H 8810 3440 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 8810 3440 50  0001 C CNN
	1    8800 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5BE2F449
P 8650 4200
F 0 "C?" H 8765 4246 50  0000 L CNN
F 1 "C" H 8765 4155 50  0000 L CNN
F 2 "" H 8688 4050 50  0001 C CNN
F 3 "~" H 8650 4200 50  0001 C CNN
	1    8650 4200
	1    0    0    -1  
$EndComp
Text GLabel 8950 4050 0    50   Input ~ 0
47mF
$Comp
L power:+7.5V #PWR?
U 1 1 5BE2F65F
P 9650 4050
F 0 "#PWR?" H 9650 3900 50  0001 C CNN
F 1 "+7.5V" H 9665 4223 50  0000 C CNN
F 2 "" H 9650 4050 50  0001 C CNN
F 3 "" H 9650 4050 50  0001 C CNN
	1    9650 4050
	1    0    0    -1  
$EndComp
$Comp
L krokovyradic-rescue:ATMEGA328-P IC?
U 1 1 5BE2CED1
P 4650 3400
F 0 "IC?" H 3900 4650 50  0000 L BNN
F 1 "ATMEGA328-P" H 5050 2000 50  0000 L BNN
F 2 "DIL28" H 4650 3400 50  0000 C CIN
F 3 "" H 4650 3400 50  0000 C CNN
	1    4650 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2600 6000 2600
Wire Wire Line
	6000 2600 6000 2100
Wire Wire Line
	4100 2100 4100 2050
Wire Wire Line
	4100 2050 3500 2050
Wire Wire Line
	3500 2050 3500 2300
Wire Wire Line
	3500 2300 3750 2300
Wire Wire Line
	4100 2100 6000 2100
Wire Wire Line
	7200 4100 5800 4100
Wire Wire Line
	5800 4100 5800 4900
Wire Wire Line
	5800 4900 3600 4900
Wire Wire Line
	3600 4900 3600 4500
Wire Wire Line
	3600 4500 3750 4500
Wire Wire Line
	5650 3550 6550 3550
Wire Wire Line
	6550 3550 6550 3300
Wire Wire Line
	6550 3300 6800 3300
Wire Wire Line
	5650 3450 6800 3450
Wire Wire Line
	6800 3450 6800 3400
Wire Wire Line
	6800 2900 6550 2900
Wire Wire Line
	6550 2900 6550 3000
Wire Wire Line
	6550 3000 6800 3000
Wire Wire Line
	7400 4100 8150 4100
Wire Wire Line
	8650 4350 9650 4350
Wire Wire Line
	9650 4350 9650 4050
Connection ~ 8650 4350
Wire Wire Line
	8650 4050 8650 3950
Wire Wire Line
	8650 3950 9650 3950
Wire Wire Line
	8150 4100 8150 4350
Wire Wire Line
	8150 4350 8650 4350
Wire Wire Line
	7700 3200 8150 3200
Wire Wire Line
	8150 3200 8150 3000
Wire Wire Line
	8150 3000 8900 3000
Wire Wire Line
	8900 3000 8900 3150
Wire Wire Line
	7700 3300 8300 3300
Wire Wire Line
	8300 3300 8300 3050
Wire Wire Line
	8300 3050 8700 3050
Wire Wire Line
	8700 3050 8700 3150
Wire Wire Line
	7700 3400 8350 3400
Wire Wire Line
	8350 3400 8350 3350
Wire Wire Line
	8350 3350 8500 3350
Wire Wire Line
	7700 3500 8400 3500
Wire Wire Line
	8400 3500 8400 3550
Wire Wire Line
	8400 3550 8500 3550
Wire Wire Line
	7400 2600 10300 2600
Wire Wire Line
	10300 2600 10300 3800
Wire Wire Line
	10300 3800 8650 3800
Wire Wire Line
	8650 3800 8650 3950
Connection ~ 8650 3950
$EndSCHEMATC
