
# Scheduling in CPU 
After learning about the scheduler in our Linux class and how it manages CPU time among processes, I was inspired to implement this concept using the C language.


I implemented three types:

FCFS : First Come First Served

SJF : Short Job First

PPF : Priority Process First

After executing this program, the GANTT CHART will display on the screen, illustrating the amount of time the process was allocated in the CPU.


## how to run project 
1- Download my repo in your computer

2- run the command 

make sure the make command is installed
```bash
 $ sudo apt-get install make

```
to build the executable file called global.exe:
```bash
 $  make

```
read the manual:
```bash
 $ ./exe/global.exe option 

```
for option : 

```bash
 $ ./exe/global.exe  {fcfs | spf | pty}

```
