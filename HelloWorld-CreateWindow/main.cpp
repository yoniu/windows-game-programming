// 实现 win32 版的 Hello World

#include <windows.h>

// 声明窗口消息处理函数
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	// 变量声明
	HWND hwnd; // 窗口句柄
	MSG Msg; // 消息
	WNDCLASS wndclass; //窗口类
	TCHAR lpszTitle[] = TEXT("Hello World"); // 窗口标题
	TCHAR lpszClassName[] = TEXT("MyClass"); 
	
	// 设置窗口类
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // 窗口类样式 
	wndclass.lpfnWndProc = WndProc; // 消息处理函数 
	wndclass.cbClsExtra = 0; // 类结构预留空间 
	wndclass.cbWndExtra = 0; // 窗口结构预留空间 
	wndclass.hInstance = hInstance; // 应用程序实例句柄 
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 图标 
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // 光标 
	wndclass.lpszMenuName = NULL; // 窗口类菜单 
	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH); // 背景画刷句柄 
	wndclass.lpszClassName = lpszClassName; // 窗口类名 
	
	// 注册窗口类
	if (!RegisterClass(&wndclass)) { 
		// 注册类成功返回窗口类唯一标识，失败返回 0 
		MessageBox(NULL, TEXT("RegisterClass fail!"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	} 
	
	// 创建窗口
	hwnd = CreateWindow(
		lpszClassName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW, // 窗口类型 
		CW_USEDEFAULT, // 窗口左上角在屏幕上的 X 
		CW_USEDEFAULT, // 窗口左上角在屏幕上的 Y 
		CW_USEDEFAULT, // 窗口的宽 
		CW_USEDEFAULT, // 窗口的高 
		NULL, // 父窗口句柄 
		NULL, // 窗口菜单句柄 
		hInstance, // 应用实例句柄 
		NULL // 创建参数 
	);
	
	if (!hwnd) {
		MessageBox(NULL, TEXT("CreateWindow fail!"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	} 
	
	// 显示更新窗口
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	// 消息循环
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	} 
	return Msg.wParam;
} 

// 窗口过程函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	// 变量声明
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	
	// 根据消息 ID 对消息进行处理
	switch (message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rect);
			DrawText(hdc, TEXT("Hello World!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hwnd, &ps);
			return 0;
	} 
	return DefWindowProc(hwnd, message, wParam, lParam);
} 
