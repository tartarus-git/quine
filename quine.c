#include <stdlib.h>
#include <stdio.h>

const char * const this_source_code = "#include <stdlib.h>\n\
#include <stdio.h>\n\
\n\
const char * const this_source_code = \"??\";\n\
\n\
void print_quine_output(const char * const output_template) {\n\
	for (const char *ptr = output_template; *ptr != '\\0'; ptr++) {\n\
		if (*ptr == '?' && *(ptr + 1) == '?') {\n\
			for (const char *inner_ptr = output_template; *inner_ptr != '\\0'; inner_ptr++) {\n\
				if (*inner_ptr == '\\n') { printf(\"\\\\n\\\\\"); }\n\
				else if (*inner_ptr == '\\\\' || *inner_ptr == '\\\"') { printf(\"\\\\\"); }\n\
				printf(\"%c\", *inner_ptr);\n\
			}\n\
			ptr++;\n\
			continue;\n\
		}\n\
		printf(\"%c\", *ptr);\n\
	}\n\
}\n\
\n\
int main(void) {\n\
	print_quine_output(this_source_code);\n\
	return EXIT_SUCCESS;\n\
}\n\
";

void print_quine_output(const char * const output_template) {
	for (const char *ptr = output_template; *ptr != '\0'; ptr++) {
		if (*ptr == '?' && *(ptr + 1) == '?') {
			for (const char *inner_ptr = output_template; *inner_ptr != '\0'; inner_ptr++) {
				if (*inner_ptr == '\n') { printf("\\n\\"); }
				else if (*inner_ptr == '\\' || *inner_ptr == '\"') { printf("\\"); }
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
