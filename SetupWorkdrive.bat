@echo off

cd /D "%~dp0"

IF exist "P:\Example\" (
	echo Removing existing link P:\Example
	rmdir "P:\Example\"
)

echo Creating link P:\Example
mklink /J "P:\Example\" "%cd%\Example\"

echo Done