#!/usr/bin/bash

day=$(date +%H:%m:%S)
currentdir=$(pwd)
echo "Time now $day"
Name="Tuan Anh"
echo "HelloWorld $Name" # in ra man hinh
echo "PATH: $currentdir

x=1
y=2


echo ${x} # in ra gia tri cua x ,y
echo ${y}
echo $(($x + $y))
echo "scale=2;5/2" | bc # in ra 2 chu so thap phan

out="bash.txt"
touch "$out"
echo "$(ls *.txt)" # in ra cac file .txt
#read name class
read -p"Nhap name: " name
read -p"Nhap class: " class
echo "my name is $name" #$1 $2la du kieu nhap tu ngoai vao
echo "my class is $class"
echo $@ #in ra  tat ca du lieu truyen vao khi o giua la dau cach
#IFS=:
#echo "$*"
touch "file.txt"
echo "$y" > "file.txt"
a=$(cat file.txt)
b=10

if [ $a = $b ] ; then
    echo OK
else
    echo not OK
    echo $a
    echo $b
fi

name="Tuan Anh Dang"
#IFS= "."
bien="1.2.3.4.5.6"
echo "$name" > "$out" #truyen du lieu $name vao file duoc luu bang bien out
echo "$bien" >> "$out"
echo "$day" >> "$out"


exit 0