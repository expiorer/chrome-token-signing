/*
* Chrome Token Signing Native Host
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "PinDialog.h"
#include "afxdialogex.h"
#include <string>

using namespace std;


IMPLEMENT_DYNAMIC(PinDialog, CDialog)

PinDialog::PinDialog(CWnd* pParent) : CDialog(PinDialog::IDD, pParent) {
}

PinDialog::~PinDialog()
{
}

void PinDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PinDialog, CDialog)
	ON_BN_CLICKED(IDOK, &PinDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// PinDialog message handlers


void PinDialog::OnBnClickedOk()
{
	// TODO: Improve

	CString rawPin;
	GetDlgItem(IDC_PIN_FIELD)->GetWindowText(rawPin);
	char * pinChar = _strdup(ATL::CT2CA(rawPin));
	string pinStr(pinChar);
	pin = pinStr;

	CDialog::OnOK();
}

string PinDialog::getPin() {
	return pin;
}