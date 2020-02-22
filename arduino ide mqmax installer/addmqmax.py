import os
import subprocess


directory = "C:/Program Files (x86)/Arduino/hardware/arduino/avr/"
directory1 = ""
data = data2 = "" 
os.getcwd()
exist=os.path.exists(directory)
print (exist)
if exist:
   with open(os.path.join(directory, "boards.txt"), "r") as fp: 
      data = fp.read()
      fp.close()	 
   with open(os.path.join(directory1,"mqmax04.txt"), "r") as fp: 
      data2 = fp.read() 
      fp.close()
   data += "\n"
   data += data2 
   with open (os.path.join(directory1,"boards.txt"), 'w+') as fp: 
      fp.write(data) 
      os.system
      subprocess.Popen(r'explorer /select,"C:\Program Files (x86)\Arduino\hardware\arduino\avr\"')
else:
   print("path not found. Install arduino")
   
   