echo start clang++ compiling

g++ src/*.cpp -I./include -I./lib  -o Geimu.exe -static

echo compile ended