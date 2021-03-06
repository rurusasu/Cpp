
// ballView.cpp : CballView クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "ball.h"
#endif

#include "ballDoc.h"
#include "ballView.h"
#include <math.h> //追加

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//変数の定義
const double T0 = 0.0;    //初期時刻
const double DT = 0.03;   //時間刻み
const double K = 10.0;    //空気抵抗の比例定数
const double PI =3.14159;
const double V0 = 70.0;   //初速度(m/s)
const double DEGREE = 45; //角度：度(°)
const int X0 = 10;    //初期位置(m)
const int Y0 = 10;
const double M0 = 0.1;    //ボールの質量(kg)


int TN = 0;                        //ステップ数
const double T = T0 + DT * double(TN);   //時刻
const double G = 9.80665;                //重力加速度 g
const double RADIAN = DEGREE * PI / 180; //角度：ラジアン(rad)

//ボールの定義
struct BALL {
	double M;   //質量
	double X, Y;
	double VX, VY;
	double AX, AY;
};

BALL ball;

// CballView
IMPLEMENT_DYNCREATE(CballView, CView)

BEGIN_MESSAGE_MAP(CballView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CballView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CballView コンストラクション/デストラクション

CballView::CballView()
{
	// TODO: 構築コードをここに追加します。

}

CballView::~CballView()
{
}

BOOL CballView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CballView 描画

void CballView::OnDraw(CDC* pDC)
{
	CballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。

	//空気抵抗を受けるボールの放物運動計算　振動・計測入門


	CPen pc1(PS_SOLID, 1, RGB(0, 125, 128)); //ペンの初期化
	CPen pc3(PS_SOLID, 2, RGB(0, 0, 255));

	CPen* oldp = pDC->SelectObject(&pc1); //ペンの変更

	int xsp = 5, ysp = 3000; //作図範囲

	//軸の表示
	char strx[256];
	LPCSTR str = "空気抵抗を受けるボールの放物運動計算プログラム";
	pDC->SelectObject(&pc3);


	pDC->MoveTo(X0, Y0); pDC->LineTo(X0, Y0);
	pDC->MoveTo(X0, Y0); pDC->LineTo(X0, Y0);

	char buf[100];
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->TextOut(60, 0, (LPCTSTR)str,strlen(str)); //文字の出力
	pDC->SetTextColor(RGB(0, 65, 0));
	sprintf_s(buf, "ボールの重さ：%.2lfg 初速度：%.1lfkm/h 打ち上げ角：%.1lf°", M0*1000.0, V0, DEGREE);
	pDC->TextOut(100, 20, (LPCTSTR)buf,strlen(buf));


	pDC->SelectObject(&pc1);
	//ボールの初期化
	ball.M = M0;
	ball.X = X0;
	ball.Y = Y0;
	ball.VX = V0 * cos(RADIAN);
	ball.VY = V0 * sin(RADIAN);
	ball.AX = 0.0;
	ball.AY = -G;
	
	while (ball.Y >= 0) {
		//加速度の算出
		ball.AX = -K / ball.M * ball.VX * DT;
		ball.AY = -G - K / ball.M * ball.VY * DT;
		//速度の算出
		ball.VX += ball.VX + ball.AX * DT;
		ball.VY += ball.VY + ball.AY * DT;
		//位置の算出
		ball.X += ball.X + ball.VX * DT;
		ball.Y += ball.Y + ball.VY * DT;
		TN++;
	}

	pDC->SetTextColor(RGB(250, 52, 50));
	sprintf_s(buf, "到達距離＝%.2fm", ball.X);
	pDC->TextOut(120, 40, (LPCTSTR)buf); //文字の出力


	pDC->SelectObject(oldp); //ペンを元に戻す
}

// CballView の印刷


void CballView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CballView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CballView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CballView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CballView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CballView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CballView の診断

#ifdef _DEBUG
void CballView::AssertValid() const
{
	CView::AssertValid();
}

void CballView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CballDoc* CballView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CballDoc)));
	return (CballDoc*)m_pDocument;
}
#endif //_DEBUG


// CballView メッセージ ハンドラー