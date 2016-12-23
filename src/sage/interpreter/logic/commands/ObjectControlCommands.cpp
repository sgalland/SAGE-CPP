#include "ObjectControlCommands.h"
#include "../../AgiInterpreter.h"

void ObjectControlCommands::unanimate_all()
{
	// all objects are removed from the control list and considered non-existant
	// ---- Does this mean that everything is deleted from the view table or is animation stopped? -- Sean

	for (auto viewObject : AgiInterpreter::viewTable)
	{
		/*if (viewObject != nullptr)
		{
		delete viewObject;
		viewObject = nullptr;
		}*/
		viewObject->flags &= ~ViewFlags::Animated;
	}
}
