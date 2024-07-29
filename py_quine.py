this_source_code = "this_source_code = \"??\"\n\
print(this_source_code.replace(\"\\077\\077\", this_source_code.replace(\"\\\\\", \"\\\\\\\\\").replace(\"\\\"\", \"\\\\\\\"\").replace(\"\\n\", \"\\\\n\\\\\\n\")))"
print(this_source_code.replace("\077\077", this_source_code.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n\\\n")))
