// QUINE ITERATION: 0

#include <stdlib.h>
#include <stdio.h>

const char * const c_source = "//QUINE ITERATION: @@\n\
\n\
#include <stdlib.h>\n\
#include <stdio.h>\n\
\n\
const char * const c_source = \"??\";\n\
\n\
const char * const py_source = \"^^\";\n\
\n\
int main(void)\n\
{\n\
	for (const char *ptr = py_source; *ptr != '\\0'; ptr++)\n\
	{\n\
		if (*ptr == '?' && *(ptr + 1) == '?')\n\
		{\n\
			for (const char *inner_ptr = c_source; *inner_ptr != '\\0'; inner_ptr++)\n\
			{\n\
				switch (*inner_ptr) {\n\
					case '\\n': printf(\"\\\\n\\\\\"); break;\n\
					case '\\\\': case '\\\"': printf(\"\\\\\"); break;\n\
					// default: break;\n\
				}\n\
				printf(\"%c\", *inner_ptr);\n\
\n\
			}\n\
\n\
			ptr++;\n\
			continue;\n\
		}\n\
\n\
		if (*ptr == '^' && *(ptr + 1) == '^')\n\
		{\n\
			for (const char *inner_ptr = py_source; *inner_ptr != '\\0'; inner_ptr++)\n\
			{\n\
				switch (*inner_ptr) {\n\
					case '\\n': printf(\"\\\\n\\\\\"); break;\n\
					case '\\\\': case '\\\"': printf(\"\\\\\"); break;\n\
					// default: break;\n\
				}\n\
				printf(\"%c\", *inner_ptr);\n\
			}\n\
\n\
			ptr++;\n\
			continue;\n\
		}\n\
\n\
		if (*ptr == '@' && *(ptr + 1) == '@')\n\
		{\n\
			printf(\"%llu\", @@ull + 1);\n\
			ptr++;\n\
			continue;\n\
		}\n\
\n\
		printf(\"%c\", *ptr);\n\
	}\n\
\n\
	return EXIT_SUCCESS;\n\
}\n\
";

const char * const py_source = "# QUINE ITERATION: @@\n\
\n\
c_source = \"??\"\n\
py_source = \"^^\"\n\
print(c_source.replace(\"\\100\\100\", str(@@ + 1)).replace(\"\\077\\077\", c_source.replace(\"\\\\\", \"\\\\\\\\\").replace(\"\\\"\", \"\\\\\\\"\").replace(\"\\n\", \"\\\\n\\\\\\n\")).replace(\"\\136\\136\", py_source.replace(\"\\\\\", \"\\\\\\\\\").replace(\"\\\"\", \"\\\\\\\"\").replace(\"\\n\", \"\\\\n\\\\\\n\")))\n\
";

int main(void)
{
	for (const char *ptr = py_source; *ptr != '\0'; ptr++)
	{
		if (*ptr == '?' && *(ptr + 1) == '?')
		{
			for (const char *inner_ptr = c_source; *inner_ptr != '\0'; inner_ptr++)
			{
				switch (*inner_ptr) {
					case '\n': printf("\\n\\"); break;
					case '\\': case '\"': printf("\\"); break;
					// default: break;
				}
				printf("%c", *inner_ptr);
			}

			ptr++;
			continue;
		}

		if (*ptr == '^' && *(ptr + 1) == '^')
		{
			for (const char *inner_ptr = py_source; *inner_ptr != '\0'; inner_ptr++)
			{
				switch (*inner_ptr) {
					case '\n': printf("\\n\\"); break;
					case '\\': case '\"': printf("\\"); break;
					// default: break;
				}
				printf("%c", *inner_ptr);
			}

			ptr++;
			continue;
		}

		if (*ptr == '@' && *(ptr + 1) == '@')
		{
			printf("%llu", 0ull + 1);
			ptr++;
			continue;
		}

		printf("%c", *ptr);
	}

	return EXIT_SUCCESS;
}
