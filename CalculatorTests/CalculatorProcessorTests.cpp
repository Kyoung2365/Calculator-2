
#include "pch.h"
#include "../Calculator/CalculatorProcessor.h"
#include "../Calculator/CalculatorProcessor.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		TEST_METHOD(AddThreePlusFourEqualsSeven)
		{
			int answer = CalculatorProcessor::GetAdd(3, 4);
			Assert::AreEqual(answer, 7);
		}

		TEST_METHOD(AddTwentyPlusSixDoesNotEqualsTwentyEight)
		{
			int answer = CalculatorProcessor::GetAdd(20, 6);
			Assert::AreNotEqual(answer, 28);
		}

		TEST_METHOD(SubOneHunTwentyMinusFortySixEqualsSeventyFour)
		{
			int answer = CalculatorProcessor::GetSub(120, 46);
			Assert::AreEqual(answer, 74);
		}

		TEST_METHOD(SubNinetyTwoMinusThirtyFourDoesNotEqualFiftyFive)
		{
			int answer = CalculatorProcessor::GetSub(92, 34);
			Assert::AreNotEqual(answer, 55);
		}

		TEST_METHOD(MultTwentyTimesSixEqualsOneHunTwenty)
		{
			int answer = CalculatorProcessor::GetMult(20, 6);
			Assert::AreEqual(answer, 120);
		}

		TEST_METHOD(DivThirtyDividedBySixDoesNotEqualSix)
		{
			int answer = CalculatorProcessor::GetDiv(30, 6);
			Assert::AreNotEqual(answer, 6);
		}

		TEST_METHOD(HexdecimalOfEightHundredSixtySix)
		{
			CalculatorProcessor process;
			std::string num = "";
			process.SetBaseNumber(866);
			num = process.GetHexdecimal();
			std::string result = "0x6C";
			Assert::AreNotEqual(result, num);
		}

		TEST_METHOD(HexdecimalOfOneThousandThirtySix)
		{
			CalculatorProcessor process;
			std::string num = "";
			process.SetBaseNumber(1036);
			num = process.GetHexdecimal();
			std::string result = "0x40C";
			Assert::AreEqual(result, num);
		}

		TEST_METHOD(BinaryOfEightHundredSixtySix)
		{
			CalculatorProcessor process;
			std::string num = "";
			process.SetBaseNumber(866);
			num = process.GetBinary();
			std::string result = "00000000000000000000001101100010";
			Assert::AreEqual(result, num);
		}

		TEST_METHOD(BinaryOfOneThousandThirtySix)
		{
			CalculatorProcessor process;
			std::string num = "";
			process.SetBaseNumber(1036);
			num = process.GetBinary();
			std::string result = "00000000000000000000101101000110";
			Assert::AreNotEqual(result, num);
		}
	};
}
