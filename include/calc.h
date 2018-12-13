#ifndef CALC_H
#define CALC_H

int32 strToInt(string str, uint8 len) 
{ 
    int32 res = 0;
	uint16 i = 0;
	if (str[0] == '-') i = 1;
    for (i; i < len && str[i] != '\0'; ++i) 
        res = res*10 + str[i] - '0'; 
    if (str[0] == '-')
		return -res;
	else
		return res;
}

void calculator() {
	int32 a, b, res;
	char op;
	
	print("KUETsoft fx-038 KS calculator\n");
	print("a = +\n");
	print("s = -\n");
	print("m = *\n");
	print("d = /\n");
	print("exit = return to OS\n");
	while (1) {
		print("> ");
		string inp = readStr();
		if (strEql(inp, "exit")) break;
		uint8 i=0;
		while (inp[i] >= '0' && inp[i] <= '9' || inp[i] == '-') i++;
		a = strToInt(inp, i);
		
		while (inp[i] != 0 && inp[i] != 'a' && inp[i] != 's' && inp[i] != 'm' && inp[i] != 'd') i++;
		if (inp[i] == 0) {
			print("Input Error\n");
			continue;
		}
		op = inp[i];
		
		while (inp[i] != 0 && inp[i] != '-' && (inp[i] < '0' || inp[i] > '9')) i++;
		if (inp[i] == 0) {
			print("Input Error\n");
			continue;
		}
		b = strToInt((string) (inp + i), 999);
		
		if (op == 'a') res = a + b;
		if (op == 's') res = a - b;
		if (op == 'm') res = a * b;
		if (op == 'd') res = a / b;
		
		printnum(res);
		print("\n");
	}
}

#endif
