#pragma once

#include <vector>
#include "AgiFileReader.h"

enum class DrawingCommands
{
	ChangePictureAndEnableDraw = 0xF0,
	DisablePictureDraw = 0xF1,
	ChangePriorityColorAndEnablePriorityDraw = 0xF2,
	DisablePriorityDraw = 0xF3,
	DrawYCorner = 0xF4,
	DrawXCorner = 0xF5,
	AbsoluteLine = 0xF6,
	RelativeLine = 0xF7,
	Fill = 0xF8,
	ChangePenSizeAndStyle = 0xF9,
	PlotWithPen = 0xFA,
	EndOfPicture = 0xFF
};

class AgiPicture
{
private:
	const int WIDTH = 320;
	const int HEIGHT = 200;
	const uint8_t EMPTY = 0xFF;

	int VectorPosition = 0;
	
	bool IsPictureDrawEnabled;
	bool IsPriorityDrawEnabled;
	bool IsDrawing;
	uint8_t patCode, patNum;
	uint8_t PictureColor = 0;
	uint8_t PriorityColor = 0;
	uint8_t bitPos;
	uint8_t penX1, penY1;
	uint8_t ResourceId;

	// this queue crap needs to be recoded.
	const int QMAX = 4000;
	int rpos = QMAX, spos = 0;
	uint8_t buf[4000 + 1];

	int picIndex;
	AgiFile file;




	const std::vector<std::vector<int>> CircleMap{
		std::vector<int>{0x80},
		std::vector<int>{0xfc},
		std::vector<int>{0x5f, 0xf4},
		std::vector<int>{0x66, 0xff, 0xf6, 0x60},
		std::vector<int>{0x23, 0xbf, 0xff, 0xff, 0xee, 0x20},
		std::vector<int>{0x31, 0xe7, 0x9e, 0xff, 0xff, 0xde, 0x79, 0xe3, 0x00},
		std::vector<int>{0x38, 0xf9, 0xf3, 0xef, 0xff, 0xff, 0xff, 0xfe, 0xf9, 0xf3, 0xe3, 0x80},
		std::vector<int>{0x18, 0x3c, 0x7e, 0x7e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x7e, 0x7e, 0x3c, 0x18}
	};

	const std::vector<uint8_t> SplatterMap{
		0x20, 0x94, 0x02, 0x24, 0x90, 0x82, 0xa4, 0xa2,
		0x82, 0x09, 0x0a, 0x22, 0x12, 0x10, 0x42, 0x14,
		0x91, 0x4a, 0x91, 0x11, 0x08, 0x12, 0x25, 0x10,
		0x22, 0xa8, 0x14, 0x24, 0x00, 0x50, 0x24, 0x04
	};

	const std::vector<uint8_t> SplatterStartPositions = {
		0x00, 0x18, 0x30, 0xc4, 0xdc, 0x65, 0xeb, 0x48,
		0x60, 0xbd, 0x89, 0x05, 0x0a, 0xf4, 0x7d, 0x7d,
		0x85, 0xb0, 0x8e, 0x95, 0x1f, 0x22, 0x0d, 0xdf,
		0x2a, 0x78, 0xd5, 0x73, 0x1c, 0xb4, 0x40, 0xa1,
		0xb9, 0x3c, 0xca, 0x58, 0x92, 0x34, 0xcc, 0xce,
		0xd7, 0x42, 0x90, 0x0f, 0x8b, 0x7f, 0x32, 0xed,
		0x5c, 0x9d, 0xc8, 0x99, 0xad, 0x4e, 0x56, 0xa6,
		0xf7, 0x68, 0xb7, 0x25, 0x82, 0x37, 0x3a, 0x51,
		0x69, 0x26, 0x38, 0x52, 0x9e, 0x9a, 0x4f, 0xa7,
		0x43, 0x10, 0x80, 0xee, 0x3d, 0x59, 0x35, 0xcf,
		0x79, 0x74, 0xb5, 0xa2, 0xb1, 0x96, 0x23, 0xe0,
		0xbe, 0x05, 0xf5, 0x6e, 0x19, 0xc5, 0x66, 0x49,
		0xf0, 0xd1, 0x54, 0xa9, 0x70, 0x4b, 0xa4, 0xe2,
		0xe6, 0xe5, 0xab, 0xe4, 0xd2, 0xaa, 0x4c, 0xe3,
		0x06, 0x6f, 0xc6, 0x4a, 0xa4, 0x75, 0x97, 0xe1
	};

	void plotPattern(uint8_t x, uint8_t y);
	void plotPatternPoint();
	void plotBrush();
	void qstore(uint8_t q);
	uint8_t qretrieve();
	void Render();

	void AbsoluteLine();
	void DrawYCorner();
	void DrawXCorner();
	void RelativeLine();
	void DrawLine(int x1, int y1, int x2, int y2);
	void Fill();
	void Fill(uint8_t x, uint8_t y);
	bool okToFill(uint8_t x, uint8_t y);
	int GetPicturePixel(int x, int y);
	int GetPriorityPixel(int x, int y);
	void SetPixel(float x, float y);
	int round(float aNumber, float dirn);
	void InitializeDrawingSurface();

public:
	AgiPicture(AgiFile file);
	~AgiPicture();

	uint32_t *pictureBuffer, *priorityBuffer;
};