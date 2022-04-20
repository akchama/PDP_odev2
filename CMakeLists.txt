cmake_minimum_required(VERSION 3.22)
project(odev2 C)

set(CMAKE_C_STANDARD 99)

add_executable(odev2 src/Test.c src/Oyun.c include/Oyun.h src/Yardimci.c include/Yardimci.h src/Kisi.c include/Kisi.h src/Dosya.c include/Dosya.h)
