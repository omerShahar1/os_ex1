# how to use:

./cmp <file_1_name> <file_2_name> <br /> <br />
./copy <file_1_name> <file_2_name> <br /> <br />
./copy -l <file_1_link> <file_2_name> <br /> <br />
./encode <codec_type> <message> <br /><br />
./decode <codec_type> <message> <br /><br />





# Terminal examples: 

### make all:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make all<br />
gcc -Wall -g -o cmp cmp.c<br />
gcc -Wall -g -o copy copy.c<br />
gcc -Wall -g -o libcodec1.so -shared -fPIC codec1.c<br />
gcc -Wall -g -o libcodec2.so -shared -fPIC codec2.c<br />
gcc -Wall -g encode.c -ldl -o encode<br />
gcc -Wall -g decode.c -ldl -o decode<br />


### cmp:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./cmp test1.txt test2.txt<br />
Identical<br />


### copy:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./copy test1.txt test3.txt<br />
file contents is copied<br />


### encode codec1:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec1 LALALA123<br />
lalala123<br />


### encode codec2:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ ./encode codec2 LALALA123<br />
���������<br />


### make clean:<br />
omer@DESKTOP-SCLMDED:~/os_class/ex1$ make clean<br />
rm -f encode decode cmp copy libcodec1.so libcodec2.so<br />

<br /><br /><br />
*used internet code from:
* https://man7.org/linux/man-pages/man2/readlink.2.html
* https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/

