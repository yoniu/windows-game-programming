// ʵ�� win32 ��� Hello World

#include <windows.h>

// ����������Ϣ������
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	// ��������
	HWND hwnd; // ���ھ��
	MSG Msg; // ��Ϣ
	WNDCLASS wndclass; //������
	TCHAR lpszTitle[] = TEXT("Hello World"); // ���ڱ���
	TCHAR lpszClassName[] = TEXT("MyClass"); 
	
	// ���ô�����
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // ��������ʽ 
	wndclass.lpfnWndProc = WndProc; // ��Ϣ������ 
	wndclass.cbClsExtra = 0; // ��ṹԤ���ռ� 
	wndclass.cbWndExtra = 0; // ���ڽṹԤ���ռ� 
	wndclass.hInstance = hInstance; // Ӧ�ó���ʵ����� 
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ͼ�� 
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // ��� 
	wndclass.lpszMenuName = NULL; // ������˵� 
	wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH); // ������ˢ��� 
	wndclass.lpszClassName = lpszClassName; // �������� 
	
	// ע�ᴰ����
	if (!RegisterClass(&wndclass)) { 
		// ע����ɹ����ش�����Ψһ��ʶ��ʧ�ܷ��� 0 
		MessageBox(NULL, TEXT("RegisterClass fail!"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	} 
	
	// ��������
	hwnd = CreateWindow(
		lpszClassName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW, // �������� 
		CW_USEDEFAULT, // �������Ͻ�����Ļ�ϵ� X 
		CW_USEDEFAULT, // �������Ͻ�����Ļ�ϵ� Y 
		CW_USEDEFAULT, // ���ڵĿ� 
		CW_USEDEFAULT, // ���ڵĸ� 
		NULL, // �����ھ�� 
		NULL, // ���ڲ˵���� 
		hInstance, // Ӧ��ʵ����� 
		NULL // �������� 
	);
	
	if (!hwnd) {
		MessageBox(NULL, TEXT("CreateWindow fail!"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	} 
	
	// ��ʾ���´���
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	// ��Ϣѭ��
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	} 
	return Msg.wParam;
} 

// ���ڹ��̺���
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	// ��������
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	
	// ������Ϣ ID ����Ϣ���д���
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
