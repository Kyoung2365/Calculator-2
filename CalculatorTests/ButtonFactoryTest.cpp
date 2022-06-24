
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
			wxButton* AddButton;
			Screen* screen{};
			wxSize size;
			AddButton = button.CreateAddButton(screen, size);
			Assert::IsTrue(ID_ADD_BUTTON);
		}

		TEST_METHOD(ReturnOne) {
			ButtonFactory button;
			wxButton* OneButton;
			Screen* screen{};
			int num = 1;
			wxSize size;
			OneButton = button.CreateNumButton(screen, num, size);
			Assert::IsTrue(ID_1_BUTTON);
		}

		TEST_METHOD(ReturnsSub) {
			ButtonFactory button;
			wxButton* SubButton;
			Screen* screen{};
			wxSize size;
			SubButton = button.CreateSubButton(screen, size);
			Assert::IsTrue(ID_SUB_BUTTON);
		}

		TEST_METHOD(ReturnTwo) {
			ButtonFactory button;
			wxButton* TwoButton;
			Screen* screen{};
			int num = 2;
			wxSize size;
			TwoButton = button.CreateNumButton(screen, num, size);
			Assert::IsTrue(ID_2_BUTTON);
		}

		TEST_METHOD(ReturnsHex) {
			ButtonFactory button;
			wxButton* HexButton;
			Screen* screen{};
			wxSize size;
			HexButton = button.CreateHexButton(screen, size);
			Assert::IsTrue(ID_HEX_BUTTON);
		}

		TEST_METHOD(ReturnFive) {
			ButtonFactory button;
			wxButton* FiveButton;
			Screen* screen{};
			int num = 5;
			wxSize size;
			FiveButton = button.CreateNumButton(screen, num, size);
			Assert::IsTrue(ID_5_BUTTON);
		}

		TEST_METHOD(ReturnsDecimal) {
			ButtonFactory button;
			wxButton* DecimalButton;
			Screen* screen{};
			wxSize size;
			button.CreateAddButton(screen, size);
			Assert::IsTrue(ID_DECI_BUTTON);
		}

		TEST_METHOD(ReturnEight) {
			ButtonFactory button;
			wxButton* EightButton;
			Screen* screen{};
			int num = 8;
			wxSize size;
			EightButton = button.CreateNumButton(screen, num, size);
			Assert::IsTrue(ID_8_BUTTON);
		}

		TEST_METHOD(ReturnsClear) {
			ButtonFactory button;
			wxButton* ClearButton;
			Screen* screen{};
			wxSize size;
			ClearButton = button.CreateClrButton(screen, size);
			Assert::IsTrue(ID_CLR_BUTTON);
		}

		TEST_METHOD(ReturnNine) {
			ButtonFactory button;
			wxButton* NineButton;
			Screen* screen{};
			int num = 9;
			wxSize size;
			NineButton = button.CreateNumButton(screen, num, size);
			Assert::IsTrue(ID_9_BUTTON);
		}
	};
}