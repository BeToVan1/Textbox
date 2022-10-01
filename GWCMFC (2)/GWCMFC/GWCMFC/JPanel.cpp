#include "JPanel.h"


// JPanel

IMPLEMENT_DYNAMIC( JPanel, CWnd )

JPanel::JPanel()
{

}

JPanel::~JPanel()
{
}

CString JPanel::sWindowName;
void JPanel::RegisterClass()
{
	sWindowName = AfxRegisterWndClass( 0 );
}


BEGIN_MESSAGE_MAP( JPanel, CWnd )
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// In case you need to get to the Dialog from somewhere
//CBaronPongDlg *tDialog = (CBaronPongDlg*)AfxGetMainWnd();

// And in case you need to get to the app
//CBaronPongApp* app = ( CBaronPongApp *)AfxGetApp();

// A click upon us!  Execute this code and be merry.
void JPanel::OnLButtonDown( UINT nFlags, CPoint point )
{
	//Tell Logic to make a new Object at this point and return the pointer (they will put it in AllObjects too.)

	// Make a new Sprite using that object pointer and keep it in AllSprites

	// If you have cool settings, apply them to the object
}



void JPanel::OnPaint()
{
	//https://msdn.microsoft.com/en-us/library/fxhhde73.aspx
	CPaintDC dc( this ); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CWnd::OnPaint() for painting messages

	// This code here is just to show you where the JPanel is.  Makes it blue.
	CBrush brushBlue( RGB( 0, 0, 255 ) );
	CBrush* pOldBrush = dc.SelectObject( &brushBlue );

	CRect rect;
	GetClientRect( rect );
	dc.Rectangle( rect );

	// Ask our dialog for the current interpolation percentage (if doing interploation)
	// Loop through all of our sprites and tell them to draw by passing the dc in..

	dc.SelectObject( pOldBrush );
}