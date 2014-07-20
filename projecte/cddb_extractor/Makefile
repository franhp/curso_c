all: cddb_extractor extract_cds extract_songs neteja

main.o: main.c
		gcc -w -g -c main.c

cddb_extractor: main.o
		gcc -w -g main.o -o cddb_extractor

extract_cds.o: extract_cds.c
		gcc -w -g -c extract_cds.c

extract_cds: extract_cds.o
		gcc -w -g extract_cds.o -o extract_cds

extract_songs.o: extract_songs.c
		gcc -w -g -c extract_songs.c

extract_songs: extract_songs.o
		gcc -w -g extract_songs.o -o extract_songs

clean:
		rm -f cddb_extractor extract_songs extract_cds *.o
neteja:
		rm -r *.o		
main_mac.o: main_mac.c
	gcc -w -g -c main_mac.c
mac: main_mac.o
	gcc -w -g main_mac.o -o cddb_extractor && make extract_cds && make extract_songs && make neteja
