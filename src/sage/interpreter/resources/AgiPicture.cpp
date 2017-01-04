#include "AgiPicture.h"
#include "../helpers/AgiColor.h"
#include <cmath>

void AgiPicture::plotPattern(uint8_t x, uint8_t y)
{
	//if (patNum >= splatterMap.Length - 1) patNum = 0;
	int circlePos = 0;
	/*penX1, peny1, */
	uint8_t penSize;
	bitPos = SplatterStartPositions[patNum];

	penSize = static_cast<uint8_t>(patCode & 7);

	if (x < ((penSize / 2) + 1)) x = static_cast<uint8_t>((penSize / 2) + 1);
	else if (x > 160 - ((penSize / 2) + 1)) x = static_cast<uint8_t>(160 - ((penSize / 2) + 1));
	if (y < penSize) y = penSize;
	else if (y >= 168 - penSize) y = static_cast<uint8_t>(167 - penSize);

	for (penY1 = static_cast<uint8_t>(y - penSize); penY1 <= y + penSize; penY1++)
	{
		for (penX1 = static_cast<uint8_t>(x - (ceill((float)penSize / 2))); penX1 <= x + (floor((float)penSize / 2)); penX1++)
		{
			if ((patCode & 0x10) != 0)
			{ /* Square */
				plotPatternPoint();
			}
			else
			{ /* Circle */
				if (((CircleMap[patCode & 7][circlePos >> 3] >> (7 - (circlePos & 7))) & 1) != 0)
				{
					plotPatternPoint();
				}
				circlePos++;
			}
		}
	}
}

void AgiPicture::plotPatternPoint()
{
	if ((patCode & 0x20) != 0)
	{
		if (((SplatterMap[bitPos >> 3] >> (7 - (bitPos & 7))) & 1) != 0) SetPixel(penX1, penY1);
		bitPos++;
		if (bitPos == 0xff) bitPos = 0;
	}
	else
		SetPixel(penX1, penY1);
}

void AgiPicture::plotBrush()
{
	uint8_t x1, y1;

	while (true)
	{
		if ((patCode & 0x20) != 0)
		{
			if (((patNum = file.data[VectorPosition++]) >= 0xF0)) break;
			patNum = static_cast<uint8_t>(patNum >> 1 & 0x7f);
		}
		if ((x1 = file.data[VectorPosition++]) >= 0xF0) break;
		if ((y1 = file.data[VectorPosition++]) >= 0xF0) break;
		plotPattern(x1, y1);
	}

	VectorPosition--;
}

void AgiPicture::qstore(uint8_t q)
{
	if (spos + 1 == rpos || (spos + 1 == QMAX && rpos == 0))
	{
		return;
	}
	buf[spos] = q;
	spos++;
	if (spos == QMAX) spos = 0;  /* loop back */
}

uint8_t AgiPicture::qretrieve()
{
	if (rpos == QMAX) rpos = 0;  /* loop back */
	if (rpos == spos)
	{
		return EMPTY;
	}
	rpos++;
	return buf[rpos - 1];
}

void AgiPicture::Render()
{
	InitializeDrawingSurface();
	VectorPosition = 0;
	IsDrawing = true;

	do
	{
		DrawingCommands action = (DrawingCommands)file.data[VectorPosition++];

		switch (action)
		{
		case DrawingCommands::EndOfPicture: { IsDrawing = false; } break;
		case DrawingCommands::ChangePictureAndEnableDraw:
		{
			PictureColor = file.data[VectorPosition++];
			IsPictureDrawEnabled = true;
		}
		break;
		case DrawingCommands::DisablePictureDraw: { IsPictureDrawEnabled = false; } break;
		case DrawingCommands::ChangePriorityColorAndEnablePriorityDraw:
		{
			PriorityColor = file.data[VectorPosition++];
			IsPriorityDrawEnabled = true;
		}
		break;
		case DrawingCommands::DisablePriorityDraw: { IsPriorityDrawEnabled = false; } break;
		case DrawingCommands::DrawYCorner: { DrawYCorner(); } break;
		case DrawingCommands::DrawXCorner: { DrawXCorner(); } break;
		case DrawingCommands::AbsoluteLine: { AbsoluteLine(); } break;
		case DrawingCommands::RelativeLine: { RelativeLine(); } break;
		case DrawingCommands::Fill: { Fill(); } break;
		case DrawingCommands::ChangePenSizeAndStyle: { patCode = file.data[VectorPosition++]; } break;
		case DrawingCommands::PlotWithPen: { plotBrush(); } break;
		default: IsDrawing = false; break;
		}
	} while (VectorPosition < file.data.size() && IsDrawing);
}

void AgiPicture::AbsoluteLine()
{
	uint8_t x1, y1, x2, y2;
	x1 = file.data[VectorPosition++];
	y1 = file.data[VectorPosition++];

	SetPixel(x1, y1);

	while ((x2 = file.data[VectorPosition++]) < 0xF0 && (y2 = file.data[VectorPosition++]) < 0xF0)
	{
		DrawLine(x1, y1, x2, y2);
		x1 = x2;
		y1 = y2;
	}

	VectorPosition--;
}

void AgiPicture::DrawYCorner()
{
	uint8_t x1, x2, y1, y2;

	x1 = file.data[VectorPosition++];
	y1 = file.data[VectorPosition++];

	SetPixel(x1, y1);

	while (true)
	{
		y2 = file.data[VectorPosition++];
		if (y2 >= 0xF0) break;
		DrawLine(x1, y1, x1, y2);
		y1 = y2;
		x2 = file.data[VectorPosition++];
		if (x2 >= 0xF0) break;
		DrawLine(x1, y1, x2, y1);
		x1 = x2;
	}

	VectorPosition--;
}

void AgiPicture::DrawXCorner()
{
	uint8_t x1, x2, y1, y2;

	x1 = file.data[VectorPosition++];
	y1 = file.data[VectorPosition++];

	SetPixel(x1, y1);

	while (true)
	{
		x2 = file.data[VectorPosition++];
		if (x2 >= 0xF0) break;
		DrawLine(x1, y1, x2, y1);
		x1 = x2;
		y2 = file.data[VectorPosition++];
		if (y2 >= 0xF0) break;
		DrawLine(x1, y1, x1, y2);
		y1 = y2;
	}

	VectorPosition--;
}

void AgiPicture::RelativeLine()
{
	int x1, y1, disp;
	int dx, dy;

	x1 = file.data[VectorPosition++];
	y1 = file.data[VectorPosition++];

	SetPixel(x1, y1);

	while (true)
	{
		disp = file.data[VectorPosition++];
		if (disp >= 0xF0) break;
		dx = ((disp & 0xF0) >> 4) & 0x0F;
		dy = (disp & 0x0F);
		if ((dx & 0x08) != 0) dx = (-1) * (dx & 0x07);
		if ((dy & 0x08) != 0) dy = (-1) * (dy & 0x07);
		DrawLine(x1, y1, x1 + dx, y1 + dy);
		x1 += dx;
		y1 += dy;
	}

	VectorPosition--;
}

void AgiPicture::DrawLine(int x1, int y1, int x2, int y2)
{
	float x, y;//, addX, addY;

	int height = (y2 - y1);
	int width = (x2 - x1);
	float addX = (height == 0 ? height : (float)width / abs(height));
	float addY = (width == 0 ? width : (float)height / abs(width));

	if (abs(width) > abs(height))
	{
		y = y1;
		addX = (width == 0 ? 0 : (width / abs(width)));
		for (x = x1; x != x2; x += addX)
		{
			SetPixel(round(x, addX), round(y, addY));
			y += addY;
		}
		SetPixel(x2, y2);
	}
	else
	{
		x = x1;
		addY = (height == 0 ? 0 : (height / abs(height)));
		for (y = y1; y != y2; y += addY)
		{
			SetPixel(round(x, addX), round(y, addY));
			x += addX;
		}
		SetPixel(x2, y2);
	}
}

void AgiPicture::Fill()
{
	uint8_t x1, y1;

	while (true)
	{
		if ((x1 = file.data[VectorPosition++]) >= 0xF0) break;
		if ((y1 = file.data[VectorPosition++]) >= 0xF0) break;
		Fill(x1, y1);
	}

	VectorPosition--;
}

void AgiPicture::Fill(uint8_t x, uint8_t y)
{
	uint8_t x1, y1;
	rpos = spos = 0;

	qstore(x);
	qstore(y);

	while (true)
	{
		x1 = qretrieve();
		y1 = qretrieve();

		if ((x1 == EMPTY) || (y1 == EMPTY))
			break;
		else
		{
			if (okToFill(x1, y1))
			{
				SetPixel(x1, y1);

				if (okToFill(x1, (uint8_t)(y1 - 1)) && (y1 != 0))
				{
					qstore(x1);
					qstore((uint8_t)(y1 - 1));
				}
				if (okToFill((uint8_t)(x1 - 1), y1) && (x1 != 0))
				{
					qstore((uint8_t)(x1 - 1));
					qstore(y1);
				}
				if (okToFill((uint8_t)(x1 + 1), y1) && (x1 != 159))
				{
					qstore((uint8_t)(x1 + 1));
					qstore(y1);
				}
				if (okToFill(x1, (uint8_t)(y1 + 1)) && (y1 != 167))
				{
					qstore(x1);
					qstore((uint8_t)(y1 + 1));
				}
			}
		}
	}
}

bool AgiPicture::okToFill(uint8_t x, uint8_t y)
{
	if (!IsPictureDrawEnabled && !IsPriorityDrawEnabled) return false;
	if (PictureColor == 15) return false;
	if (!IsPriorityDrawEnabled) return (GetPicturePixel(x, y) == 15);
	if (IsPriorityDrawEnabled && !IsPictureDrawEnabled) return (GetPriorityPixel(x, y) == 4);
	return (GetPicturePixel(x, y) == 15);
}

int AgiPicture::GetPicturePixel(int x, int y)
{
	int vx = (x << 1);
	int vy = y;
	if (vx > 319 || vy > 199)
		return 15;

	uint32_t currentPixelColor = pictureBuffer[vx + vy * WIDTH];
	AgiColor color = AgiColor::getColorByDosColor(currentPixelColor);
	return color.dosColor;
}

int AgiPicture::GetPriorityPixel(int x, int y)
{
	int vx = (x << 1);
	int vy = y;
	if (vx > 319 || vy > 199)
		return 4;

	uint32_t currentPixelColor = priorityBuffer[vx + vy * WIDTH];	
	AgiColor color = AgiColor::getColorByDosColor(currentPixelColor);
	return color.dosColor;
}

void AgiPicture::SetPixel(float x, float y)
{
	int xx = (int)x;
	int x1 = xx << 1;
	if (x1 > 319) return;
	if (y > 199) return;

	if (IsPictureDrawEnabled)
	{
		uint8_t drawingColor = PictureColor;
		pictureBuffer[(int)x1 + (int)y * WIDTH] = drawingColor;
		pictureBuffer[(int)x1 + 1 + (int)y * WIDTH] = drawingColor;
	}
	else if (IsPriorityDrawEnabled)
	{
		uint8_t drawingColor = PriorityColor;
		priorityBuffer[(int)x1 + (int)y * WIDTH] = drawingColor;
		priorityBuffer[(int)x1 + 1 + (int)y * WIDTH] = drawingColor;
	}
}

int AgiPicture::round(float aNumber, float dirn)
{
	if (dirn < 0)
		return (int)((aNumber - floor(aNumber) <= 0.501) ? floor(aNumber) : ceil(aNumber));
	return (int)((aNumber - floor(aNumber) < 0.499) ? floor(aNumber) : ceil(aNumber));
}

void AgiPicture::InitializeDrawingSurface()
{
	AgiColor agiColor = AgiColor::getColorByDosColor(15);
	int bufferSize = HEIGHT * WIDTH;
	pictureBuffer = new uint32_t[bufferSize];
	for (int i = 0; i < bufferSize; i++)
		pictureBuffer[i] = agiColor.dosColor;

	agiColor = AgiColor::getColorByDosColor(4);
	priorityBuffer = new uint32_t[bufferSize];
	for (int i = 0; i < bufferSize; i++)
		priorityBuffer[i] = agiColor.dosColor;
}

AgiPicture::AgiPicture(AgiFile file)
{
	this->file = file;
	this->Render();
}

AgiPicture::~AgiPicture()
{
	if (this->pictureBuffer != nullptr)
		delete[] pictureBuffer;

	if (this->priorityBuffer != nullptr)
		delete[] priorityBuffer;

	pictureBuffer = nullptr;
	priorityBuffer = nullptr;
}
