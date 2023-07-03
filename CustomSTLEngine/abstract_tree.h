#pragma once

#include <iostream>

template<typename T>
class TreeNode {
public:
	virtual void symmetric_print(const T* node) = 0;
};
