@echo off

g++ .\main.cpp .\student.cpp -I. -o a


if %errorlevel% neq 0 (
    echo Compilation failed. Exiting.
    exit 
)

.\a.exe
pause