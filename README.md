# MuttonAutoClicker
MuttonAutoClicker is a basic autoclicker made using C++ raylib and windows.h. It will invoke a left-click once every 100ms.
<br>
Recorded cps: 10
<br>
Press the button to start!
<br>
Optionally: CTRL+X to start and stop.

# Installation Guide
## Option 1: Github releases tab.
1. Go to the releases tab and click on the latest release
<img src="https://github.com/user-attachments/assets/b78b166a-4e55-46c3-ab51-eb8a81f55761">
<br>
2. If prompted a Windows security prompt, ignore it and press run anyways. I'm currently trying to fix this issue.

## Option 2: Copy from github
1. Clone repository
```
git clone https://github.com/Mutton9558/MuttonAutoClicker
cd MuttonAutoClicker
```
2. Compile the code
```
g++ gui.cpp autoclicker.cpp -o MuttonAutoClicker.exe -lraylib -lgdi32 -lwinmm -mwindows
```
3. Run application
```
./MuttonAutoClicker.exe
```
This option should avoid a windows security prompt.

# UI view
<img src="https://github.com/user-attachments/assets/9e10b10f-bd40-46d6-9594-b25037967bd1">
