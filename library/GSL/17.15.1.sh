# !/bin/sh
gcc -Wall -c 17.15.1.c
gcc 17.15.1.o -lgsl -lgslcblas -lm -o 17.15.1

gcc -Wall -c FFT.c
gcc FFT.o -lgsl -lgslcblas -lm -o FFT

gcc -Wall  -c polynomial.c
gcc  polynomial.o -lgsl -lgslcblas -lm -o  polynomial

echo "⛳️ Runing the 17.15.1"
./17.15.1

echo "⛳️ Runing the FFT"
./FFT

echo "⛳️ Runing the polynomial"
./polynomial

rm 17.15.1
rm FFT
rm polynomial
rm *.o
