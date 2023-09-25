#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <iostream>
#include "about.h"

class MyWindow : public Gtk::Window {
	public :
		MyWindow();
		~MyWindow() override;

	protected :
		Gtk::Box m_box1;
		Gtk::Box buttons1;
		Gtk::Box buttons2;
		Gtk::Button m_button1, m_button2, m_button3, m_button4,
			m_button5, m_button6, m_button7, m_button8, m_button9, m_button10;
		Gtk::Label title;
		Gtk::Label body;
		RenImage m_area;
    Gtk::Window *about_window;
};

