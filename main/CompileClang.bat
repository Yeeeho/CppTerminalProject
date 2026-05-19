echo start clang++ compiling

clang++ -x c++-header -I./lib include/pch.h -o include/pch.h.gch -static

clang++ src/*.cpp -I./include -I./lib -include include/pch.h -o Geimu.exe -static -H

echo compile ended