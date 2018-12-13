#ifndef SCREEN_SUBSTR_H
#define SCREEN_SUBSTR_H

void screen_substr(string str) {
    string vidmem = (string) 0xb8000;
	uint8 len = strlength(str);
	uint32 i, j, found;
	
	for (i=0; i<(cursorY-1)*sw*2-len*2; i+=2) {
		found = 1;
		for (j=0; j<len; j++) {
			if (vidmem[i+j*2] != str[j]) {
				found = 0;
				break;
			}
		}
		if (found) break;
		found = 0;
	}
	
	if (found) {
		for (j=0; j<len*2; j+=2) {
			vidmem[i+j+1] = 0xF0;
		}
		print("Substring found and marked\n");
	} else {
		print("Substring not found\n");
	}
	
}



#endif
