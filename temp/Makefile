CC = $(CLANG_PREFIX)clang
LAB_OPTS = -I./src
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no --trace-children=no --error-exitcode=1

all:	
	make clean prep compile 
clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin 

main.bin: main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

format:
	         find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;

# TODO: clang-tidy; scan-build