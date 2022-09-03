import cv2
import tkinter as tk
from tkinter import *
import time
from itertools import count
from PIL import Image, ImageTk
import torch
import os
import serial
import time

types = ['freshripe','freshunripe','overripe','ripe','rotten','unripe']

# Set serial port 
ser = serial.Serial()

fresh_counter = 0
rotten_counter = 0
is_run = False

class ImageLabel(tk.Label):
    def load(self, im):
        if isinstance(im, str):
            im = Image.open(im)
        self.display_image(im)

    def set_capture_image(self ,image):
        RGB_img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        RGB_img = cv2.resize(RGB_img , (300,300))
        img = Image.fromarray(RGB_img)
        self.display_image(img)
        
    def display_image(self , img):
        self.loc = 0
        self.frames = []
        try:
            for i in count(1):
                self.frames.append(ImageTk.PhotoImage(img.copy()))
                img.seek(i)
        except EOFError:
            pass
        try:
            self.delay = img.info['duration']
        except:
            self.delay = 100
        if len(self.frames) == 1:
            self.config(image=self.frames[0])
        else:
            self.next_frame()

    def unload(self):
        self.config(image=None)
        self.frames = None
    
    def next_frame(self):
        if self.frames:
            self.loc += 1
            self.loc %= len(self.frames)
            self.config(image=self.frames[self.loc])
            self.after(self.delay, self.next_frame)


def clock_time():
    t=time.strftime('%I:%M:%S  %p',time.localtime())
    if t!='':
        label1.config(text=t,font='times 15 bold',background="#34282C",foreground="#FFFFFF")
    main_window.after(100,clock_time)

def clock_data():
    t=time.strftime('%d-%B-%Y',time.localtime())
    if t!='':
        label2.config(text=t,font='times 15 bold',background="#34282C",foreground="#FFFFFF")
    main_window.after(100,clock_data)

#----------------------------------------------------------------------------------------------------------------------------------------------
# function of Detection
#----------------------------
def final_result(img):
    model = torch.hub.load('E:\engineering\graduation_project\yolov5','custom', path='E:\engineering\graduation_project\yolov5\last_101.pt', source='local')
    res = model(img)
    a=res.xyxy[0]
    f=a.numpy()
    t=int(f[0][5])
    print(types[t])
    if t == 1 or t == 4 or t == 5:
        t = 0         # freshunripe , unripe and rotten 
    else:
        t = 1         # freshripe , overripe and ripe

    return t
#----------------------------------------------------------------------------------------------------------------------------------------

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

#------------------------------------------------------------------------------------------------------------------------------------------------
# initialization of serial port
#-------------------------------
def initialize_serial_port():
    global ser
    ser.port = 'COM7'                         # port name depending on operating system. e.g. /dev/ttyUSB0 on GNU/Linux or COM3 on Windows.
    ser.baudrate = 9600                       # baud rate
    ser.bytesize = serial.EIGHTBITS           # char size , Possible values: FIVEBITS, SIXBITS, SEVENBITS, EIGHTBITS
    ser.parity = serial.PARITY_NONE           # parity type , Possible values: PARITY_NONE, PARITY_EVEN, PARITY_ODD PARITY_MARK, PARITY_SPACE
    stopbits = serial.STOPBITS_ONE            # stop bit(s) size ,Possible values: STOPBITS_ONE, STOPBITS_ONE_POINT_FIVE, STOPBITS_TWO
    
    try:
        ser.open()                            # open port
    except:
        print('AVR MCU is not connected :(')
#------------------------------------------------------------------------------------------------------------------------------------------------
# main function

def main_program():

    global ser
    while True:
        ser.flushInput()
        received_byte = ser.read_until('R',1)
        if ord(received_byte) == ord('R'):
            print('READY')
            break
    
    capture = cv2.VideoCapture(1)
    while True:
        result, frame = capture.read()
        if result:
            cv2.imwrite(r'E:\engineering\graduation_project\yolov5\cliped_img\banana.jpg', frame)
            camera_view.set_capture_image(frame)
        else:
            print('No image detected. Please! try again')
        break
    
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
        fruit_state.config(text= f'Rotten fruit')
        update_rotten_entry()

    elif y == 1:
        move_to_rippen_box()
        fruit_state.config(text= f'Fresh fruit')
        update_fresh_entry()

    elif y == 2:
        print('WIERD BODY')

    # reading finish signal from AVR MCU
    #-----------------------------------
    while True:
        #ser.flushInput()
        received_byte = ser.read_until('F',1)
        if ord(received_byte) == ord('F') or y == 2:
            print('FINISH')
            break
    
def update_fresh_entry():
        global fresh_counter
        fresh_counter += 1
        fresh_entry.config(state= 'normal')
        fresh_entry.delete(0,END)
        fresh_entry.insert(0,fresh_counter)
        fresh_entry.config(state= 'readonly')

def update_rotten_entry():
        global rotten_counter
        rotten_counter += 1
        rotten_entry.config(state= 'normal')
        rotten_entry.delete(0,END)
        rotten_entry.insert(0,rotten_counter)
        rotten_entry.config(state= 'readonly')

def perform_main():
    main_program()
    global is_run
    if is_run:
        main_window.after(20000, perform_main) # depends on how long the main function takes time to be executed

def press_connect():
    camera_view.load('load.gif')
    initialize_serial_port()
    start_button.config(state=ACTIVE)
    stop_button.config(state=ACTIVE)
    camera_view.load('bh.png')

def press_start():
    is_run = True
    perform_main()
    start_button.config(state=DISABLED)

def press_stop():
    is_run = False
    start_button.config(state=DISABLED)
    stop_button.config(state=DISABLED)

# Build GUI APP
main_window = Tk()
main_window.title('Automated Recognition Fruit Quality System')
# put the app icon
main_window.iconbitmap('banana.ico')
# set the app window size
main_window.geometry('1000x510')
# set the app background image
img = PhotoImage(file="green.png")
label = Label(main_window,image=img)
label.place(x=0, y=0)

label1=Label(main_window,anchor="e",justify="left" , width= 10)
label1.pack()
label1.place(x=840,y=30)
clock_time()

label2=Label(main_window,justify='left' , width= 10)
label2.pack()
label2.place(x=840,y=60)
clock_data()

Camera_label = Label(main_window , text = 'Camera View',width=25)
Camera_label.config(font='times 15 bold',background="white", foreground="black")
Camera_label.pack()
Camera_label.place(x= 400 , y= 45)

camera_view = ImageLabel(main_window)
camera_view.pack()
camera_view.place(x=400,y=80)
camera_view.load('bh.png')
camera_view.config(background="black")

fruit_state = Label(main_window)
fruit_state.config(font='times 15 bold', foreground="green" , width= 25)
fruit_state.pack()
fruit_state.place(x= 400 , y= 390)

fresh_banana_image = ImageLabel(main_window)
fresh_banana_image.pack()
fresh_banana_image.place(x=10,y=10)
fresh_banana_image.load('fresh.jpg')

fresh_banana_image_label = Label(main_window , text = 'Fresh:')
fresh_banana_image_label.config(font='times 15 bold',background="white", foreground="black")
fresh_banana_image_label.pack()
fresh_banana_image_label.place(x= 10 , y= 217)
        
fresh_entry = Entry()
fresh_entry.pack()
fresh_entry.place(x= 74 , y=217)
fresh_entry.config(font='times 15 bold',background="white", foreground="black" , width=10 , state= 'readonly')

rotten_banana_image = ImageLabel(main_window)
rotten_banana_image.pack()
rotten_banana_image.place(x=10,y=250)
rotten_banana_image.load('rotten.jpg')

rotten_banana_image_label = Label(main_window , text = 'Rotten:')
rotten_banana_image_label.config(font='times 15 bold',background="white", foreground="black")
rotten_banana_image_label.pack()
rotten_banana_image_label.place(x= 10 , y= 457)

rotten_entry = Entry()
rotten_entry.pack()
rotten_entry.place(x= 85 , y=457)
rotten_entry.config(font='times 15 bold',background="white", foreground="black" , width=10 , state='readonly' )

connect_button = Label(main_window)
connect_button = Button(main_window,text="Connect",command= press_connect )
connect_button.config(font='times 15 bold',background="#000000", foreground="#08E900")
connect_button.pack()
connect_button.place(x=400, y=430)

start_button = Label(main_window)
start_button = Button(main_window,text="Start",command= press_start)
start_button.config(font='times 15 bold',background="#000000", foreground="#08E900")
start_button.pack()
start_button.place(x=540, y=430)
start_button.config(state=DISABLED) # tate=ACTIVE

stop_button = Label(main_window)
stop_button = Button(main_window,text="Stop",command= press_stop)
stop_button.config(font='times 15 bold',background="#000000", foreground="#08E900" , state= DISABLED)
stop_button.pack()
stop_button.place(x=650, y=430)

main_window.resizable(0,0)
main_window.mainloop()