#include "UIBase.h"

UIBase::UIBase(OBJCT_TYPE objtype)
{
	obj_type = objtype;
	FontHandle["HP"] = CreateFontToHandle(NULL, 90, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	FontHandle["AD"] = CreateFontToHandle(NULL, 45, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

UIBase::~UIBase()
{
}


