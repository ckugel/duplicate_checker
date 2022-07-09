# Duplicate file removal

this is a simple c++ app that removes all duplicate files from a given directory. It is recommended to make a backup
and to not give the program a folder that contains files you don't know what do. I ckugel am not reliable for any files
lost, run at your own risk.

src code can be found [here](https://github.com/ckugel/duplicate_checker)

exe can be found [here](https://drive.google.com/file/d/11Ew09jzUnjUsF64v5VqArPBv4aqRtLli/view?usp=sharing)

built using [c++ 20](https://en.wikipedia.org/wiki/C%2B%2B20) and coded in [clion](https://www.jetbrains.com/clion/)

How to run: 
pull this git repo
install g++:
Windows: https://www.youtube.com/watch?v=sXW2VLrQ3Bs
Windows if you have choco installed (put this in powershell): choco install mingw
Linux (debain): sudo apt install g++
Mac os: I don't know how but you can try this thing: https://github.com/kennethreitz/osx-gcc-installer

compile the files
in the terminal (any bash terminal) go to the src folder
run in the terminal to compile the files: g++ -std=c++2a *.cpp -o myProgram
execute the app: ./myProgram
