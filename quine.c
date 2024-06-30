#include <stdlib.h>
#include <stdio.h>

const char * const this_source_code = "#include <stdlib.h>\n\
#include <stdio.h>\n\
\n\
const char * const this_source_code = \"??\";\n\
\n\
void print_quine_output(const char * const output_template)\n\
{\n\
	for (const char *ptr = output_template; *ptr != '\\0'; ptr++)\n\
	{\n\
		if (*ptr == '?' && *(ptr + 1) == '?')\n\
		{\n\
			for (const char *inner_ptr = output_template; *inner_ptr != '\\0'; inner_ptr++)\n\
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
		printf(\"%c\", *ptr);\n\
	}\n\
}\n\
\n\
int main(void) {\n\
	print_quine_output(this_source_code);\n\
	return EXIT_SUCCESS;\n\
}\n\
";

void print_quine_output(const char * const output_template)
{
	for (const char *ptr = output_template; *ptr != '\0'; ptr++)
	{
		if (*ptr == '?' && *(ptr + 1) == '?')
		{
			for (const char *inner_ptr = output_template; *inner_ptr != '\0'; inner_ptr++)
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

		printf("%c", *ptr);
	}
}

int main(void) {
	print_quine_output(this_source_code);
	return EXIT_SUCCESS;
}
