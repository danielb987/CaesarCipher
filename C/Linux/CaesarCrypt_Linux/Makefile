CaesarCrypt.o: CaesarCrypt.c
	gcc -c -fPIC -I ../../headers -I /usr/lib/jvm/java-11-openjdk-amd64/include/ -I /usr/lib/jvm/java-11-openjdk-amd64/include/linux/ -o CaesarCrypt.o CaesarCrypt.c

libcaesarcrypt.so: CaesarCrypt.o
	gcc -shared -fPIC -Wl,-soname,libcaesarcrypt.so.1 -o libcaesarcrypt.so.1.1.0 CaesarCrypt.o -lc


all: libcaesarcrypt.so
	ln -s libcaesarcrypt.so.1.1.0 libcaesarcrypt.so

