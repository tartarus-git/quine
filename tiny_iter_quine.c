// QUINE ITERATION: 0

#include <stdio.h>
char*a="// QUINE ITERATION: @@\n\
\n\
#include <stdio.h>\n\
char*a=\"??\";\n\
int main(){for(char*b=a;*b!='\\0';b++){if(*b=='?'&&*(b+1)=='?'){for(char*c=a;*c!='\\0';c++){switch(*c){\n\
case'\\n':printf(\"\\\\n\\\\\");break;case'\\\\':case'\\\"':printf(\"\\\\\");break;}printf(\"%c\",*c);}b++;\n\
continue;}if(*b=='@'&&*(b+1)=='@'){printf(\"%llu\",@@ull+1);b++;continue;}printf(\"%c\",*b);}return 0;}\n\
";
int main(){for(char*b=a;*b!='\0';b++){if(*b=='?'&&*(b+1)=='?'){for(char*c=a;*c!='\0';c++){switch(*c){
case'\n':printf("\\n\\");break;case'\\':case'\"':printf("\\");break;}printf("%c",*c);}b++;
continue;}if(*b=='@'&&*(b+1)=='@'){printf("%llu",0ull+1);b++;continue;}printf("%c",*b);}return 0;}
