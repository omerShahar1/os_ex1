Terminal examples: 

make all:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make all
gcc -Wall -g -o cmp cmp.c
gcc -Wall -g -o copy copy.c
gcc -Wall -g -o libcodec1.so -shared -fPIC codec1.c
gcc -Wall -g -o libcodec2.so -shared -fPIC codec2.c
gcc -Wall -g encode.c -ldl -o encode
gcc -Wall -g decode.c -ldl -o decode


cmp:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./cmp test1.txt test2.txt
Identical


copy:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./copy test1.txt test3.txt
file contents is copied


encode codec1:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec1 LALALA123
lalala123


encode codec2:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec2 LALALA123
���������


make clean:
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make clean
rm -f encode decode cmp copy libcodec1.so libcodec2.so
