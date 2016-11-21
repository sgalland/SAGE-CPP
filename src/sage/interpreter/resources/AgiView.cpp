#include "AgiView.h"

void AgiView::LoadViewHeader(AgiFile file)
{
	// Skip the first two bytes, which are unknown bytes.
	loopCount = file.data[2];
	uint16_t descriptionLocation = 0;

	// My C# code for this
	//LoopCount = file.Data[2];
	//var descriptionLocation = BitConverter.ToInt16(file.Data, 3);
	//if (descriptionLocation > 0)
	//{
	//	Description = AgiStringHelper.GetString(file.Data, descriptionLocation);
	//}

	//// Read the loop header positions
	//// Loop indices start 5 bytes past the start of the file and are two bytes wide
	//const int offset = 5;
	//for (var loopIndex = 0; loopIndex < LoopCount; loopIndex++)
	//{
	//	loopLocations[loopIndex] = BitConverter.ToInt16(file.Data, offset + (loopIndex * 2));
	//}
}

void AgiView::ReadLoopHeaders(AgiFile file)
{
}

void AgiView::ReadCelHeader(AgiFile file)
{
}

AgiView::AgiView(AgiFile file)
{
	LoadViewHeader(file);
	ReadLoopHeaders(file);
	ReadCelHeader(file);
}
