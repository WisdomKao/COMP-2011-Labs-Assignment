import subprocess
import glob
import os

os.chdir(__file__.rstrip("lab6.py"))

try :
  os.remove("lab6.exe")
except :
  pass

subprocess.run("g++ --std=c++11 -c transpose.cpp", shell = True)
subprocess.run("g++ --std=c++11 -c add.cpp", shell = True)
subprocess.run("g++ --std=c++11 -c multiply.cpp", shell = True)
subprocess.run("g++ --std=c++11 -c horizontal_flip_2D_array.cpp", shell = True)
subprocess.run("g++ --std=c++11 -c lab6.cpp", shell = True)
subprocess.run("g++ --std=c++11 -o main lab6.o add.o multiply.o transpose.o horizontal_flip_2D_array.o", shell = True)

fn = "main"

if not(os.path.isfile("main.exe")) :
  subprocess.run("clear", shell = True)    # clear the terminal
  os.system("command g++ --std=c++11 -o main lab6.o add.o multiply.o transpose.o horizontal_flip_2D_array.o")    #show the compilation error and end the program
else :

  input_cases = glob.glob("./**/input*.txt", recursive = True)    # list of sample input files
  print("Testing for : " + fn)

  try : 
    for case in input_cases :
      c = case.split('\\')
      address = ''
      cn = c[len(c)-1]    # the filename of the input file
      for i in range(1, len(c)-1) :
        address += c[i] + '/'
      address.rstrip('/')    # the address of the input file
      
      subprocess.run(fn + " < " + address + cn + " > myOutput" + cn[5:], shell = True)    # generate myOutput file by given sample input case

      with open("myOutput" + cn[5:]) as myOut, open(address + "output" + cn[5:]) as out :
        if (myOut.read() == out.read()) :
          print(cn + " is okay.")
        else :
          print(cn + " is WRONG!!!!")    # compare myOutput file with the sample output file

    print("DONE")
  except :
    print("testing failed")
