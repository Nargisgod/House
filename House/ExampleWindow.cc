/*
 * ExampleWindow.cc
 *
 *  Created on: 16 нояб. 2020 г.
 *      Author: unyuu
 */

#include "ExampleWindow.h"

#include <cmath>

static constexpr double Pi = acos(-1.);


ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  _crate_texture("crate_tex.png")
{

}

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	// Задаём цвет очистки буфера цвета
	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION); // Далее используем матрицу проекции
	gluPerspective(45.,
			double(width()) / double(height()),
			0.1, 60.0);
	glMatrixMode(GL_MODELVIEW); // Далее используем матрицу модели-вида
}

void ExampleWindow::render()
{
	// Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); // замена текущей матрицы на единичную

	gluLookAt(
			0., 20., sin(360)*12,
			0.0, 0.0, 0.0,
			0., 0., 1.);

	//glRotated(_angle, 0., 0., 1.);
	glEnable(GL_TEXTURE_2D);
	_crate_texture.bind();

	glPushMatrix();
	        glRotated(90., 0., 0., 1.);
	        glTranslated(-6.,0.,0.);
	            _cube.draw();
	    glPopMatrix();

	glPushMatrix();
		    glRotated(90., 0., 0., 1.);
		    glTranslated(-6.,-3.,0.);
		       _cube.draw();
	    glPopMatrix();
	glPushMatrix();
	        glRotated(90., 0., 0., 1.);
	        glTranslated(-6.,3.,0.);
	            _cube.draw();
	    glPopMatrix();

	glPushMatrix();
		    glRotated(0., 0., 0., 1.);
		    glTranslated(-6.,-4.,0.);
		        _cube.draw();
		glPopMatrix();

	glPushMatrix();
			glRotated(180., 0., 0., 1.);
			glTranslated(-6.,4.,0.);
			   _cube.draw();
	    glPopMatrix();

	   _ground.draw();
	//_cube.draw();
}

void ExampleWindow::do_logic()
{
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

	//_camera_z = sin(_angle / 180. * Pi) * 10.;
}
