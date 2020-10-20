#include "pch.h"
#include "CppUnitTest.h"
#include "../3semA2/Alg.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My3semA2test
{
	TEST_CLASS(Sorted)
	{
	public:
		int n = 10;
		int* arr = new int[n];
		TEST_METHOD_INITIALIZE(setup)
		{
			for (int i = 0; i < n; i++) arr[i] = i;
		}
		TEST_METHOD(IsSorted)
		{
			Assert::IsTrue(isSorted(arr, n));
		}
		TEST_METHOD(Search)
		{
			Assert::AreEqual(BinarySearch(arr, n, 3), 3);
		}
		TEST_METHOD(Search_beg)
		{
			Assert::AreEqual(BinarySearch(arr, n, 0), 0);
		}
		TEST_METHOD(Search_end)
		{
			Assert::AreEqual(BinarySearch(arr, n, 9), 9);
		}
		TEST_METHOD(Search_none)
		{
			Assert::AreEqual(BinarySearch(arr, n, 15), -1);
		}
	};
	TEST_CLASS(NotSorted) 
	{
	public:
		int n = 10;
		int* arr = new int[n];
		TEST_METHOD_INITIALIZE(setup)
		{
			for (int i = 0; i < n; i++) arr[i] = rand();
		}
		TEST_METHOD(bubbleSort)
		{
			BubbleSort(arr, n);
			Assert::IsTrue(isSorted(arr, n));
		}
		TEST_METHOD(quickSort)
		{
			QuickSort(arr, 0, n - 1);
			Assert::IsTrue(isSorted(arr, n));
		}
		TEST_METHOD(bogoSort) {
			BogoSort(arr, n);
			Assert::IsTrue(isSorted(arr, n));
		}
		TEST_METHOD(countSort)
		{
			char* a = new char[n];
			for (int i = 0; i < n; i++) a[i] = (rand() % 95) + 32;
			CountingSort(a, n);
			for (int i = 0; i < n - 1; i++) Assert::IsTrue((a[i] <= a[i + 1]));
		}
	};
}
