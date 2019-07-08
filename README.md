LibroDeConocimiento

## PURPOSE
This program aims to try out different concepts within the C++ software development that is often overlooked when working on already established projects.

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. Git (optional if you just prefer to do a download and extract from GitHub)
    ~~~
    sudo apt install git
    ~~~
3. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
4. CMake
    ~~~
    sudo apt install cmake
    ~~~

## BUILDING
~~~
git clone https://github.com/nponcian/LibroDeConocimiento.git
cd LibroDeConocimiento
mkdir -p build && cd build
cmake ..
~~~

## RUNNING
~~~
cd LibroDeConocimiento/build
cmake ..
make
src/libro_src --help
src/libro_src --challenges
~~~
Example
~~~
src/libro_src --challenges

[main] Input to main is --challenges or --challenges
[ChallengesController] 
[ChallengesController] What challenge do you want to run?
[ChallengesController]  - To see list of available challenges, enter <listall>
[ChallengesController]  - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>
[ChallengesController]  - To exit, enter <exit>
[UserInputHandler] Input:listall

[ChallengesController] ID:0 Name:FirstReverse
[ChallengesController] ID:1 Name:FirstFactorial
[ChallengesController] ID:2 Name:LongestWord
[ChallengesController] ID:3 Name:LetterChanges
[ChallengesController] ID:4 Name:SimpleAdding
[ChallengesController] ID:5 Name:LetterCapitalize
[ChallengesController] ID:6 Name:SimpleSymbols
[ChallengesController] ID:7 Name:KaprekarsConstant
[ChallengesController] ID:8 Name:ChessboardTraveling
[ChallengesController] ID:9 Name:MultiplesOf3And5
[ChallengesController] ID:10    Name:EvenFibonacciNumbers
[ChallengesController] ID:11    Name:LargestPrimeFactor
[ChallengesController] 
[ChallengesController] What challenge do you want to run?
[ChallengesController]  - To see list of available challenges, enter <listall>
[ChallengesController]  - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>
[ChallengesController]  - To exit, enter <exit>
[UserInputHandler] Input:8

[ChessboardTraveling] Have the function ChessboardTraveling(str) read str which will be a string consisting of the location of a space on a standard 8x8 chess board with no pieces on the board along with another space on the chess board.
[ChessboardTraveling] The structure of str will be the following:
[ChessboardTraveling] "(x y)(a b)" where (x y) represents the position you are currently on with x and y ranging from 1 to 8 and (a b) represents some other space on the chess board with a and b also ranging from 1 to 8 where a > x and b > y.
[ChessboardTraveling] Your program should determine how many ways there are of traveling from (x y) on the board to (a b) moving only up and to the right.
[ChessboardTraveling] For example: if str is (1 1)(2 2) then your program should output 2 because there are only two possible ways to travel from space (1 1) on a chessboard to space (2 2) while making only moves up and to the right.
[ChessboardTraveling] Sample Test Cases
[ChessboardTraveling] Input:"(1 1)(3 3)"
[ChessboardTraveling] Output:6
[ChessboardTraveling] Input:"(2 2)(4 3)"
[ChessboardTraveling] Output:3
[UserInputHandler] Input:(2 2)(4 3)

[ChessboardTraveling] Node : 2 2
[ChessboardTraveling]       2 3
[ChessboardTraveling]           3 3
[ChessboardTraveling]               4 3
[ChessboardTraveling]       3 2
[ChessboardTraveling]           3 3
[ChessboardTraveling]               4 3
[ChessboardTraveling]           4 2
[ChessboardTraveling]               4 3
[ChessboardTraveling] Result: 3
~~~

## TESTING
~~~
cd LibroDeConocimiento/build
cmake ..
make
test/libro_test
~~~
To display result of specific testcase
~~~
cd LibroDeConocimiento/build
../Tools/GoogleTestResultReader/setup
../Tools/GoogleTestResultReader/GoogleTestResultReader/readgtest test/libro_test --all
../Tools/GoogleTestResultReader/GoogleTestResultReader/readgtest test/libro_test --test FactorialTest
~~~

Feliz aprendizaje mis AMIGOS!
