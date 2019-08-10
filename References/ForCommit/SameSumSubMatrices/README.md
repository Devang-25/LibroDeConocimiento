Visitor

## PURPOSE
The CHALLENGE: Given a matrix of size NxM containing positive and negative numbers, write a program that finds all square sub-matrices where the sum of each column, row, and diagonal are the same. Input matrix is stored in a text file matrix.txt. Output should display all sub-matrices from smallest to largest (excluding 1x1 matrices), separated by CR/LF and should be saved in a text file named output.txt.

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
3. Boost
    ~~~
    sudo apt install libboost-all-dev
    ~~~

## BUILDING
Using GNU Make
~~~
cd SameSumSubMatrices
make
~~~
Using solely GNU Compiler Collection (GCC)
~~~
cd SameSumSubMatrices
g++ src/*.cpp -o a.out -I. -std=c++17 -g -Wall -Wextra -Werror -pedantic
~~~

## USAGE:
~~~
./a.out [OPTIONAL: ./Path/To/Matrix/File] [OPTIONAL: --printtoscreen]
~~~
Note: If the ./Path/To/Matrix/File is not entered, default file to read would be ./MatrixFiles/matrix.txt

## RUNNING
Using GNU Make
~~~
cd SameSumSubMatrices
build/a.out
build/a.out ../SomeDirectory/MyMatrix.txt
build/a.out ../SomeDirectory/MyMatrix.txt --printtoscreen
~~~
Using solely GNU Compiler Collection (GCC)
~~~
cd SameSumSubMatrices
./a.out
./a.out ../SomeDirectory/MyMatrix.txt
./a.out ../SomeDirectory/MyMatrix.txt --printtoscreen
~~~
Output file will be in current working directory with file name ./output.txt

## EXAMPLE RUN
~~~
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs$ cd SameSumSubMatrices/
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ ls
Makefile  MatrixFiles  README.md  src
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ make
mkdir -p ./build
g++ -Isrc -std=c++17 -g -Wall -Wextra -Werror -pedantic -c src/main.cpp -o build/main.o
g++ -Isrc -std=c++17 -g -Wall -Wextra -Werror -pedantic -c src/FileHandler.cpp -o build/FileHandler.o
g++ -Isrc -std=c++17 -g -Wall -Wextra -Werror -pedantic -c src/MagicSquareFinder.cpp -o build/MagicSquareFinder.o
g++ -Isrc -std=c++17 -g -Wall -Wextra -Werror -pedantic -c src/MatrixOutputter.cpp -o build/MatrixOutputter.o
g++ -Isrc -std=c++17 -g -Wall -Wextra -Werror -pedantic build/main.o build/FileHandler.o build/MagicSquareFinder.o build/MatrixOutputter.o -o build/a.out
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ ls
build  Makefile  MatrixFiles  README.md  src
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ ls build/
a.out  FileHandler.o  MagicSquareFinder.o  main.o  MatrixOutputter.o
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ build/a.out

Execution started
File ./MatrixFiles/matrix.txt was successfully read
Enter number of rows: 
Enter number of columns: 
Enter 4 x 4 matrix

Execution finished
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ ls
build  Makefile  MatrixFiles  output.txt  README.md  src
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ cat MatrixFiles/matrix.txt 
-1 0 3 3
2 4 3 3
4 3 2 5
3 2 4 -6nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ cat output.txt 

Matrix
 -1 0 3 3
 2 4 3 3
 4 3 2 5
 3 2 4 -6

SubMatrices
 3 3
 3 3

 2 4 3
 4 3 2
 3 2 4
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ build/a.out --printtoscreen

Execution started
File ./MatrixFiles/matrix.txt was successfully read
Enter number of rows: 
Enter number of columns: 
Enter 4 x 4 matrix

Matrix
 -1 0 3 3
 2 4 3 3
 4 3 2 5
 3 2 4 -6

SubMatrices
 3 3
 3 3

 2 4 3
 4 3 2
 3 2 4

Execution finished
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ build/a.out MatrixFiles/matrix2.txt --printtoscreen

Execution started
File MatrixFiles/matrix2.txt was successfully read
Enter number of rows: 
Enter number of columns: 
Enter 7 x 9 matrix

Matrix
 1 2 3 4 5 2 2 8 9
 9 2 4 3 5 2 2 2 1
 1 4 3 2 5 6 7 8 9
 1 3 2 4 2 7 6 1 4
 3 8 4 8 9 5 1 2 5
 5 7 2 2 4 3 8 5 5
 9 8 2 2 5 9 8 5 5

SubMatrices
 2 2
 2 2

 2 2
 2 2

 5 5
 5 5

 2 4 3
 4 3 2
 3 2 4

 2 7 6
 9 5 1
 4 3 8

Execution finished
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ cat MatrixFiles/matrix2.txt 
1 2 3 4 5 2 2 8 9
9 2 4 3 5 2 2 2 1
1 4 3 2 5 6 7 8 9
1 3 2 4 2 7 6 1 4
3 8 4 8 9 5 1 2 5
5 7 2 2 4 3 8 5 5
9 8 2 2 5 9 8 5 5nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/SameSumSubMatrices$ cat output.txt 

Matrix
 1 2 3 4 5 2 2 8 9
 9 2 4 3 5 2 2 2 1
 1 4 3 2 5 6 7 8 9
 1 3 2 4 2 7 6 1 4
 3 8 4 8 9 5 1 2 5
 5 7 2 2 4 3 8 5 5
 9 8 2 2 5 9 8 5 5

SubMatrices
 2 2
 2 2

 2 2
 2 2

 5 5
 5 5

 2 4 3
 4 3 2
 3 2 4

 2 7 6
 9 5 1
 4 3 8
~~~
