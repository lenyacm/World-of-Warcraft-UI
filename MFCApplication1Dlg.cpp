
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include"UI.h"
#include"head.h"
#include<vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//my code


extern int main(double set[]);
extern void show_ui();
//my code end
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, life(0)
	, City_sum(0)
	, total_time(0)
	, need1(0)
	, need2(0)
	, need3(0)
	, need4(0)
	, need5(0)
	, attack1(0)
	, attack2(0)
	, attack3(0)
	, attack4(0)
	, attack5(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m_hIcon = 0;
	time = 0;
	flag = 0;
	zero = 0;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, life);
	DDX_Text(pDX, IDC_EDIT2, City_sum);
	DDX_Text(pDX, IDC_EDIT3, total_time);
	DDX_Text(pDX, IDC_EDIT4, need1);
	DDX_Text(pDX, IDC_EDIT5, need2);
	DDX_Text(pDX, IDC_EDIT6, need3);
	DDX_Text(pDX, IDC_EDIT7, need4);
	//  DDX_Text(pDX, IDC_EDIT8, attack);
	//  DDX_Text(pDX, IDC_EDIT9, attack2);
	//  DDX_Text(pDX, IDC_EDIT8, attack1);
	DDX_Text(pDX, IDC_EDIT8, need5);
	DDX_Text(pDX, IDC_EDIT9, attack1);
	DDX_Text(pDX, IDC_EDIT10, attack2);
	DDX_Text(pDX, IDC_EDIT11, attack3);
	DDX_Text(pDX, IDC_EDIT12, attack4);
	DDX_Text(pDX, IDC_EDIT13, attack5);
	DDX_Text(pDX, IDC_EDIT4, need1);
	DDX_Text(pDX, IDC_EDIT5, need2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}




void TransparentPNG(CImage* png)
{
	for (int i = 0; i < png->GetWidth(); i++)  				//遍历像素处理
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			byte* pucColor = (byte*)(png->GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}
bool LoadImageFromResource(CImage* pImage, UINT nResID, LPCTSTR lpTyp)
{
	if (pImage == NULL)
		return false;
	pImage->Destroy();
	// 查找资源
	HRSRC hRsrc = ::FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResID), lpTyp);
	if (hRsrc == NULL)
		return false;
	// 加载资源
	HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hRsrc);
	if (hImgData == NULL)
	{
		::FreeResource(hImgData);
		return false;
	}
	// 锁定内存中的指定资源
	LPVOID lpVoid = ::LockResource(hImgData);
	LPSTREAM pStream = NULL;
	DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hRsrc);
	HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
	LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
	::memcpy(lpByte, lpVoid, dwSize);
	// 解除内存中的指定资源
	::GlobalUnlock(hNew);
	// 从指定内存创建流对象
	HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
	if (ht != S_OK)
	{
		GlobalFree(hNew);
	}
	else
	{
		// 加载图片
		pImage->Load(pStream);
		TransparentPNG(pImage);
		GlobalFree(hNew);
	}
	// 释放资源
	::FreeResource(hImgData);
	return true;
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


struct XSleep_Structure
{
	int duration;
	HANDLE eventHandle;
};
DWORD WINAPI XSleepThread(LPVOID pWaitTime)
{
	XSleep_Structure* sleep = (XSleep_Structure*)pWaitTime;

	Sleep(sleep->duration);
	SetEvent(sleep->eventHandle);

	return 0;
}
void XSleep(int nWaitInMsecs)
{

	XSleep_Structure sleep;
	sleep.duration = nWaitInMsecs;
	sleep.eventHandle = CreateEvent(NULL, TRUE, FALSE, NULL);

	/*DWORD dwThreadId;
	CreateThread(NULL, 0, &XSleepThread, &sleep, 0, &dwThreadId);*/

	HANDLE getHandle;
	getHandle = (HANDLE)_beginthreadex(NULL, 0,
		(unsigned int(__stdcall*)(void*))XSleepThread, &sleep, 0, NULL);

	MSG msg;
	while (::WaitForSingleObject(sleep.eventHandle, 0) == WAIT_TIMEOUT)
	{
		// get and dispatch message
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
	}
	CloseHandle(sleep.eventHandle);
	CloseHandle(getHandle);

}


void CMFCApplication1Dlg::OnClickedButton1()
{
	AllocConsole();//控制台调试窗口开启
	freopen("CONOUT$", "w", stdout);//开启中文控制台输出支持
	double delta;
	UpdateData(TRUE);
	double set[] = { life,City_sum ,total_time ,need1,need2,need3,need4,need5,attack1,attack2,attack3,attack4,attack5 };
	main(set);
	UpdateData(FALSE);
	FreeConsole(); // 释放控制台资源
	
}




void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UI picture;
	picture.init_ui();
	time = 0;

	time++;
	SetTimer(4, 60, NULL);

	time++;
	SetTimer(1, 4, NULL);

	time++;
	SetTimer(2, 4, NULL);
	XSleep(4000);

	time++;
	SetTimer(3, 4, NULL);
	XSleep(4000);

	time++;
	SetTimer(8, 4, NULL);
}

void CMFCApplication1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	UI picture;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
		switch (nIDEvent % 5)
		{
		case 1:
			// 如果m_nData1已经达到10，则销毁ID为1的定时器   
			if (htime[nIDEvent] == WINDOW_WIDTH - Ww)
			{
				
				KillTimer(1);
				break;
			}
			// 刷新编辑框IDC_EDIT1的显示   


			picture.drawAlpha(0, WINDOW_HEIGHT - Hh, &i_home0);
			picture.drawAlpha(WINDOW_WIDTH - Hw, WINDOW_HEIGHT - Hh, &i_home1);
			picture.drawAlpha(htime[nIDEvent], WINDOW_HEIGHT - Wh, &i_dragon0);
			htime[nIDEvent]++;
			break;
		case 2:
			if (htime[nIDEvent] == WINDOW_WIDTH - Ww)
			{
				
				KillTimer(nIDEvent);
				break;
			}
			picture.drawAlpha(WINDOW_WIDTH - Ww - htime[nIDEvent], WINDOW_HEIGHT - Wh, &i_iceman0);
			htime[nIDEvent]++;
			break;
		case 3:
			if (htime[nIDEvent] == WINDOW_WIDTH - Ww)
			{
				
				KillTimer(3);
				break;
			}
			picture.drawAlpha(WINDOW_WIDTH - Ww - htime[nIDEvent], WINDOW_HEIGHT - Wh, &i_lion0);
			htime[nIDEvent]++;
			break;
		case 4:
			cleardevice();
			htime[nIDEvent]++;
			break;
		default:
			break;
		}
	
	CDialogEx::OnTimer(nIDEvent);
}
