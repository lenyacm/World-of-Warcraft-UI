﻿
// MFCApplication1Dlg.h: 头文件
//

#pragma once

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
//	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double life;
	double City_sum;
	double total_time;
//	double need1;
//	double need2;
	afx_msg void OnClickedButton1();
	double need3;
	double need4;
	double need5;
	double attack1;
	double attack2;
	double attack3;
	double attack4;
	double attack5;
//	int m_hIcon;
//	HICON m_hicon;
	HICON m_hIcon;
	double need1;
	double need2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int time;
//	UI picture;
	int flag;
//	std::vector<int> htime;
	int zero;
};
