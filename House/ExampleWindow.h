/*
 * ExampleWindow.h
 *
 *  Created on: 16 но€б. 2020 г.
 *      Author: unyuu
 */
#pragma once
#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "SimpleModel.h"
#include "Ground.h"
#include "Texture.h"

class ExampleWindow: public Window
{
protected:
	double _angle { 0. };
	double _camera_z { 0. };

	SimpleModel _cube = SimpleModel::create_cube();
	Texture _crate_texture;
	Ground _ground = Ground::create_ground();

public:
	ExampleWindow(	int width = DEFAULT_WIDTH,
					int height = DEFAULT_HEIGHT	);
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* EXAMPLEWINDOW_H_ */
