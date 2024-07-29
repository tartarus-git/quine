// QUINE ITERATION: 0

#include <stdlib.h>
#include <stdio.h>

const char * const c_source = "// QUINE ITERATION: @@\n\
\n\
#include <stdlib.h>\n\
#include <stdio.h>\n\
\n\
const char * const c_source = \"??\";\n\
\n\
const char * const py_source = \"^^\";\n\
\n\
void print_quine_substitution(const char * const source)\n\
{\n\
	for (const char *ptr = source; *ptr != '\\0'; ptr++)\n\
	{\n\
		switch (*ptr) {\n\
			case '\\n': printf(\"\\\\n\\\\\"); break;\n\
			case '\\\\': case '\\\"': putchar('\\\\'); break;\n\
			// default: break;\n\
		}\n\
		putchar(*ptr);\n\
	}\n\
}\n\
\n\
int main(void)\n\
{\n\
	for (const char *ptr = py_source; *ptr != '\\0'; ptr++)\n\
	{\n\
		if (*ptr == '?' && *(ptr + 1) == '?')\n\
		{\n\
			print_quine_substitution(c_source);\n\
			ptr++;\n\
			continue;\n\
		}\n\
\n\
		if (*ptr == '^' && *(ptr + 1) == '^')\n\
		{\n\
			print_quine_substitution(py_source);\n\
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
		putchar(*ptr);\n\
	}\n\
\n\
	putchar('\\n');\n\
\n\
	return EXIT_SUCCESS;\n\
}";

const char * const py_source = "# QUINE ITERATION: @@\n\
\n\
c_source = \"??\"\n\
\n\
py_source = \"^^\"\n\
\n\
def create_quine_substitution(source):\n\
	return source.replace(\"\\\\\", \"\\\\\\\\\") \\\n\
		     .replace(\"\\\"\", \"\\\\\\\"\") \\\n\
		     .replace(\"\\n\", \"\\\\n\\\\\\n\")\n\
\n\
print(c_source.replace(\"\\100\\100\", str(@@ + 1)) \\\n\
	      .replace(\"\\136\\136\", create_quine_substitution(py_source)) \\\n\
	      .replace(\"\\077\\077\", create_quine_substitution(c_source), 1))";

void print_quine_substitution(const char * const source)
{
	for (const char *ptr = source; *ptr != '\0'; ptr++)
	{
		switch (*ptr) {
			case '\n': printf("\\n\\"); break;
			case '\\': case '\"': putchar('\\'); break;
			// default: break;
		}
		putchar(*ptr);
	}
}

int main(void)
{
	for (const char *ptr = py_source; *ptr != '\0'; ptr++)
	{
		if (*ptr == '?' && *(ptr + 1) == '?')
		{
			print_quine_substitution(c_source);
			ptr++;
			continue;
		}

		if (*ptr == '^' && *(ptr + 1) == '^')
		{
			print_quine_substitution(py_source);
			ptr++;
			continue;
		}

		if (*ptr == '@' && *(ptr + 1) == '@')
		{
			printf("%llu", 0ull + 1);
			ptr++;
			continue;
		}

		putchar(*ptr);
	}

	putchar('\n');

	return EXIT_SUCCESS;
}
