#pragma once
#include <vector>
#include <Control.h>
class Controls
{
public:
	void AddControl(Control ctrl);
	void Show();

private:
	std::vector<Control> controls_;
};

