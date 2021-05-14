# -*- coding: utf-8 -*-
"""
Created on Fri Dec 11 11:41:05 2020

@author: Arun
"""
import pandas as pd
import serial
import time

green_rgb =[]                       # empty list to store the data
green_ir = []
green_uv = []

blue_rgb =[]                       # empty list to store the data
blue_ir = []
blue_uv = []

red_rgb =[]                       # empty list to store the data
red_ir = []
red_uv = []

ir_rgb =[]                       # empty list to store the data
ir_ir = []
ir_uv = []


ident = 0
outer = str()
Run = True



ser = serial.Serial('COM8 ')  # open serial port
print(ser.name)         # check which port was really used
# for x in range(10):
#     ser.write(b'hello')     # write a string
#     time.sleep(1)

while Run:
#     print(ser.readline()) # Read the newest output from the Arduino
#     print("------------")
#     time.sleep(.1) # Delay for one tenth of a second
     
     
    b = ser.readline()         # read a byte string
    string_n = b.decode()      # decode byte string into Unicode  
    string = string_n.rstrip() # remove \n and \r
    
    if 'Green' in string:
        outer = 'G'
    if 'Blue' in string:
        outer = 'B'
    if 'Red' in string:
        outer = 'R'
    if 'Infrared' in string:
        outer = 'I'
        
    if 'rgb' in string :
            ident = 1
    if 'IR' in string :
            ident = 2
    if 'UV' in string:
            ident = 3
    if 'End' in string:
            Run = False
    
    if 'G' in outer and 'Green' not in string:
      
        if ident == 1  and 'rgb' not in string:
            flt = float(string)        # convert string to float
            green_rgb.append(flt)
            ident = 0
    
        if ident == 2 and 'IR' not in string:
            flt = float(string)        # convert string to float
            green_ir.append(flt)
            ident = 0
            
        if ident == 3  and 'UV' not in string:
            flt = float(string)        # convert string to float
            green_uv.append(flt)
            ident = 0
        
        time.sleep(0.1)            # wait (sleep) 0.1 seconds
        
    if 'B' in outer and 'Blue' not in string:
        
        if ident == 1  and 'rgb' not in string:
            flt = float(string)        # convert string to float
            blue_rgb.append(flt)
            ident = 0
    
        if ident == 2 and 'IR' not in string:
            flt = float(string)        # convert string to float
            blue_ir.append(flt)
            ident = 0
            
        if ident == 3  and 'UV' not in string:
            flt = float(string)        # convert string to float
            blue_uv.append(flt)
            ident = 0
            
    if 'R' in outer and 'Red' not in string:
        
        if ident == 1  and 'rgb' not in string:
            flt = float(string)        # convert string to float
            red_rgb.append(flt)
            ident = 0
    
        if ident == 2 and 'IR' not in string:
            flt = float(string)        # convert string to float
            red_ir.append(flt)
            ident = 0
            
        if ident == 3  and 'UV' not in string:
            flt = float(string)        # convert string to float
            red_uv.append(flt)
            ident = 0
            
    if 'I' in outer and 'Infrared' not in string:     
        
        if ident == 1  and 'rgb' not in string:
            flt = float(string)        # convert string to float
            ir_rgb.append(flt)
            ident = 0
    
        if ident == 2 and 'IR' not in string:
            flt = float(string)        # convert string to float
            ir_ir.append(flt)
            ident = 0
            
        if ident == 3  and 'UV' not in string:
            flt = float(string)        # convert string to float
            ir_uv.append(flt)
            ident = 0
        
        
#
#
#print("RGB", rgb)
#print("===================")
#print("IR", ir)
#("===================")
#print("UV", uv)


ser.close()             # close por

# Introducing dataframe here
data_points = len(red_rgb)
column_names = ['Material']
idx = ['Coffee'] * data_points
df = pd.DataFrame(idx, columns = column_names )

df['Green_sensor'] = ""
df['Green_IR'] = ""
df['Green_UV'] = ""

df['Blue_sensor'] = ""
df['Blue_IR'] = ""
df['Blue_UV'] = ""

df['Red_sensor'] = ""
df['Red_IR'] = ""
df['Red_UV'] = ""

df['IR_sensor'] = ""
df['IR_IR'] = ""
df['IR_UV'] = ""


for i in range(data_points):
    df.at[i,"Green_sensor"] = green_rgb[i]
    df.at[i,"Green_IR"] = green_ir[i]
    df.at[i,"Green_UV"] = green_uv[i]
    
    df.at[i,"Blue_sensor"] = blue_rgb[i]
    df.at[i,"Blue_IR"] = blue_ir[i]
    df.at[i,"Blue_UV"] = blue_uv[i]
    
    df.at[i,"Red_sensor"] = red_rgb[i]
    df.at[i,"Red_IR"] = red_ir[i]
    df.at[i,"Red_UV"] = red_uv[i]
    
    df.at[i,"IR_sensor"] =  ir_rgb[i]
    df.at[i,"IR_IR"] = ir_ir[i]
    df.at[i,"IR_UV"] = ir_uv[i]
    
    
df.head()
df.to_csv('Coffee test2.csv',index=True)

#exit()
