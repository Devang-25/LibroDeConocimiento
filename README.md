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
5. Boost
    ~~~
    sudo apt install libboost-all-dev
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
src/libro_src --algorithms
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
[ChallengesController] ID:7 Name:CorrectPath
[ChallengesController] ID:8 Name:EightQueens
[ChallengesController] ID:9 Name:KaprekarsConstant
[ChallengesController] ID:10    Name:ChessboardTraveling
[ChallengesController] ID:11    Name:MaximalSquare
[ChallengesController] ID:12    Name:MultiplesOf3And5
[ChallengesController] ID:13    Name:EvenFibonacciNumbers
[ChallengesController] ID:14    Name:LargestPrimeFactor
[ChallengesController] ID:15    Name:LargestPalindromeProduct
[ChallengesController] ID:16    Name:SmallestMultiple
[ChallengesController] ID:17    Name:LargestProductInASeries
[ChallengesController] 
[ChallengesController] What challenge do you want to run?
[ChallengesController]  - To see list of available challenges, enter <listall>
[ChallengesController]  - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>
[ChallengesController]  - To exit, enter <exit>
[UserInputHandler] Input:10

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
[ChallengesController] 
[ChallengesController] What challenge do you want to run?
[ChallengesController]  - To see list of available challenges, enter <listall>
[ChallengesController]  - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>
[ChallengesController]  - To exit, enter <exit>
[UserInputHandler] Input:CorrectPath

[CorrectPath] Have the function CorrectPath(str) read the str parameter being passed, which will represent the movements made in a 5x5 grid of cells starting from the top left position.
[CorrectPath] The characters in the input string will be entirely composed of: r, l, u, d, ?.
[CorrectPath] Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down.
[CorrectPath] Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the grid all the way to the bottom right without touching previously travelled on cells in the grid.
[CorrectPath] For example: if str is r?d?drdd then your program should output the final correct string that will allow a path to be formed from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd.
[CorrectPath] There will only ever be one correct path and there will always be at least one question mark within the input string.
[CorrectPath] Sample Test Cases
[CorrectPath] Input: ???rrurdr?
[CorrectPath] Output:dddrrurdrd
[CorrectPath] Input: drdr??rrddd?
[CorrectPath] Output:drdruurrdddd
[CorrectPath] Input: ??rr???rrddd????rr??
[CorrectPath] Output: ddrrulurrdddllldrrrr
[UserInputHandler] Input:??rr???rrddd????rr??

[CorrectPath] Grid
[CorrectPath]     00 01 02 03 04
[CorrectPath]     10 11 12 13 14
[CorrectPath]     20 21 22 23 24
[CorrectPath]     30 31 32 33 34
[CorrectPath]     40 41 42 43 44
[CorrectPath] Input                                             = ??rr???rrddd????rr??
[CorrectPath] Output
[CorrectPath]     correctPathWithRepeatingNodes_shortestPath    = rrrrdllrrddd
[CorrectPath]     correctPathWithoutRepeatingNodes_shortestPath = rdrrdddr
[CorrectPath]     correctPathWithoutRepeatingNodes              = ddrrulurrdddllldrrrr
[CorrectPath] Result: ddrrulurrdddllldrrrr
[ChallengesController]
[ChallengesController] What challenge do you want to run?
[ChallengesController]  - To see list of available challenges, enter <listall>
[ChallengesController]  - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>
[ChallengesController]  - To exit, enter <exit>
[UserInputHandler] Input:exit

[main] End of execution
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
