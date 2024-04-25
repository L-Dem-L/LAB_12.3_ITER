#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.3_ITER/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCountOddElements)
		{
			// Arrange
			int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int size = sizeof(values) / sizeof(values[0]);
			Node* head = createList(values, size);

			// Act
			int oddCount = countOddElements(head);

			// Assert
			Assert::AreEqual(5, oddCount); // Очікуємо, що у списку є 5 непарних елементів

			// Cleanup
			deleteList(head);
		}
	};
}
