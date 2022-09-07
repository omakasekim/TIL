#!/bin/sh
rm-rfcscope.files
find . \( -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.ic' -o -name '*.h' -o -name '*.hpp' -o -name '*.s' -o -name '*.S' \) -print > cscope.filescscope-b -q -k
