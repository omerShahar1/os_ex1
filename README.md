Terminal examples: 

make all:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make all
gcc -Wall -g -o cmp cmp.c
gcc -Wall -g -o copy copy.c
gcc -Wall -g -o libcodec1.so -shared -fPIC codec1.c
gcc -Wall -g -o libcodec2.so -shared -fPIC codec2.c
gcc -Wall -g encode.c -ldl -o encode
gcc -Wall -g decode.c -ldl -o decode


cmp:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./cmp test1.txt test2.txt
Identical


copy:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./copy test1.txt test3.txt
file contents is copied


encode codec1:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec1 LALALA123
lalala123


encode codec2:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec2 LALALA123
���������


make clean:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make clean
rm -f encode decode cmp copy libcodec1.so libcodec2.so
