#include <windows.h>
#include <stdio.h>

HWND textfield;
HWND textbox1,textbox2;
HWND buttonplus,buttonminus,buttonmultiply,buttondivide;
char textsaved1[100],textsaved2[100];
double t1,t2;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE: {
			textfield = CreateWindowA("STATIC",
									"Please input two numbers",
									WS_VISIBLE | WS_CHILD,
									20,15,205,25, //left upper width hieght
									hwnd, NULL, NULL, NULL);
			textbox1 = CreateWindowA("EDIT",
									"",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									45,45,165,30,
									hwnd, NULL, NULL, NULL);
			textbox2 = CreateWindowA("EDIT",
									"",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									45,80,165,30,
									hwnd, NULL, NULL, NULL);
			buttonplus = CreateWindowA("BUTTON",
									"+",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									60,122.5,30,30,
									hwnd, (HMENU) 1, NULL,NULL);
			buttonminus = CreateWindowA("BUTTON",
									"-",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									95,122.5,30,30,
									hwnd, (HMENU) 2, NULL,NULL);
			buttonmultiply = CreateWindowA("BUTTON",
									"*",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									130,122.5,30,30,
									hwnd, (HMENU) 3, NULL,NULL);
			buttondivide = CreateWindowA("BUTTON",
									"/",
									WS_VISIBLE | WS_CHILD | WS_BORDER,
									165,122.5,30,30,
									hwnd, (HMENU) 4, NULL,NULL);
			
			break;
		}
		case WM_COMMAND: {
			switch (LOWORD(wParam)){
				case 1: {
					int textLength1 = GetWindowText(textbox1, textsaved1, 100);
					textsaved1[textLength1] = '\0'; // กำหนดตัวสุดท้ายเป็น \0 จะได้จบข้อความได้
					int textLength2 = GetWindowText(textbox2, textsaved2, 100);
					textsaved2[textLength2] = '\0'; // กำหนดตัวสุดท้ายเป็น \0 จะได้จบข้อความได้
    				sscanf(textsaved1, "%lf", &t1);
    				sscanf(textsaved2, "%lf", &t2);
					char t[100];
					double result = t1+t2;
					sprintf(t, "%f", result);
					::MessageBeep(MB_ICONERROR);
					::MessageBox(hwnd, t, "Result", MB_OK); //first is body, second is title
					break;
				}
				case 2: {
					int textLength1 = GetWindowText(textbox1, textsaved1, 100);
					textsaved1[textLength1] = '\0'; // Null-terminate the string
					int textLength2 = GetWindowText(textbox2, textsaved2, 100);
					textsaved2[textLength2] = '\0'; // Null-terminate the string 
    				sscanf(textsaved1, "%lf", &t1);
    				sscanf(textsaved2, "%lf", &t2);
					char t[100];
					double result = t1-t2;
					sprintf(t, "%f", result);
					::MessageBeep(MB_ICONERROR);
					::MessageBox(hwnd, t, "Result", MB_OK); //first is body, second is title
					break;
				}
				case 3: {
					int textLength1 = GetWindowText(textbox1, textsaved1, 100);
					textsaved1[textLength1] = '\0'; // Null-terminate the string
					int textLength2 = GetWindowText(textbox2, textsaved2, 100);
					textsaved2[textLength2] = '\0'; // Null-terminate the string 
    				sscanf(textsaved1, "%lf", &t1);
    				sscanf(textsaved2, "%lf", &t2);
					char t[100];
					double result = t1*t2;
					sprintf(t, "%f", result);
					::MessageBeep(MB_ICONERROR);
					::MessageBox(hwnd, t, "Result", MB_OK); //first is body, second is title
					break;
				}
				case 4: {
					int textLength1 = GetWindowText(textbox1, textsaved1, 100);
					textsaved1[textLength1] = '\0'; // Null-terminate the string
					int textLength2 = GetWindowText(textbox2, textsaved2, 100);
					textsaved2[textLength2] = '\0'; // Null-terminate the string 
    				sscanf(textsaved1, "%lf", &t1);
    				sscanf(textsaved2, "%lf", &t2);
					char t[100];
					double result = t1/t2;
					sprintf(t, "%f", result);
					::MessageBeep(MB_ICONERROR);
					::MessageBox(hwnd, t, "Result", MB_OK); //first is body, second is title
					break;
				}
			}
			break;
		}
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreateSolidBrush(RGB(255,0,0));
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
