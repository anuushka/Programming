#pragma once

#include "IGeoFig.h"
#include "IPhysObject.h"
#include "IPrintable.h"
#include "IDialogInitiable.h"
#include "BaseCObject.h"
#include "CVector2D.h"

class IFigure : public IGeoFig, public IPhysObject, public CVector2D, public IPrintable, public IDialogInitiable, public BaseCObject
{
};
