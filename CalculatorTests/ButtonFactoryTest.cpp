
#include "pch.h"
#include "../Calculator/ButtonFactory.h"
#include "../Calculator/ButtonFactory.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTests 
{
	TEST_CLASS(ButtonFactoryTests) 
	{
	public:
		TEST_METHOD(ReturnsAdd) {
			ButtonFactory button;
			Button AddButton;
			Screen* screen{};
			wxSize size;
			button.CreateAddButton(screen, size);
			Assert::AreEqual(ID_ADD_BUTTON, AddButton);
		}

		TEST_METHOD(ReturnZero) {
			ButtonFactory button;
			Button ZeroButton;
			Screen* screen{};
			int num = 0;
			wxSize size;
			button.CreateNumButton(screen, num, size);
			Assert::AreEqual(ID_0_BUTTON, ZeroButton);
		}

		TEST_METHOD(ReturnsSub) {
			ButtonFactory button;
			Button SubButton;
			Screen* screen{};
			wxSize size;
			button.CreateSubButton(screen, size);
			Assert::AreEqual(ID_SUB_BUTTON, SubButton);
		}

		TEST_METHOD(ReturnTwo) {
			ButtonFactory button;
			Button TwoButton;
			Screen* screen{};
			int num = 2;
			wxSize size;
			button.CreateNumButton(screen, num, size);
			Assert::AreEqual(ID_2_BUTTON, TwoButton);
		}

		TEST_METHOD(ReturnsHex) {
			ButtonFactory button;
			Button HexButton;
			Screen* screen{};
			wxSize size;
			button.CreateHexButton(screen, size);
			Assert::AreEqual(ID_HEX_BUTTON, HexButton);
		}

		TEST_METHOD(ReturnFive) {
			ButtonFactory button;
			Button FiveButton;
			Screen* screen{};
			int num = 5;
			wxSize size;
			button.CreateNumButton(screen, num, size);
			Assert::AreEqual(ID_5_BUTTON, FiveButton);
		}

		TEST_METHOD(ReturnsDecimal) {
			ButtonFactory button;
			Button DecimalButton;
			Screen* screen{};
			wxSize size;
			button.CreateAddButton(screen, size);
			Assert::AreEqual(ID_DECI_BUTTON, DecimalButton);
		}

		TEST_METHOD(ReturnEight) {
			ButtonFactory button;
			Button EightButton;
			Screen* screen{};
			int num = 8;
			wxSize size;
			button.CreateNumButton(screen, num, size);
			Assert::AreEqual(ID_8_BUTTON, EightButton);
		}

		TEST_METHOD(ReturnsClear) {
			ButtonFactory button;
			Button ClearButton;
			Screen* screen{};
			wxSize size;
			button.CreateClrButton(screen, size);
			Assert::AreEqual(ID_CLR_BUTTON, ClearButton);
		}

		TEST_METHOD(ReturnNine) {
			ButtonFactory button;
			Button NineButton;
			Screen* screen{};
			int num = 9;
			wxSize size;
			button.CreateNumButton(screen, num, size);
			Assert::AreEqual(ID_9_BUTTON, NineButton);
		}
	};
}