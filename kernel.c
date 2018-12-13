#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/game.h"
#include "include/calc.h"
#include "include/screen_substr.h"
kmain()
{
       clearScreen();
	   
       print("Welcome to Teligati operating system\nUser login\n");
	   string username = "kuet";
	   string password = "cse";
	   
	   string inp = 0;
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Login successful\n");
			   break;
		   }
		   print("Wrong username and password. Try again\n");
	   }
	   
       while (1)
       {
			print("kuet> ");
			inp = readStr();
			if(strEql(inp,"cmd"))
			{
					print("You are allready in cmd\n");
			}
			else if(strEql(inp,"clear"))
			{
					clearScreen();
			}
			else if(strEql(inp,"game"))
			{
					clearScreen();
					game();
					clearScreen();
			}
			else if(strEql(inp,"calc"))
			{
					clearScreen();
					calculator();
					clearScreen();
			}
			else if(strEql(inp,"substr"))
			{
				print("String to match: ");
				inp = readStr();
				screen_substr(inp);
			}
			else if(strEql(inp,"strlen"))
			{
				print("Enter string: ");
				inp = readStr();
				print("The length of string is: ");
				printnum(strlength(inp));
				print("\n");
			}
			else if(strEql(inp,"clearline"))
			{
				print("Enter line no: ");
				inp = readStr();
				uint8 lineno = (uint8) strToInt(inp, 999);
				if (lineno < 1 || lineno > cursorY-1) {
					print("Line no is out of screen\n");
					continue;
				}
				clearLine(lineno-1, lineno);
				uint8 i,j;
				string vidmem = (string)0xb8000; 
				for (i = lineno-1 +1; i<=cursorY; i++) {
					for (j = 0; j<sw; j++) {
						vidmem[((i-1)*sw+j)*2] = vidmem[(i*sw+j)*2];
						vidmem[((i-1)*sw+j)*2+1] = vidmem[(i*sw+j)*2+1];
					}
				}
				cursorY--;
				updateCursor();
			}
			else if(strEql(inp,"shutdown"))
			{
					print("Shutting down Teligati OS!\n");
					break;
			}
			else
			{
					print("Bad command!\n");
			}
       }
}
