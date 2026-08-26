#include "Controls.h"

void Controls::AddControl(Control ctrl)
{
	controls_.push_back(ctrl);
}

void Controls::Show()
{
	for (auto& control : controls_)
	{
		control.Show();
	}
}
