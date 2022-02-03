make
./cal.exe "cal.in" > cal.out
echo -------------------------------------------
echo Printing the output from cal.out
cat cal.out
echo Execution of the cal.in is completed --- EOL
echo -------------------------------------------
echo Please enter the string to search ....
echo [Make a note of excluding quotation signs when entering the string]
read varname
cat cal.out | fgrep -h -i "$varname"
