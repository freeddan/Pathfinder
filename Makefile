PROG_NAME = pathfinder
CFLAGS = -std=c11 -Wall -Wextra -Werror

.PHONY: all clean reinstall uninstall

all: $(PROG_NAME)

$(PROG_NAME):
	make -C libmx
	clang $(CFLAGS) src/*.c -c
	mkdir obj
	mv *.o obj
	clang $(CFLAGS) obj/*.o libmx/libmx.a -o $(PROG_NAME)

clean:
	rm -rf obj libmx/obj

uninstall: clean
	rm -rfv libmx/libmx.a $(PROG_NAME)

reinstall: uninstall $(PROG_NAME)