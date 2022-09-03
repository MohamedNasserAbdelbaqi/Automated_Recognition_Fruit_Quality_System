import torch
import os
import cv2
import serial
import time
#----------------------------------------------------------------------------------------------------------------------------------------------
# riping level of banana
#------------------------
#            1             2            3        4      5       6
types = ['freshripe','freshunripe','overripe','ripe','rotten','unripe']
#----------------------------------------------------------------------------------------------------------------------------------------------
# function of classification
#----------------------------
def final_result(img):
    model = torch.hub.load('E:\engineering\graduation_project\yolov5','custom', path='E:\engineering\graduation_project\yolov5\last_101.pt', source='local')
    res = model(img)
    a=res.xyxy[0]
    f=a.numpy()
    t=int(f[0][5])
    print(t)
    print(types[t])
    if t == 4:
        t = 0         # 'rotten' 
    else:
        t = 1         # 'freshripe','freshunripe','overripe','ripe' and 'unripe'

    return t
#----------------------------------------------------------------------------------------------------------------------------------------
def move_to_not_rippen_box():
    try:                        
        ser.write(b'0')
    except:
        print('raspberry pi is not connected to AVR MCU')
#-----------------------------------------------------------------------------------------------------------------------------------------------    
def move_to_rippen_box():
    try:                        
        ser.write(b'1')
    except:
        print('raspberry pi is not connected to AVR MCU')
#------------------------------------------------------------------------------------------------------------------------------------------------
# initialization of serial port
#-------------------------------
ser = serial.Serial()
ser.port = 'COM7'                         # port name depending on operating system. e.g. /dev/ttyUSB0 on GNU/Linux or COM3 on Windows.
ser.baudrate = 9600                       # baud rate
ser.bytesize = serial.EIGHTBITS           # char size , Possible values: FIVEBITS, SIXBITS, SEVENBITS, EIGHTBITS
ser.parity = serial.PARITY_NONE           # parity type , Possible values: PARITY_NONE, PARITY_EVEN, PARITY_ODD PARITY_MARK, PARITY_SPACE
stopbits = serial.STOPBITS_ONE            # stop bit(s) size ,Possible values: STOPBITS_ONE, STOPBITS_ONE_POINT_FIVE, STOPBITS_TWO
   
try:
    ser.open()                            # open port
except:
    print('AVR MCU is not connected :(')

# main
#------------------------------------------------------------------------------------------------------------------------------------------------
while True:
    #----------------------------------
    # reading ready signal from AVR MCU
    #----------------------------------
    while True:
        ser.flushInput()
        received_byte = ser.read_until('R',1)
        if ord(received_byte) == ord('R'):
            print('READY')
            break
    #---------------------------------------------------------------------------------------------------------------------------------------------
    # capture picture with connected camera
    #---------------------------------------
    #http://192.168.1.57:8080/video
    capture = cv2.VideoCapture(1)
    while True:
        result, frame = capture.read()
        cv2.imshow('Live Stream',frame)
        if cv2.waitKey(1) == ord('q'):
            if result:
                cv2.imwrite(r'E:\engineering\graduation_project\yolov5\cliped_img\banana.jpg', frame)
            else:
                print('No image detected. Please! try again')
            break
    capture.release()
    cv2.destroyAllWindows()
    #--------------------------------------------------------------------------------------------------------------------------------------------
    # classify captured image
    #-------------------------
    try:
        y = final_result(os.path.join(r'E:\engineering\graduation_project\yolov5\cliped_img\banana.jpg'))
    except:
        y = 2
    #--------------------------------------------------------------------------------------------------------------------------------------------
    # print result of classification
    #--------------------------------
    if y == 0:
        move_to_not_rippen_box()
        print('Rotten')
    elif y == 1:
        move_to_rippen_box()
        print('Fresh')
    elif y == 2:
        print('WIERD BODY')
    #-----------------------------------
    # reading finish signal from AVR MCU
    #-----------------------------------
    while True:
        #ser.flushInput()
        received_byte = ser.read_until('F',1)
        if ord(received_byte) == ord('F') or y == 2:
            print('FINISH')
            break
    print('--------------------------------END--------------------------------')
#-------------------------------------------------------------------------------------------------------------------------------------------------
