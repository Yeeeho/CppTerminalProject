echo start clang++ compiling

clang++ src/*.cpp -I./include -I./lib  -o Geimu.exe -static

echo compile ended