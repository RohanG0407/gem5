GEM5_PATH = /home/rgangar/Documents/gem5/
ISA = arm64
GXX = aarch64-linux-gnu-gcc
OBJDUMP = aarch64-linux-gnu-objdump
CFLAGS = -march=armv8.4-a -Wall -I$(GEM5_PATH)/include
LDFLAGS = -L$(GEM5_PATH)/util/m5/build/$(ISA)/out -lm5

all: hello-static hello-dynamic hello-static.S hello-dynamic.S

hello-static: hello.c
	$(GXX) $(CFLAGS) -o $@ $< $(LDFLAGS) -static

hello-dynamic: hello.c
	$(GXX) $(CFLAGS) -o $@ $< $(LDFLAGS)

hello-static.S: hello-static
	$(OBJDUMP) -d $< > $@

hello-dynamic.S: hello-dynamic
	$(OBJDUMP) -d $< > $@

clean:
	rm -f hello-static hello-dynamic hello-static.S hello-dynamic.S
