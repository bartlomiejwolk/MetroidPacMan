#pragma once

#include "cocos2d.h"

namespace Utils 
{
	// TODO replace Point with Vec2
	/**
	 * Converts viewport point to OpenGL point.
	 *
	 * @param width Distance from (0, 0) bottom-left along horizontal axis represented as value from 0 to 1.
	 * @param height Distance from (0, 0) bottom-left along vertical axis represented as value from 0 to 1.
	 * @return Screen point as OpenGL point.
	 */
	static cocos2d::Point GetScreenPoint(float width, float height)
	{
		cocos2d::Size openGLVisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
		cocos2d::Point result = cocos2d::Point(openGLVisibleSize.width * width, openGLVisibleSize.height * height);

		return result;
	}

	// TODO change to uppercase
	// Print useful error message instead of segfaulting when files are not there.
	static void ProblemLoading(const char* filename)
	{
		printf("Error while loading: %s\n", filename);
		printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
	}

};