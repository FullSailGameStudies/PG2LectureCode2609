#pragma once

#include <vector>
#include <chrono>
#include <functional>

namespace results {

	void WriteResults(const char* _codeFile, const char* _resultsFile);

	void WriteResults(std::vector<const char*> _codeFiles, const char* _resultsFile);

	void ReadResults(const char* _resultsFile, std::chrono::seconds _ignore = std::chrono::seconds(0));

	void TestToggle(char _choice, int& _test);

	void RunLabTest(std::function<void()> _battery, const char* _resultsFile, int _toggle);
}