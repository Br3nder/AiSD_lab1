﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1){
			List s;
			Assert::IsTrue(1 == 1);
		}

		TEST_METHOD(TestMethod2){

			Assert::IsTrue(1 == 2);
		}
	};
}
